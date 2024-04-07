#include "../include/Scene.hpp"

void SceneManager::LoadScene(std::string name, Scene *s)
{
    Scenes[name] = s;
}

void SceneManager::ChangeScene(std::string name)
{
    Scenes[name]->Update();
}

void SceneManager::Clear()
{
    for (auto iter : Scenes)
        delete iter.second;
}

void SceneManager::Loop()
{
}

std::map<std::string, Scene *> SceneManager::Scenes;