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
 +-------------------------------------------------------------------------------+
 | db   dD db    db db   db  .d88b.  d888888b d88888b  .d8b.  d888888b d8888b.	 | 
 | 88 ,8P' 88    88 88   88 .8P  Y8. `~~88~~' 88'     d8' `8b `~~88~~' 88  `8D	 | 
 | 88,8P   88    88 88ooo88 88    88    88    88ooooo 88ooo88    88    88oodD'	 | 
 | 88`8b   88    88 88~~~88 88    88    88    88~~~~~ 88~~~88    88    88~~~	 | 
 | 88 `88. 88b  d88 88   88 `8b  d8'    88    88.     88   88    88    88	 | 
 | YP   YD ~Y8888P' YP   YP  `Y88P'     YP    Y88888P YP   YP    YP    88	 | 
 +-------------------------------------------------------------------------------+)"
              << std::endl;
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
    cbi.wAttributes = Colors::WHITE * 16 + Colors::LIGHTGREEN;
    SetConsoleScreenBufferInfoEx(console, &cbi);

    COORD new_size =
        {
            short(info.srWindow.Right - info.srWindow.Left + 1),
            short(info.srWindow.Bottom - info.srWindow.Top + 1)};
    SetConsoleScreenBufferSize(console, new_size);

    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    parser = new CinemaContainer("assets/cinema.csv");
    accCont = new AccountContainer("assets/accounts.csv");

    menuScene = new MenuScene("MainScene", []()
                              { PrintNameOfProgram(); });
    adminScene = new MenuScene("AdminScene", []()
                               { PrintNameOfProgram(); });
    userScene = new MenuScene("UserScene", []()
                              { PrintNameOfProgram(); });
    sortScene = new MenuScene("SortScene", [this]()
                              { parser->ReadFromFile(); });

    SceneManager::LoadScene("MainScene", menuScene);
    SceneManager::LoadScene("AdminScene", adminScene);
    SceneManager::LoadScene("UserScene", userScene);
    SceneManager::LoadScene("SortScene", sortScene);

    // SceneManager::LoadScene("AccountsScene", accScene);
}

void Application::CheckAccout()
{
    system("cls");
    std::cout << "������ ����� � ��஫� ��� ⮣�, �⮡� ������� ����� �����������: " << std::endl;
    std::string pass, passLogin;

    std::cout << "������ �����: " << std::endl;
    std::cout << ">>> ";
    cin >> passLogin;

    std::cout << "������ ��஫�: " << std::endl;
    std::cout << ">>> ";
    cin >> pass;

    if (!accCont->Authenticate(passLogin, pass))
    {
        cout << "������ ���짮��⥫� �� �������!!!" << endl;
        Sleep(300);
        CheckAccout();
    }
    else
    {
        isAccessGranted = true;
    }
}

void Application::Registration()
{
    system("cls");
    std::cout << "���������: " << std::endl;
    std::string pass, passLogin;

    std::cout << "������ �����: " << std::endl;
    std::cout << ">>> ";
    cin >> passLogin;

    std::cout << "������ ��஫�: " << std::endl;
    std::cout << ">>> ";
    cin >> pass;

    if (!accCont->CheckLogin(passLogin))
    {
        accCont->AddElement(new Account(accCont->GetSize(), passLogin, pass, false));
        isAccessGranted = true;
    }
    else
    {
        std::cout << "��� ������ 㦥 �������, ��������, ������ ��� ࠧ ����� � ��஫�!!!" << std::endl;
        Sleep(500);
        Registration();
    }
}

void Application::AddAllScenesElements()
{
    menuScene->AddScene(
        new MenuElem("���������", [this]()
                     { 
                        if(!isAccessGranted) this->Registration();
                        if(isAccessGranted) SceneManager::ChangeScene("AdminScene"); }));
    menuScene->AddScene(
        new MenuElem("���ਧ���", [this]()
                     { 
                        if(!isAccessGranted) this->CheckAccout();
                        if(isAccessGranted) SceneManager::ChangeScene("AdminScene"); }));

    menuScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));
    adminScene->AddScene(
        new MenuElem("�������� ᯨ᮪ 䨫쬮�", [this]()
                     { SceneManager::ChangeScene("SortScene"); }));

    sortScene->AddScene(
        new MenuElem("�� id", [this]()
                     { 
                            // parser->SortById(false);
    parser->SaveToFile(); }));
    sortScene->AddScene(
        new MenuElem("�� �������� 䨫쬠", [this]() { // parser->SortByTitle(false);
            parser->SaveToFile();
        }));

    sortScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));

    adminScene->AddScene(
        new MenuElem("�������� 䨫� � �ப��", [this]()
                     { parser->AddFunc(); }));
    adminScene->AddScene(
        new MenuElem("������� 䨫� �� �ப��", [this]()
                     { parser->DeleteFunc(); }));
    adminScene->AddScene(
        new MenuElem("�������� 䨫� � �ப��", [this]() {parser->ChangeFunc();}));

    adminScene->AddScene(
        new MenuElem("��室 �� �ணࠬ��", []()
                     { std::cout << "Please stand by.... " << std::endl;
                         exit(EXIT_SUCCESS); }));

    // accScene->AddScene(
    //     new MenuElem("�������� ������ � ���� ������", [this]() {}));
    // accScene->AddScene(
    //     new MenuElem("������� ������ �� ���� ������", [this]() {}));
    // accScene->AddScene(
    //     new MenuElem("�������� ���������樮��� �ࠢ� ��� ������", [this]() {}));
    // accScene->AddScene(
    //     new MenuElem("��室 �� �ணࠬ��", []()
    //                  { std::cout << "Please stand by.... " << std::endl;
    //                      exit(EXIT_SUCCESS); }));
}
void Application::Update()
{
    AddAllScenesElements();
    SceneManager::ChangeScene("MainScene");
}
