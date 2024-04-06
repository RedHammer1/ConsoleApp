#include "../include/Csv_Parser.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <array>

using namespace std;

CSV_Parser::CSV_Parser(std::string filename)
{
    this->filename = filename;

    ifstream file(filename);
    if (!file)
    {
        throw runtime_error("Файл с данными не найден");
    }
    
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string title, director, id;
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, director);
        int _id = stoi(id);

        Cinema *cinema = new Cinema(_id, title, director);
        cinemaList.push_back(cinema);
    }
    file.close();
}

void CSV_Parser::SaveToFile()
{
    try
    {
        ofstream file(filename);
        if (!file)
        {
            throw runtime_error("Ошибка создания файла");
        }
        else
        {
            for (int i = 0; i < cinemaList.size(); i++)
            {
                Cinema *cinema = cinemaList[i];
                file << cinema->GetId() << ";"
                     << cinema->GetTitle() << ";"
                     << cinema->GetDirector() << std::endl;
            }
        }

        file.close();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
    }
    cinemaList.clear();
}

void CSV_Parser::ReadFromFile()
{
    for (int i = 0; i < cinemaList.size(); i++)
    {
        Cinema *cinema = cinemaList[i];
        std::cout << "ID: " << cinema->GetId() << "; "
                                                  "Название Фильма: "
                  << cinema->GetTitle() << "; "
                                           "Режиссер: "
                  << cinema->GetDirector() << std::endl;
    }
}

void CSV_Parser::AddCinema()
{
    lastID = cinemaList.size() + 1;

    string title, director;
    cout << "Введите название фильма: ";
    getline(cin, title);
    cout << "Введите название автора фильма в формате Николас Виндинг Рефн: ";
    getline(cin, director);
    Cinema *cinemaItem = new Cinema(lastID, title, director);
    cinemaList.push_back(cinemaItem);
}
void CSV_Parser::DeleteCinema()
{
    this->ReadFromFile();

    int id;
    cout << "Введите порядковый номер для удаления фильма: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Cinema *_id = cinemaList[id - 1];

    auto it = std::find(cinemaList.begin(), cinemaList.end(), _id);
    if (it != cinemaList.end())
        cinemaList.erase(it);
}

void CSV_Parser::SortById(bool reverse)
{
    sort(
        cinemaList.begin(), cinemaList.end(),
        reverse ? [](Cinema *a, Cinema *b)
            { return a->GetTitle() > b->GetTitle(); }
                : [](Cinema *a, Cinema *b)
            { return a->GetTitle() < b->GetTitle(); });

    this->ReadFromFile();
}

void CSV_Parser::SortByTitle(bool reverse)
{
    this->ReadFromFile();
}