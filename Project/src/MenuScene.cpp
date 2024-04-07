#include "../include/MenuScene.hpp"



void PrintNameOfProgram()
{
     std::cout << R"(
浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�
� db   dD db    db db   db  .d88b.  d888888b d88888b  .d8b.  d888888b d8888b.	� 
� 88 ,8P' 88    88 88   88 .8P  Y8. `~~88~~' 88'     d8' `8b `~~88~~' 88  `8D	� 
� 88,8P   88    88 88ooo88 88    88    88    88ooooo 88ooo88    88    88oodD'	� 
� 88`8b   88    88 88~~~88 88    88    88    88~~~~~ 88~~~88    88    88~~~	� 
� 88 `88. 88b  d88 88   88 `8b  d8'    88    88.     88   88    88    88	� 
� YP   YD ~Y8888P' YP   YP  `Y88P'     YP    Y88888P YP   YP    YP    88	� 
藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�)"
               << '\n';
}



void MenuScene::Destroy()
{
}
void MenuScene::Update()
{
     while ((true))
     {
          system("cls");
          PrintNameOfProgram();
          

          std::cout << "��爬��硅: " << std::endl;
          for (int i = 0; i < scenes.size(); i++)
          {
               scenes[i]->Print(i);
          }

          std::cout << "�襦ム�皀 ��爬��� (q か� �諷���)" << std::endl;
          std::string variant;
          std::cout << ">>> ";
          std::cin >> variant ;

          std::cin.ignore(100, '\n');
          if (variant == "q")
          {
               break;
          }
          int choice = 0;
          try
          {
               choice = std::stoi(variant);
          }
          catch (const std::invalid_argument &)
          {
               std::cout << "�アム�覃 □��!" << std::endl;
               getchar();
               continue;
          }
          if (choice > 0 && choice <= (int)scenes.size())
          {
               scenes[choice - 1]->Update();
          }
          else
          {
               std::cout << "�アム�覃 □��!" << std::endl;
               getchar();
          }
     }
}
