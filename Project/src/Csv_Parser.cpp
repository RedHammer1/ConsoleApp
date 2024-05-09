

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

        ConsoleTable table{"ID", "ФИЛЬМ", "ЖАНР", "ВОЗРАСТНОЙ РЕЙТИНГ", "ГОД ВЫПУСКА", "ЦЕНА"};
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
    ConsoleTable table{"ID", "ФИЛЬМ", "ЖАНР", "ВОЗРАСТНОЙ РЕЙТИНГ", "ГОД ВЫПУСКА", "ЦЕНА"};
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
    cout << "Для добавления фильма в прокат, пожайлуйста, заполните данные о киноленте: " << endl;

    string title, genre, ageRating;
    unsigned int price, year;
    cout << "Введите название фильма: ";
    try
    {
        getline(cin, title);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите жанр фильма: ";
    try
    {
        getline(cin, genre);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите возрастной рейтинг: ";
    try
    {
        getline(cin, ageRating);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите год выпуска фильма: ";
    try
    {
        cin >> year;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    cout << "Введите цену фильма: ";
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

    std::cout << "Хотите ли вы добавить ещё один фильм? (д или y(лат) - да, н или n - нет)" << std::endl;
    std::cin >> variant;

    std::cin.ignore(100, '\n');

    if (variant == "д" || variant == "y")
    {
        AddElement();
    }
    else if (variant == "н" || variant == "n")
    {
        Sleep(100);
    }
    else
    {
        std::cout << "Неверный ввод!" << std::endl;
    }
}
template <>
void CSV_Parser<Cinema>::DeleteElement()
{
    system("cls");
    this->ReadFromFile();

    int id;
    cout << "Введить номер фильма для последующего удаления: " << endl;
    std::cout << ">>> ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (elementList.size() < id || id <= 0)
    {
        std::cout << "В списке нет фильма номером" << id << std::endl;
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

        std::cout << "Хотите ли вы удалить ещё один фильм? (д или y(лат) - да, н или n - нет)" << std::endl;
        std::cin >> variant;

        std::cin.ignore(100, '\n');

        if (variant == "д" || variant == "y")
        {
            DeleteElement();
        }
        else if (variant == "н" || variant == "n")
        {
            Sleep(100);
        }
        else
        {
            std::cout << "Неверный ввод!" << std::endl;
            Sleep(100);
        }
    }
}

