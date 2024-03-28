#include "../include/MenuElem.hpp"

void MenuElem::Update()
{
    system("cls");
    (action)();
}
void MenuElem::Print(int i)
{
    std::cout << i + 1 << ". " << name << std::endl;
}
void MenuElem::Destroy()
{
}