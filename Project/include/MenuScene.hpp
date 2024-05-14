#include "MenuElem.hpp"
#include <vector>
class Scene;
class MenuScene : public Scene
{
public:
     MenuScene(std::string name, std::function<void()> action) : Scene(name), action(action) {}
     void Update() override;
     void Destroy() override;

     void AddScene(MenuElem *scene)
     {
          scenes.push_back(scene);
     }

private:
     std::vector<MenuElem *> scenes;
     std::function<void()> action;
};
