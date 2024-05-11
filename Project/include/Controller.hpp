#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Base.hpp"
#include "Csv_Parser.hpp"
using namespace std;

bool stob(std::string s);

class Controller
{
public:
    static std::string GetFRCL_str(bool& error);
    static int GetFRCL_int(bool& error);
    static bool GetFRCL_bool(bool& error);
};

#endif