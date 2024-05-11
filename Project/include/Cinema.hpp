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

class CinemaContainer : public CSV_Parser<Cinema>
{
public:
    CinemaContainer(std::string filename) : CSV_Parser<Cinema>(filename) {}
    void AddFunc() override;
    void ChangeFunc() override;

    void SaveToFile() override;
    void ReadFromFile() override;
};

/*void CinemaContainer::DeleteCinema()
{
    system("cls");
    this->ReadFromFile();

    int id;
    cout << "???ý??? ????? ?????ÿ ý?? ?????ý?????? ?ýÿ?????: " << endl;
    std::cout << ">>> ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cinemaList.size() < id || id <= 0)
    {
        std::cout << "? ?????? ??? ?????ÿ ???????" << id << std::endl;
        return;
    }

    auto it = std::find(cinemaList.begin(), cinemaList.end(), cinemaList[id - 1]);
    if (it != cinemaList.end())
        cinemaList.erase(it);
    for (int i = 0; i < cinemaList.size(); i++)
    {
        cinemaList[i]->SetId(i + 1);
    }

    SaveToFile();

    if (cinemaList.size() > 0)
    {
        std::string variant;

        std::cout << "?????? ?? ?? ?ýÿ???? ??? ?ý?? ?????? (ý ??? y(?ÿ?) - ýÿ, ? ??? n - ???)" << std::endl;
        std::cin >> variant;

        std::cin.ignore(100, '\n');

        if (variant == "ý" || variant == "y")
        {
            DeleteCinema();
        }
        else if (variant == "?" || variant == "n")
        {
            Sleep(100);
        }
        else
        {
            std::cout << "???????? ???ý!" << std::endl;
            Sleep(100);
        }
    }
}*/

#endif