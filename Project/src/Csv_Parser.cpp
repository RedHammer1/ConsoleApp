

#include "../include/Csv_Parser.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>

#include <algorithm>
#include <array>

#include "../include/TextTable.hpp"

using namespace std;


template <>
void CSV_Parser<Cinema>::SaveToFile()
{
    try
    {
        ofstream file(filename);

        ConsoleTable table{"ID", "�����", "����", "���������� �������", "��� �������", "����"};
        table.setPadding(5);

        for (int i = 0; i < elementList.size(); i++)
        {
            Cinema *cinema = elementList[i];
            cinema->Print(table);
            cinema->WriteToCSV(file);
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
template <>
void CSV_Parser<Cinema>::ReadFromFile()
{
    elementList.clear();

    ReadData();
    ConsoleTable table{"ID", "�����", "����", "���������� �������", "��� �������", "����"};
    table.setPadding(5);

    for (int i = 0; i < elementList.size(); i++)
    {
        Cinema *cinema = elementList[i];
        cinema->Print(table);
    }
    std::cout << table;
}
template <>
void CSV_Parser<Cinema>::AddElement()
{
    system("cls");
    lastID = elementList.size() + 1;
    cout << "��� ���������� 䨫쬠 � �ப��, ���������, �������� ����� � ��������: " << endl;

    string title, genre, ageRating;
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

    cout << "������ ���� 䨫쬠: ";
    try
    {
        getline(cin, genre);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "������ �����⭮� ३⨭�: ";
    try
    {
        getline(cin, ageRating);
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

    Cinema *cinemaItem = new Cinema(lastID, title, genre, ageRating, price, year);
    elementList.push_back(cinemaItem);
    SaveToFile();

    std::string variant;

    std::cout << "���� �� �� �������� ��� ���� 䨫�? (� ��� y(���) - ��, � ��� n - ���)" << std::endl;
    std::cin >> variant;

    std::cin.ignore(100, '\n');

    if (variant == "�" || variant == "y")
    {
        AddElement();
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
template <>
void CSV_Parser<Cinema>::DeleteElement()
{
    system("cls");
    this->ReadFromFile();

    int id;
    cout << "������� ����� 䨫쬠 ��� ��᫥���饣� 㤠�����: " << endl;
    std::cout << ">>> ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (elementList.size() < id || id <= 0)
    {
        std::cout << "� ᯨ᪥ ��� 䨫쬠 ����஬" << id << std::endl;
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
        std::string variant;

        std::cout << "���� �� �� 㤠���� ��� ���� 䨫�? (� ��� y(���) - ��, � ��� n - ���)" << std::endl;
        std::cin >> variant;

        std::cin.ignore(100, '\n');

        if (variant == "�" || variant == "y")
        {
            DeleteElement();
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

