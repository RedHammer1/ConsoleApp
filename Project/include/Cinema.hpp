#include <iostream>
#include <string>

class Cinema
{
public:
    Cinema(unsigned int id, unsigned int price, std::string title, std::string director) : id(id), price(price), title(title), director(director) {}
    
    unsigned int GetId();
    void SetId(unsigned int id);
    unsigned int GetPrice();
    void SetPrice(unsigned int price);
    std::string GetTitle();
    void SetTitle(std::string title);
    std::string GetDirector();
    void SetDirector(std::string price);

private:
    std::string title;
    std::string director;
    unsigned int id;
    unsigned int price;
};