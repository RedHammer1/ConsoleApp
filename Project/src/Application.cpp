#include "../include/Application.hpp"

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

    SetConsoleTextAttribute(console, Colors::WHITE * 16 + Colors::GREEN);
    SetConsoleOutputCP(65001);

    menuScene = new MenuScene("MainScene");
    adminScene = new MenuScene("AdminScene");
    authorizeScene = new MenuScene("AuthorizeScene");

    SceneManager::LoadScene("MainScene", menuScene);
    SceneManager::LoadScene("AdminScene", adminScene);
    SceneManager::LoadScene("AuthorizeScene", adminScene);
}

void Application::AddAllScenesElements()
{
    menuScene->AddScene(
        new MenuElem("Администрационное меню", []()
                     { SceneManager::ChangeScene("AdminScene"); }));
    menuScene->AddScene(
        new MenuElem("Выход из программы", []()
                     { std::cout << "Выходим из программы.... " << std::endl;
                         exit(EXIT_SUCCESS); }));
    menuScene->AddScene(
        new MenuElem("Показать список фильмов", []()
                     { std::cout << "Показываем список фильмов.... " << std::endl;
                        getchar(); }));

    adminScene->AddScene(
        new MenuElem("Добавить фильм в прокат", []()
                     { std::cout << "Добавляется фильмец..." << std::endl; 
                     getchar(); })

    );
    adminScene->AddScene(
        new MenuElem("Удалить фильм из проката", []()
                     { std::cout << "Удаляется фильмец..." << std::endl; 
                     getchar(); }));
    adminScene->AddScene(
        new MenuElem("Выход из программы", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));
}
void Application::Update()
{
    AddAllScenesElements();
    SceneManager::ChangeScene("MainScene");

    SetConsoleTextAttribute(console, 0);
}
