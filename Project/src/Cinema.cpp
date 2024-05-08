#include "../include/Cinema.hpp"

std::string Cinema::GetAgeRating()
{
    return ageRating;
}

void Cinema::SetAgeRating(std::string ageRating)
{
    this->ageRating = ageRating;
}

std::string Cinema::GetTitle()
{
    return title;
}

void Cinema::SetTitle(std::string title)
{
    this->title = title;
}

std::string Cinema::GetGenre()
{
    return genre;
}

void Cinema::SetGenre(std::string genre)
{
    this->genre = genre;
}

unsigned int Cinema::GetPrice()
{
    return price;
}

void Cinema::SetPrice(unsigned int price)
{
    this->price = price;
}

unsigned int Cinema::GetYear()
{
    return year;
}

void Cinema::SetYear(unsigned int year)
{
    this->year = year;
}