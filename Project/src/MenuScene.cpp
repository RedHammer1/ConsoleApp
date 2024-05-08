#include "../include/MenuScene.hpp"


void MenuScene::Destroy()
{
}
void MenuScene::Update()
{
     
     while ((true))
     {
          system("cls");
          this->action();
          
          std::cout << "��ਠ���: " << std::endl;
          for (int i = 0; i < scenes.size(); i++)
          {
               scenes[i]->Print(i);
          }

          std::cout << "�롥�� ��ਠ�� (q - �����)" << std::endl;
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
               std::cout << "������ ����!" << std::endl;
               continue;
          }
          if (choice > 0 && choice <= (int)scenes.size())
          {
               scenes[choice - 1]->Update();
          }
          else
          {
               std::cout << "������ ����!" << std::endl;
               Sleep(100);
          }
     }
}
