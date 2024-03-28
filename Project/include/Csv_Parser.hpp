#include "Cinema.hpp"
#include <vector>

class Cinema;
class CSV_Parser
{
public:
    CSV_Parser(std::string filename);

    void SaveToFile();
    void ReadFromFile();

    void AddCinema();
    void DeleteCinema();

    void SortById(bool reverse);
    void SortByTitle(bool reverse);

    ~CSV_Parser();

private:
    std::vector<Cinema *> cinemaList;
    std::string filename;
    int lastID = 0;
};