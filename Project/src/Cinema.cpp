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