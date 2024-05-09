#include "../include/Cinema.hpp"

using namespace std;

string Cinema::GetAgeRating() { return ageRating; }

void Cinema::SetAgeRating(string ageRating) { this->ageRating = ageRating; }

string Cinema::GetTitle() { return title; }

void Cinema::SetTitle(string title) { this->title = title; }

string Cinema::GetGenre() { return genre; }

void Cinema::SetGenre(string genre) { this->genre = genre; }

unsigned int Cinema::GetPrice() { return price; }

void Cinema::SetPrice(unsigned int price) { this->price = price; }

unsigned int Cinema::GetYear() { return year; }

void Cinema::SetYear(unsigned int year) { this->year = year; }

void Cinema::Print(ConsoleTable &table)
{
    table += {std::to_string(GetId()), GetTitle(), GetGenre(), GetAgeRating(),
              std::to_string(GetYear()), std::to_string(GetPrice())};
}
void Cinema::ReadFromCSV(stringstream &file)
{

    string _id, _title, _genre, _ageRating, _price, _year;
    getline(file, _id, ';');
    getline(file, _title, ';');
    getline(file, _genre, ';');
    getline(file, _ageRating, ';');
    getline(file, _year, ';');
    getline(file, _price);

    this->SetId(stoi(_id));
    this->SetTitle(_title);
    this->SetGenre(_genre);
    this->SetAgeRating(_ageRating);

    this->SetPrice(stoi(_price));
    this->SetYear(stoi(_year));
}

void Cinema::WriteToCSV(ofstream &file)
{
    file << GetId() << ";"
         << GetTitle() << ";"
         << GetGenre() << ";"
         << GetAgeRating() << ";"
         << GetYear() << ";"
         << GetPrice() << endl;
}

template <>
void CSV_Parser<Cinema>::SaveToFile()
{
    try
    {
        ConsoleTable table{"ID", "ФИЛЬМ", "ЖАНР", "ВОЗРАСТНОЙ РЕЙТИНГ", "ГОД ВЫПУСКА", "ЦЕНА"};
        _SaveToFile(table);
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        Sleep(100);
    }
}
template <>
void CSV_Parser<Cinema>::ReadFromFile()
{
    ConsoleTable table{"ID", "ФИЛЬМ", "ЖАНР", "ВОЗРАСТНОЙ РЕЙТИНГ", "ГОД ВЫПУСКА", "ЦЕНА"};
    _ReadFromFile(table);
}

/*
template <>
void CSV_Parser<Cinema>::AddElement()
{
    system("cls");
    lastID = elementList.size() + 1;
    std::cout << "Для добавления фильма в прокат, пожайлуйста, заполните данные о киноленте: " << std::endl;

    std::string title, genre, ageRating;
    unsigned int price, year;
    std::cout << "Введите название фильма: ";
    try
    {
        std::getline(std::cin, title);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Введите жанр фильма: ";
    try
    {
        std::getline(std::cin, genre);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Введите возрастной рейтинг: ";
    try
    {
        std::getline(std::cin, ageRating);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Введите год выпуска фильма: ";
    try
    {
        std::cin >> year;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "Введите цену фильма: ";
    try
    {
        std::cin >> price;
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
    std::cout << "Введить номер фильма для последующего удаления: " << std::endl;
    std::cout << ">>> ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
*/