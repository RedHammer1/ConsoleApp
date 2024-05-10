#ifndef PASRSER_HPP
#define PASRSER_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

#include <algorithm>
#include <array>
#include "../include/TextTable.hpp"

template <typename T>
class CSV_Parser
{
public:
    CSV_Parser(std::string filename);

    void SaveToFile();
    void ReadFromFile();

    void AddElement(T *t);
    void DeleteElement(unsigned int id);
    T *GetElementById(unsigned int id);
    unsigned int GetSize();

    // void AddElement();
    // void DeleteElement();

protected:
    std::vector<T *> elementList;
    std::string filename;
    int lastID = 0;

    void ReadData();
    void _SaveToFile(ConsoleTable &table);
    void _ReadFromFile(ConsoleTable &table);
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

bool stob(std::string s);

#endif