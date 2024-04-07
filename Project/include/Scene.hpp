#include <map>
#include <string>
#include <iostream>

#include <windows.h>

class Scene
{
public:
    Scene(std::string name) : name(name) {}
    virtual void Update() = 0;
    virtual void Destroy() = 0;

protected:
    std::string GetName()
    {
        return name;
    }
    std::string name;
};
class SceneManager
{
public:
    static std::map<std::string, Scene *> Scenes;

    static void LoadScene(std::string name, Scene *s);
    static void ChangeScene(std::string name);
    static void Clear();

private:
    void Loop();
};
