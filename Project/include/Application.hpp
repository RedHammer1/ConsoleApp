
#include "MenuScene.hpp"

#include <vector>

class Application
{
public:
    Application();
    void Update();

private:
    MenuScene *menuScene;
    MenuScene *adminScene;
    MenuScene *authorizeScene;
    HANDLE console;

    void AddAllScenesElements();
};
