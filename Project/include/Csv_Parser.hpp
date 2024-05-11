#ifndef PASRSER_HPP
#define PASRSER_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <functional>

#include <algorithm>
#include <array>
#include "../include/TextTable.hpp"

#include "../include/Controller.hpp"

template <typename T>
class CSV_Parser
{
public:
    CSV_Parser(std::string filename);

    virtual void SaveToFile() = 0;
    virtual void ReadFromFile() = 0;

    void AddElement(T *t);
    void DeleteElement(unsigned int id);
    T *GetElementById(unsigned int id);
    void SortById(bool reverse);

    unsigned int GetSize();

    virtual void AddFunc() = 0;
    virtual void ChangeFunc() = 0;
    void DeleteFunc();

protected:
    std::vector<T *> elementList;
    std::string filename;
    int lastID = 0;

    void ReadData();
    void _SaveToFile(ConsoleTable &table);
    void _ReadFromFile(ConsoleTable &table);
    int _ChangeFunc();

    void ContinueFunc(std::function<void()> action);
};

template <typename T>
CSV_Parser<T>::CSV_Parser(std::string filename)
{
    this->filename = filename;
    ReadData();
}
template <typename T>
unsigned int CSV_Parser<T>::GetSize()
{
    return elementList.size();
}
template <typename T>
void CSV_Parser<T>::ReadData()
{
    std::ifstream file(filename);

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        T *t = new T();
        t->ReadFromCSV(ss);
        elementList.push_back(t);
    }
    file.close();
}
template <typename T>
void CSV_Parser<T>::_SaveToFile(ConsoleTable &table)
{
    std::ofstream file(filename);

    table.setPadding(5);

    for (int i = 0; i < elementList.size(); i++)
    {
        T *t = elementList[i];
        t->Print(table);
        t->WriteToCSV(file);
    }
    std::cout << table;

    file.close();
}

template <typename T>
void CSV_Parser<T>::_ReadFromFile(ConsoleTable &table)
{
    elementList.clear();
    ReadData();
    table.setPadding(5);

    for (int i = 0; i < elementList.size(); i++)
    {
        T *t = elementList[i];
        t->Print(table);
    }
    std::cout << table;
}

template <typename T>
void CSV_Parser<T>::AddElement(T *t)
{
    elementList.push_back(t);
    SaveToFile();
}
template <typename T>
T *CSV_Parser<T>::GetElementById(unsigned int id)
{
    return elementList[id];
}

template <typename T>
void CSV_Parser<T>::DeleteElement(unsigned int id)
{
    if (elementList.size() < id || id <= 0)
    {
        std::cout << "В списке нет элемента с этим номером" << id << std::endl;
        return;
    }
    auto it = std::find(elementList.begin(), elementList.end(), elementList[id - 1]);
    if (it != elementList.end())
        elementList.erase(it);
    for (int i = 0; i < elementList.size(); i++)
    {
        elementList[i]->SetId(i + 1);
    }
}

template <typename T>
void CSV_Parser<T>::DeleteFunc()
{
    system("cls");
    this->ReadFromFile();

    int id;
    std::cout << "Введить номер для последующего удаления элемента из списка: " << std::endl;
    std::cout << ">>> ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (elementList.size() < id || id <= 0)
    {
        std::cout << "В списке нет элемента номером" << id << std::endl;
        return;
    }

    auto it = std::find(elementList.begin(), elementList.end(), elementList[id - 1]);
    if (it != elementList.end())
        elementList.erase(it);
    for (int i = 0; i < elementList.size(); i++)
    {
        elementList[i]->SetId(i + 1);
    }

    SaveToFile();

    if (elementList.size() > 0)
    {
        ContinueFunc([this]()
                     { DeleteFunc(); });
    }
}
template <typename T>
void CSV_Parser<T>::ContinueFunc(std::function<void()> action)
{
    std::string variant;

    std::cout << "Если вы хотите продолжить ввод, то введите д или y(лат) - иначе н или n(лат)!!!" << std::endl;
    std::cin >> variant;

    std::cin.ignore(100, '\n');

    if (variant == "д" || variant == "y")
    {
        action();
    }
    else if (variant == "н?" || variant == "n")
    {
        Sleep(100);
    }
    else
    {
        std::cout << "Вы ввели неверно функцию, возращаем на предыдущую сцену!" << std::endl;
        Sleep(100);
    }
}

template <typename T>
int CSV_Parser<T>::_ChangeFunc()
{
    int id = 0;
    system("cls");
    ReadFromFile();
    std::cout << "Введите в каком элементе списка вы хотите изменить данные: " << std::endl;
    std::cout << ">>> ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (elementList.size() < id || id <= 0)
    {
        std::cout << "В списке нет элемента номером" << id << std::endl;
        return -1;
    }

    return id;
}

template <typename T>
void CSV_Parser<T>::SortById(bool reverse)
{
    sort(
        elementList.begin(), elementList.end(),
        reverse ? [](T *a, T *b)
            { return a->GetId() > b->GetId(); }
                : [](T *a, T *b)
            { return a->GetId() < b->GetId(); });
}



#endif