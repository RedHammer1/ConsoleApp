#ifndef CINEMA_HPP
#define CINEMA_HPP

#include "Base.hpp"
#include "Csv_Parser.hpp"
using namespace std;

class Cinema;

class Cinema : public Base
{
public:
    Cinema(unsigned int id, std::string title,
           std::string genre, std::string ageRating, float price, unsigned int year)
        : Base(id), title(title), genre(genre),
          price(price), year(year), ageRating(ageRating) {}

    Cinema() {}

    std::string GetTitle();
    void SetTitle(std::string title);

    std::string GetGenre();
    void SetGenre(std::string genre);

    std::string GetAgeRating();
    void SetAgeRating(std::string ageRating);

    float GetPrice();
    void SetPrice(float price);

    unsigned int GetYear();
    void SetYear(unsigned int year);

    void Print(ConsoleTable &table) override;
    void ReadFromCSV(std::stringstream &file) override;
    void WriteToCSV(std::ofstream &file) override;
    

private:
    std::string title;
    std::string genre;
    std::string ageRating;
    float price = 0;
    unsigned int year = 0;
};

class CinemaContainer : public CSV_Parser<Cinema>
{
public:
    CinemaContainer(std::string filename) : CSV_Parser<Cinema>(filename) {}
    void AddFunc() override;
    void ChangeFunc() override;

    void SaveToFile() override;
    void ReadFromFile() override;

    void SortByTitle(bool reverse);
    void SortPrice(bool reverse);
    void SortYear(bool reverse);

   
};


#endif