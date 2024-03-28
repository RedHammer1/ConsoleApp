#include "../include/Cinema.hpp"

unsigned int Cinema::GetId()
{
    return id;
}

void Cinema::SetId(unsigned int id)
{
    this->id = id;
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

void Cinema::SetDirector(std::string director)
{
    this->director = director;
}