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
    string id, title, genre, ageRating, price, year;
    getline(file, id, ';');
    getline(file, title, ';');
    getline(file, genre, ';');
    getline(file, ageRating, ';');
    getline(file, year, ';');
    getline(file, price);

    this->SetId(stoi(id));
    this->SetTitle(title);
    this->SetGenre(genre);
    this->SetAgeRating(ageRating);

    this->SetPrice(stoi(price));
    this->SetYear(stoi(year));
}
void Cinema::WriteToCSV(std::ofstream &file)
{
}