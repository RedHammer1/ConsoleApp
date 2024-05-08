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
        string title, genre, id, year, price;
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, genre, ';');
        getline(ss, year, ';');
        getline(ss, price);
        int _id = stoi(id);

        int _price = stoi(price);
        int _year = stoi(year);

        cinemaList.push_back(new Cinema(_id, title, genre, _year, _price));
    }

    file.close();
}

void CSV_Parser::SaveToFile()
{
    try
    {
        ofstream file(filename);

        ConsoleTable table{"ID", "�����", "�������", "��� �������", "����"};
        table.setPadding(5);

        for (int i = 0; i < cinemaList.size(); i++)
        {
            Cinema *cinema = cinemaList[i];
            table += {std::to_string(cinema->GetId()), cinema->GetTitle(), cinema->GetGenre(), std::to_string(cinema->GetYear()), std::to_string(cinema->GetPrice())};

            file << cinema->GetId() << ";"
                 << cinema->GetTitle() << ";"
                 << cinema->GetGenre() << ";"
                 << cinema->GetYear() << ";"
                 << cinema->GetPrice() << std::endl;
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
    ConsoleTable table{"ID", "�����", "�������", "��� �������", "����"};
    table.setPadding(5);

    for (int i = 0; i < cinemaList.size(); i++)
    {
        Cinema *cinema = cinemaList[i];

        table += {std::to_string(cinema->GetId()), cinema->GetTitle(), cinema->GetGenre(), std::to_string(cinema->GetYear()), std::to_string(cinema->GetPrice())};
    }
    std::cout << table;
}

void CSV_Parser::AddCinema()
{
    system("cls");
    lastID = cinemaList.size() + 1;
    cout << "��� ���������� 䨫쬠 � �ப��, ���������, ������ �������� 䨫쬠 � ��� ०���: " << endl;

    string title, genre;
    unsigned int price, year;
    cout << "������ �������� 䨫쬠: ";
    try
    {
        getline(cin, title);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "������ ��� ०���: ";
    try
    {
        getline(cin, genre);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "������ ��� ���᪠ 䨫쬠: ";
    try
    {
        cin >> year;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    cout << "������ 業� 䨫쬠: ";
    try
    {
        cin >> price;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }


    Cinema *cinemaItem = new Cinema(lastID, title, genre, price, year);
    cinemaList.push_back(cinemaItem);
    SaveToFile();

    std::string variant;

    std::cout << "���� �� �� �������� ��� ���� 䨫�? (� ��� y(���) - ��, � ��� n - ���)" << std::endl;
    std::cin >> variant;

    std::cin.ignore(100, '\n');

    if (variant == "�" || variant == "y")
    {
        AddCinema();
    }
    else if (variant == "�" || variant == "n")
    {
        Sleep(100);
    }
    else
    {
        std::cout << "������ ����!" << std::endl;
    }
}
void CSV_Parser::DeleteCinema()
{
    system("cls");
    this->ReadFromFile();

    int id;
    cout << "������� ����� 䨫쬠 ��� ��᫥���饣� 㤠�����: " << endl;
    std::cout << ">>> ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cinemaList.size() < id || id <= 0)
    {
        std::cout << "� ᯨ᪥ ��� 䨫쬠 ����஬" << id << std::endl;
        return;
    }

    auto it = std::find(cinemaList.begin(), cinemaList.end(), cinemaList[id - 1]);
    if (it != cinemaList.end())
        cinemaList.erase(it);
    for (int i = 0; i < cinemaList.size(); i++)
    {
        cinemaList[i]->SetId(i + 1);
    }

    SaveToFile();

    if (cinemaList.size() > 0)
    {
        std::string variant;

        std::cout << "���� �� �� 㤠���� ��� ���� 䨫�? (� ��� y(���) - ��, � ��� n - ���)" << std::endl;
        std::cin >> variant;

        std::cin.ignore(100, '\n');

        if (variant == "�" || variant == "y")
        {
            DeleteCinema();
        }
        else if (variant == "�" || variant == "n")
        {
            Sleep(100);
        }
        else
        {
            std::cout << "������ ����!" << std::endl;
            Sleep(100);
        }
    }
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