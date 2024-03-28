#include "../include/MenuScene.hpp"



void PrintNameOfProgram()
{
     std::cout << R"(
╔═══════════════════════════════════════════════════════════════════════════════╗
║ db   dD db    db db   db  .d88b.  d888888b d88888b  .d8b.  d888888b d8888b.	║ 
║ 88 ,8P' 88    88 88   88 .8P  Y8. `~~88~~' 88'     d8' `8b `~~88~~' 88  `8D	║ 
║ 88,8P   88    88 88ooo88 88    88    88    88ooooo 88ooo88    88    88oodD'	║ 
║ 88`8b   88    88 88~~~88 88    88    88    88~~~~~ 88~~~88    88    88~~~	║ 
║ 88 `88. 88b  d88 88   88 `8b  d8'    88    88.     88   88    88    88	║ 
║ YP   YD ~Y8888P' YP   YP  `Y88P'     YP    Y88888P YP   YP    YP    88	║ 
╚═══════════════════════════════════════════════════════════════════════════════╝)"
               << '\n';
}

void MenuScene::Destroy()
{
}
void MenuScene::Update()
{
     while ((true))
     {
          PrintNameOfProgram();

          std::cout << "Варианты: " << std::endl;
          for (int i = 0; i < scenes.size(); i++)
          {
               scenes[i]->Print(i);
          }

          std::cout << "Выберите вариант (q для выхода)" << std::endl;
          std::string variant;
          std::cout << ">>> ";
          std::cin >> variant;

          std::cin.ignore(100, '\n');
          if (variant == "q")
          {
               system("cls");
               std::cout << "Выход из программы\n";
               break;
          }
          int choice = 0;
          try
          {
               choice = std::stoi(variant);
          }
          catch (const std::invalid_argument &)
          {
               std::cout << "Неверный ввод\n";
               getchar();
               continue;
          }
          if (choice > 0 && choice <= (int)scenes.size())
          {
               scenes[choice - 1]->Update();
          }
          else
          {
               std::cout << "Неверный ввод\n";
               getchar();
          }
     }
}
