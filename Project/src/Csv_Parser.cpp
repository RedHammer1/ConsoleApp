#include "../include/Csv_Parser.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

#include <algorithm>
#include <array>

#include "../include/TextTable.hpp"

using namespace std;

CSV_Parser::CSV_Parser(std::string filename)
{
    this->filename = filename;

    ReadFile();
}

void CSV_Parser::ReadFile()
{
    ifstream file(this->filename);

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string title, director, id;
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, director);
        int _id = stoi(id);

        cinemaList.push_back(new Cinema(_id, title, director));
    }

    file.close();
}

void CSV_Parser::SaveToFile()
{
    try
    {
        ofstream file(filename);

        ConsoleTable table{"ID", "ФИЛЬМ", "РЕЖИСЕР"};
        table.setPadding(5);

        for (int i = 0; i < cinemaList.size(); i++)
        {
            Cinema *cinema = cinemaList[i];
            table += {std::to_string(cinema->GetId()), cinema->GetTitle(), cinema->GetDirector()};

            file << cinema->GetId() << ";"
                 << cinema->GetTitle() << ";"
                 << cinema->GetDirector() << std::endl;
        }
        std::cout << table;

        file.close();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        Sleep(100);
    }
}

void CSV_Parser::ReadFromFile()
{
    cinemaList.clear();
    ReadFile();
    ConsoleTable table{"ID", "ФИЛЬМ", "РЕЖИСЕР"};
    table.setPadding(5);

    for (int i = 0; i < cinemaList.size(); i++)
    {
        Cinema *cinema = cinemaList[i];

        table += {std::to_string(cinema->GetId()), cinema->GetTitle(), cinema->GetDirector()};
    }
    std::cout << table;
}

void CSV_Parser::AddCinema()
{
    lastID = cinemaList.size() + 1;
    cout << "Для добавления фильма в прокат, пожайлуйста, введите название фильма и ФИО режисера: " << endl;

    string title, director;
    cout << "Введите название фильма: ";
    try
    {
        getline(cin, title);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите ФИО режисера: ";
    try
    {
        getline(cin, director);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Cinema *cinemaItem = new Cinema(lastID, title, director);
    cinemaList.push_back(cinemaItem);
    SaveToFile();
}
void CSV_Parser::DeleteCinema()
{
    this->ReadFromFile();

    int id;
    cout << "Введить номер фильма для последующего удаления: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Cinema *_id = cinemaList[id - 1];

    auto it = std::find(cinemaList.begin(), cinemaList.end(), _id);
    if (it != cinemaList.end())
        cinemaList.erase(it);
    for (int i = 0; i < cinemaList.size(); i++)
    {
        cinemaList[i]->SetId(i + 1);
    }

    SaveToFile();
}

void CSV_Parser::SortById(bool reverse)
{
    sort(
        cinemaList.begin(), cinemaList.end(),
        reverse ? [](Cinema *a, Cinema *b)
            { return a->GetId() > b->GetId(); }
                : [](Cinema *a, Cinema *b)
            { return a->GetId() < b->GetId(); });
}

void CSV_Parser::SortByTitle(bool reverse)
{
    sort(
        cinemaList.begin(), cinemaList.end(),
        reverse ? [](Cinema *a, Cinema *b)
            { return a->GetTitle() > b->GetTitle(); }
                : [](Cinema *a, Cinema *b)
            { return a->GetTitle() < b->GetTitle(); });
}