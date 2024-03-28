#include "Scene.hpp"
#include <iostream>
#include <string.h>
#include <functional>
class Scene;
class MenuElem : public Scene
{
public:
    MenuElem(const std::string &title, std::function<void()> action) : Scene(title), action(action) {}
    void Update() override;
    void Destroy() override;

    void Print(int i);

    ~MenuElem() {}

private:
    std::function<void()> action;
};

