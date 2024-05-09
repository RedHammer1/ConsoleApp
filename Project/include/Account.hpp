#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Base.hpp"

class Account : public Base
{
public:
    Account(unsigned int id, std::string login,
            std::string password, bool isAdmin)
        : Base(id), login(login),
          password(password), isAdmin(isAdmin) {}

    std::string GetLogin();
    void SetLogin(std::string login);

    std::string GetPassword();
    void SetPassword(std::string password);

    bool GetIsAdmin();
    void SetIsAdmin(bool isAdmin);

private:
    std::string login;
    std::string password;
    bool isAdmin;
};
#endif