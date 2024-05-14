#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Base.hpp"
#include "Csv_Parser.hpp"



class Account;


class Account : public Base
{
public:
    Account(unsigned int id, std::string login,
            std::string password, bool isAdmin)
        : Base(id), login(login),
          password(password), isAdmin(isAdmin) {}

    Account() {}

    std::string GetLogin();
    void SetLogin(std::string login);

    std::string GetPassword();
    void SetPassword(std::string password);

    bool GetIsAdmin();
    void SetIsAdmin(bool isAdmin);

    void Print(ConsoleTable &table) override;
    void ReadFromCSV(std::stringstream &file) override;
    void WriteToCSV(std::ofstream &file) override;

private:
    std::string login;
    std::string password;
    bool isAdmin = false;
};

class AccountContainer : public CSV_Parser<Account>
{
public:
    AccountContainer(std::string filename) : CSV_Parser<Account>(filename)
    {

        if (elementList.size() == 0)
        {
            elementList.push_back(new Account(0, "admin", "admin", true));
        }
    }
    Account *GetAccountForAuth(std::string login, std::string password);
    bool CheckLogin(std::string login);
    bool Authenticate(std::string login, std::string password, bool &isAdmin);
    void AddFunc() override;
    void ChangeFunc() override;
    void SaveToFile() override;
    void ReadFromFile() override;
};

#endif