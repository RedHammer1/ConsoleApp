#include <iostream>
#include <string>

class Base
{
public:
    Base(unsigned int id) : id(id) {}

    inline unsigned int GetId();
    inline void SetId(unsigned int id);

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