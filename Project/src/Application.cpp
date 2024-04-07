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

void PrintNameOfProgram()
{
    std::cout << R"(
�������������������������������������������������������������������������������ͻ
� db   dD db    db db   db  .d88b.  d888888b d88888b  .d8b.  d888888b d8888b.	� 
� 88 ,8P' 88    88 88   88 .8P  Y8. `~~88~~' 88'     d8' `8b `~~88~~' 88  `8D	� 
� 88,8P   88    88 88ooo88 88    88    88    88ooooo 88ooo88    88    88oodD'	� 
� 88`8b   88    88 88~~~88 88    88    88    88~~~~~ 88~~~88    88    88~~~	� 
� 88 `88. 88b  d88 88   88 `8b  d8'    88    88.     88   88    88    88	� 
� YP   YD ~Y8888P' YP   YP  `Y88P'     YP    Y88888P YP   YP    YP    88	� 
�������������������������������������������������������������������������������ͼ)"
              << '\n';
}

Application::Application()
{

    console = GetStdHandle(
        STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(console, &info);

    CONSOLE_SCREEN_BUFFER_INFOEX cbi;
    cbi.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(console, &cbi);
    cbi.wAttributes = Colors::CYAN * 16 + Colors::LIGHTGREEN;
    SetConsoleScreenBufferInfoEx(console, &cbi);

    COORD new_size =
        {
            short(info.srWindow.Right - info.srWindow.Left + 1),
            short(info.srWindow.Bottom - info.srWindow.Top + 1)};
    SetConsoleScreenBufferSize(console, new_size);

    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    parser = new CSV_Parser("assets/cinema.csv");

    menuScene = new MenuScene("MainScene", []()
                              { PrintNameOfProgram(); });
    adminScene = new MenuScene("AdminScene", []()
                               { PrintNameOfProgram(); });
    sortScene = new MenuScene("SortScene", [this]()
                              { this->ShowCinemaList(); });

    SceneManager::LoadScene("MainScene", menuScene);
    SceneManager::LoadScene("AdminScene", adminScene);
    SceneManager::LoadScene("SortScene", sortScene);
}

void Application::ShowCinemaList()
{
    parser->ReadFromFile();
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
    std::cout << "������ ��஫� ��� ⮣�, �⮡� ������� ����� �����������: ";
    cin >> pass;
    if (pass != password)
    {
        cout << "� ����㯥 �⪠����! ������ ��஫� ��� ࠧ ��� �멤��" << endl;
        getchar();
    }
    isAccessGranted = (pass == password);
}
void Application::AddAllScenesElements()
{
    menuScene->AddScene(
        new MenuElem("���������樮���� ����", [this]()
                     { 
                        if(!isAccessGranted) this->CheckPassword();
                        if(isAccessGranted) SceneManager::ChangeScene("AdminScene"); }));
    menuScene->AddScene(
        new MenuElem("�������� ᯨ᮪ 䨫쬮�", [this]()
                     { SceneManager::ChangeScene("SortScene"); }));
    menuScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));

    sortScene->AddScene(
        new MenuElem("�� id", [this]()
                     { this->SortById(false); }));
    sortScene->AddScene(
        new MenuElem("�� �������� 䨫쬠", [this]()
                     { this->SortByTitle(false); }));
    sortScene->AddScene(
        new MenuElem("�� id ������஢����", [this]()
                     { this->SortById(true); }));
    sortScene->AddScene(
        new MenuElem("�� �������� 䨫쬠 ������஢����", [this]()
                     { this->SortByTitle(true); }));
    sortScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));

    adminScene->AddScene(
        new MenuElem("�������� 䨫� � �ப��", [this]()
                     { this->AddCinema(); }));
    adminScene->AddScene(
        new MenuElem("������� 䨫� �� �ப��", [this]()
                     { this->DeleteCinema(); }));

    adminScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));
}
void Application::Update()
{
    AddAllScenesElements();
    SceneManager::ChangeScene("MainScene");
}
