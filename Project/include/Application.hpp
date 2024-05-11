
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
    MenuScene *accScene;
    MenuScene *sortScene;
    HANDLE console;

    CinemaContainer *parser;
    AccountContainer *accCont;

    void AddAllScenesElements();

    void CheckAccout();
    void Registration();

    bool isAdmin = false;
    bool isAccessGranted = false;
};
