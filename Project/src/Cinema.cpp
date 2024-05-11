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
        ConsoleTable table{"ID", "”ˆ‹œŒ", "†€", "‚Ž‡€‘’Ž‰ …‰’ˆƒ", "ƒŽ„ ‚›“‘Š€", "–…€"};
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
    ConsoleTable table{"ID", "”ˆ‹œŒ", "†€", "‚Ž‡€‘’Ž‰ …‰’ˆƒ", "ƒŽ„ ‚›“‘Š€", "–…€"};
    _ReadFromFile(table);
}

void CinemaContainer::AddFunc()
{
    system("cls");
    bool error = false;
    lastID = elementList.size() + 1;
    cout << "®¦ «ã©áâ , ¤®¡ ¢ìâ¥ ­®¢ãî ª¨­®«¥­âã!!" << endl;

    string title, genre, ageRating;
    int price, year;

    cout << "‚¢¥¤¨â¥ ­ §¢ ­¨¥ ä¨«ì¬ : " << std::endl;
    title = Controller::GetFRCL_str(error);

    if (!error)
    {
        cout << "‚¢¥¤¨â¥ ¦ ­à ä¨«ì¬ : " << std::endl;
        genre = Controller::GetFRCL_str(error);
    }
    if (!error)
    {
        cout << "‚¢¥¤¨â¥ ¢®§à áâ­®© à¥©â¨­£ ä¨«ì¬ : " << std::endl;
        ageRating = Controller::GetFRCL_str(error);
    }
    if (!error)
    {
        cout << "‚¢¥¤¨â¥ æ¥­­¨ª ¤«ï ä¨«ì¬ : " << std::endl;
        price = Controller::GetFRCL_int(error);
    }
    if (!error)
    {
        cout << "‚¢¥¤¨â¥, â® ª®£¤  ¡ë« á®§¤ ­ ä¨«ì¬: " << std::endl;
        year = Controller::GetFRCL_int(error);
    }
    if (!error)
    {
        Cinema *cinemaItem = new Cinema(lastID, title,
                                        genre, ageRating, price, year);

        AddElement(cinemaItem);

        ContinueFunc(
            [this]()
            { AddFunc(); });
    }
}

void CinemaContainer::ChangeFunc()
{
    int id = _ChangeFunc();
    if (id == -1)
    {
        return;
    }
    int cid = 0;
    cout << "‚¢¥¤¨â¥ ª ª¨¥ ¤ ­­ë¥ ¢ë ¡ë å®â¥«¨ ¨§¬¥­¨âì (áçñâ ¨¤ñâ á ­ ¨¬¥­®¢ ­¨ï ä¨«ì¬  (®â 0 ¤® 4)): " << endl;
    cout << ">>> ";
    cin >> cid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    bool error = false;

    if (cid >= 0 && cid <= 4)
    {
        switch (cid)
        {
        case 0:
            elementList[id]->SetTitle(Controller::GetFRCL_str(error));
            break;
        case 1:
            elementList[id]->SetGenre(Controller::GetFRCL_str(error));
            break;
        case 2:
            elementList[id]->SetAgeRating(Controller::GetFRCL_str(error));
            break;
        case 3:
            elementList[id]->SetYear(Controller::GetFRCL_int(error));
            break;
        case 4:
            elementList[id]->SetPrice(Controller::GetFRCL_int(error));
            break;
        default:
            break;
        }
        SaveToFile();
        ContinueFunc(
            [this]()
            { ChangeFunc(); });
    }

    return;
}
