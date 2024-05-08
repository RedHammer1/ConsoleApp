#include "Cinema.hpp"
#include "Account.hpp"

class Cinema;
class Account;

#include <vector>



template <typename T>
class CSV_Parser
{
public:
    CSV_Parser(std::string filename);

    void SaveToFile();
    void ReadFromFile();

    void AddElement();
    void DeleteElement();

    ~CSV_Parser();

private:
    std::vector<T *> elementList;
    std::string filename;
    int lastID = 0;

    void ReadFile();
};

template <typename T>
CSV_Parser<T>::CSV_Parser(std::string filename)
{
    this->filename = filename;
    ReadFile();
}