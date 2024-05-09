#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include "../include/TextTable.hpp"

class Base;
class Base
{
public:
    Base(unsigned int id) : id(id) {}
    Base() : id(0) {}

    inline unsigned int GetId();
    inline void SetId(unsigned int id);

    virtual void Print(ConsoleTable &table) = 0;

    virtual void WriteToCSV(std::ofstream &file) = 0;

private:
    unsigned int id;
};

inline unsigned int Base::GetId()
{
    return id;
}

inline void Base::SetId(unsigned int id)
{
    this->id = id;
}

#endif