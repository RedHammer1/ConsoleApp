#include <iostream>
#include <string>

class Cinema
{
public:
    Cinema(unsigned int id, std::string title,
           std::string genre, unsigned int price, unsigned int year)
        : id(id), title(title), genre(genre),
          price(price), year(year) {}

    unsigned int GetId();
    void SetId(unsigned int id);

    std::string GetTitle();
    void SetTitle(std::string title);

    std::string GetGenre();
    void SetGenre(std::string genre);

    unsigned int GetPrice();
    void SetPrice(unsigned int price);

    unsigned int GetYear();
    void SetYear(unsigned int year);

private:
    unsigned int id;
    std::string title;
    std::string genre;
    unsigned int price;
    unsigned int year;
};