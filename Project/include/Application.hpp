
#include "MenuScene.hpp"
#include "Csv_Parser.hpp"

#include <vector>

class Application
{
public:
    Application();
    void Update();

private:
    MenuScene *menuScene;
    MenuScene *adminScene;
    MenuScene *sortScene;
    HANDLE console;
    CSV_Parser<Cinema> *parser;

    void AddAllScenesElements();
    void ShowCinemaList();

    void AddCinema();
    void DeleteCinema();

    void SortById(bool reverse);
    void SortByTitle(bool reverse);

    void CheckAccout();

    std::string password = "admin";
    std::string login = "admin";

    bool isProtected;
    bool isAccessGranted = false;
};
