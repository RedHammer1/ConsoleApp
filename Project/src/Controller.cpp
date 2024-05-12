#include "../include/Controller.hpp"

bool stob(std::string s)
{
    auto result = false;

    std::istringstream is(s);
    is >> result;

    if (is.fail())
    {
        is.clear();
        is >> std::boolalpha >> result;
    }

    if (is.fail())
    {
        throw std::invalid_argument(s.append(" is not convertable to bool"));
    }

    return result;
}

std::string Controller::GetFRCL_str(bool &error)
{
    std::string str;
    std::cout << ">>> ";
    try
    {
        
        getline(cin, str);
        error = false;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        error = true;
    }
    return str;
}

int Controller::GetFRCL_int(bool &error)
{
    int i;
    std::string str;
    std::cout << ">>> ";
    try
    {
        
        getline(cin, str);
        i = stoi(str);
        error = false;
    }
    catch (const std::exception &e)
    {
        error = true;
        std::cerr << e.what() << '\n';
    }
    return i;
}

float Controller::GetFRCL_float(bool &error)
{
    float i;
    std::string str;
    std::cout << ">>> ";
    try
    {
        
        getline(cin, str);
        i = stof(str);
        error = false;
    }
    catch (const std::exception &e)
    {
        error = true;
        std::cerr << e.what() << '\n';
    }
    return i;
}

bool Controller::GetFRCL_bool(bool &error)
{
    bool i;
    std::string str;
    std::cout << ">>> ";
    try
    {
        getline(cin, str);
        i = stob(str);
        error = false;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        error = true;
    }
    return i;
}