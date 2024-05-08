#include "../include/Account.hpp"

std::string Account::GetLogin()
{
    return login;
}

void Account::SetLogin(std::string login)
{
    this->login = login;
}

std::string Account::GetPassword()
{
    return password;
}

void Account::SetPassword(std::string password)
{
    this->password = password;
}

bool Account::GetIsAdmin()
{
    return isAdmin;
}

void Account::SetIsAdmin(bool isAdmin)
{
    this->isAdmin = isAdmin;
}