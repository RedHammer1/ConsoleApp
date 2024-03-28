#include "../include/Cinema.hpp"

unsigned int Cinema::GetId()
{
    return id;
}

void Cinema::SetId(unsigned int id)
{
    this->id = id;
}

unsigned int Cinema::GetPrice()
{
    return price;
}

void Cinema::SetPrice(unsigned int price)
{
    this->price = price;
}

std::string Cinema::GetTitle()
{
    return title;
}

void Cinema::SetTitle(std::string title)
{
    this->title = title;
}

std::string Cinema::GetDirector()
{
    return director;
}

void Cinema::SetDirector(std::string price)
{
    this->director = director;
}