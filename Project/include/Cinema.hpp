#include <iostream>
#include <string>

class Cinema
{
public:
    Cinema(unsigned int id, std::string title, std::string director) : id(id), title(title), director(director) {}
    
    unsigned int GetId();
    void SetId(unsigned int id);
    std::string GetTitle();
    void SetTitle(std::string title);
    std::string GetDirector();
    void SetDirector(std::string director);

private:
    std::string title;
    std::string director;
    unsigned int id;
};