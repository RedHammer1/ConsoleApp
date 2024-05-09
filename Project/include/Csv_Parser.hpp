#ifndef PASRSER_HPP
#define PASRSER_HPP

#include "Cinema.hpp"
#include "Account.hpp"

class Cinema;
class Account;

#include <vector>
#include <fstream>

template <typename T>
class CSV_Parser
{
public:
    CSV_Parser(std::string filename);

    void SaveToFile();
    void ReadFromFile();

    void AddElement();
    void DeleteElement();

    ~CSV_Parser();

private:
    std::vector<T *> elementList;
    std::string filename;
    int lastID = 0;

    void ReadData();
};

template <typename T>
CSV_Parser<T>::CSV_Parser(std::string filename)
{
    this->filename = filename;
    ReadData();
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
    }
    file.close();
}

#endif