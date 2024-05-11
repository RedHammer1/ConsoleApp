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

void CinemaContainer::SaveToFile()
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

void CinemaContainer::ReadFromFile()
{
    ConsoleTable table{"ID", "ФИЛЬМ", "ЖАНР", "ВОЗРАСТНОЙ РЕЙТИНГ", "ГОД ВЫПУСКА", "ЦЕНА"};
    _ReadFromFile(table);
}

void CinemaContainer::AddFunc()
{
    system("cls");
    lastID = elementList.size() + 1;
    cout << "Пожалуйста, добавьте новую киноленту!!" << endl;

    string title, genre, ageRating, price, year;
    int _price, _year;
    cout << "Введите название фильма: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, title);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите жанр фильма: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, genre);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите возрастной рейтинг фильма: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, ageRating);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите ценник для фильма: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, price);
        _price = stoi(price);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите, то когда был создан фильм: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, year);
        _year = stoi(year);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Cinema *cinemaItem = new Cinema(lastID, title,
                                    genre, ageRating, _price, _year);

    AddElement(cinemaItem);

    ContinueFunc(
        [this]()
        { AddFunc(); });
}

void CinemaContainer::ChangeFunc()
{
    int id = _ChangeFunc();
    if (id == -1)
    {
        return;
    }

    int cid = 0;
    cout << "Введите какие данные вы бы хотели изменить (счёт идёт с наиминования фильма (от 0 до 4)): " << endl;
    cout << ">>> ";
    cin >> cid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cid >= 0 && cid <= 4)
    {

        // switch (cid)
        // {
        // case 0:
        // {
        //     string title;
        //     cout << "Введите название фильма: " << std::endl;
        //     cout << "<<<" << std::endl;
        //     try
        //     {
        //         getline(cin, title);
        //     }
        //     catch (const std::exception &e)
        //     {
        //         std::cerr << e.what() << '\n';
        //     }

        //     elementList[id]
        //         ->SetTitle()
        // }
        // break;

        // default:
        //     break;
        // }
    }

    return;

    //
}
