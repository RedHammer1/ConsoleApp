
#include "MenuScene.hpp"
#include "Cinema.hpp"
#include "Account.hpp"

#include <vector>

class Application
{
public:
    Application();
    void Update();

private:
    MenuScene *menuScene;
    MenuScene *adminScene;
    MenuScene *userScene;
    MenuScene *sortScene;
    HANDLE console;

    CinemaContainer *parser;
    AccountContainer *accCont;

    void AddAllScenesElements();
    void ShowCinemaList();

    void AddCinema();
    void DeleteCinema();

    void SortById(bool reverse);
    void SortByTitle(bool reverse);

    void CheckAccout();
    void Registration();



    bool isProtected;
    bool isAccessGranted = false;
};
