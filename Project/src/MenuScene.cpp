#include "../include/MenuScene.hpp"



void PrintNameOfProgram()
{
     std::cout << R"(
ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ db   dD db    db db   db  .d88b.  d888888b d88888b  .d8b.  d888888b d8888b.	บ 
บ 88 ,8P' 88    88 88   88 .8P  Y8. `~~88~~' 88'     d8' `8b `~~88~~' 88  `8D	บ 
บ 88,8P   88    88 88ooo88 88    88    88    88ooooo 88ooo88    88    88oodD'	บ 
บ 88`8b   88    88 88~~~88 88    88    88    88~~~~~ 88~~~88    88    88~~~	บ 
บ 88 `88. 88b  d88 88   88 `8b  d8'    88    88.     88   88    88    88	บ 
บ YP   YD ~Y8888P' YP   YP  `Y88P'     YP    Y88888P YP   YP    YP    88	บ 
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ)"
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
          

          std::cout << " เจ ญโ๋: " << std::endl;
          for (int i = 0; i < scenes.size(); i++)
          {
               scenes[i]->Print(i);
          }

          std::cout << "๋กฅเจโฅ ข เจ ญโ (q คซ๏ ข๋ๅฎค )" << std::endl;
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
               std::cout << "ฅขฅเญ๋ฉ ขขฎค!" << std::endl;
               getchar();
               continue;
          }
          if (choice > 0 && choice <= (int)scenes.size())
          {
               scenes[choice - 1]->Update();
          }
          else
          {
               std::cout << "ฅขฅเญ๋ฉ ขขฎค!" << std::endl;
               getchar();
          }
     }
}
