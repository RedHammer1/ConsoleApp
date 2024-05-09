#ifndef CINEMA_HPP
#define CINEMA_HPP

#include "Base.hpp"

class Cinema : public Base
{
public:
    Cinema(unsigned int id, std::string title,
           std::string genre, std::string ageRating, unsigned int price, unsigned int year)
        : Base(id), title(title), genre(genre),
          price(price), year(year), ageRating(ageRating) {}

    Cinema() {}

    std::string GetTitle();
    void SetTitle(std::string title);

    std::string GetGenre();
    void SetGenre(std::string genre);

    std::string GetAgeRating();
    void SetAgeRating(std::string ageRating);

    unsigned int GetPrice();
    void SetPrice(unsigned int price);

    unsigned int GetYear();
    void SetYear(unsigned int year);

    void Print(ConsoleTable &table) override;
    void ReadFromCSV(std::stringstream &file) override;
    void WriteToCSV(std::ofstream &file) override;

private:
    std::string title;
    std::string genre;
    std::string ageRating;
    unsigned int price = 0;
    unsigned int year = 0;
};


#endif