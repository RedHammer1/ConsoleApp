#include "../include/Application.hpp"

using namespace std;

enum Colors
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGRAY = 7,
    DARKGRAY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};



Application::Application()
{

    console = GetStdHandle(
        STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(console, &info);

    CONSOLE_SCREEN_BUFFER_INFOEX cbi;
    cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(console, &cbi);
    cbi.wAttributes = Colors::BLACK * 16 + Colors::GREEN;
    SetConsoleScreenBufferInfoEx(console, &cbi);

    COORD new_size =
        {
            short(info.srWindow.Right - info.srWindow.Left + 1),
            short(info.srWindow.Bottom - info.srWindow.Top + 1)};
    SetConsoleScreenBufferSize(console, new_size);

    SetConsoleCP(866);                
    SetConsoleOutputCP(866);

    parser = new CSV_Parser("assets/cinema.csv");

    menuScene = new MenuScene("MainScene");
    adminScene = new MenuScene("AdminScene");
    authorizeScene = new MenuScene("AuthorizeScene");

    SceneManager::LoadScene("MainScene", menuScene);
    SceneManager::LoadScene("AdminScene", adminScene);
    SceneManager::LoadScene("AuthorizeScene", adminScene);
}

void Application::ShowCinemaList()
{
    parser->ReadFromFile();
    getchar();
}
void Application::AddCinema()
{
    parser->AddCinema();
    getchar();
}

void Application::SortById(bool reverse)
{
    parser->SortById(reverse);
    getchar();
}
void Application::SortByTitle(bool reverse)
{
    parser->SortByTitle(reverse);
    getchar();
}

void Application::DeleteCinema()
{
    parser->DeleteCinema();
    getchar();
}

void Application::CheckPassword()
{
    system("cls");
    std::string pass;
    std::cout << "Введите пароль для того, чтобы получить доступ администратора: ";
    cin >> pass;
    if (pass != password)
    {
        cout << "В доступе отказано! Введите пароль ещё раз или выйдите" << endl;
        getchar();
    }
    isAccessGranted = (pass == password);
}

void Application::AddAllScenesElements()
{

    menuScene->AddScene(
        new MenuElem("Администрационное меню", [this]()
                     { 
                        if(isAccessGranted != true) this->CheckPassword();
                        SceneManager::ChangeScene("AdminScene"); }));
    menuScene->AddScene(
        new MenuElem("Показать список фильмов", [this]()
                     { this->ShowCinemaList(); }));
    menuScene->AddScene(
        new MenuElem("Сортировать фильмы по id", [this]()
                     { this->SortById(false); }));
    menuScene->AddScene(
        new MenuElem("Сортировать фильмы по названию фильма", [this]()
                     { this->SortByTitle(false); }));
    menuScene->AddScene(
        new MenuElem("Сортировать фильмы по id инвертированно", [this]()
                     { this->SortById(true); }));
    menuScene->AddScene(
        new MenuElem("Сортировать фильмы по названию фильма инвертированно", [this]()
                     { this->SortByTitle(true); }));

    menuScene->AddScene(
        new MenuElem("Выход из программы", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));

    adminScene->AddScene(
        new MenuElem("Добавить фильм в прокат", [this]()
                     { this->AddCinema(); }));
    adminScene->AddScene(
        new MenuElem("Удалить фильм из проката", [this]()
                     { this->DeleteCinema(); }));

    adminScene->AddScene(
        new MenuElem("Выход из программы", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));
}
void Application::Update()
{
    AddAllScenesElements();
    SceneManager::ChangeScene("MainScene");
}
