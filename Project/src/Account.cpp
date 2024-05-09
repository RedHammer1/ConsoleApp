#include "../include/Account.hpp"
using namespace std;

std::string Account::GetLogin() { return login; }

void Account::SetLogin(std::string login) { this->login = login; }

std::string Account::GetPassword() { return password; }

void Account::SetPassword(std::string password) { this->password = password; }

bool Account::GetIsAdmin() { return isAdmin; }

void Account::SetIsAdmin(bool isAdmin) { this->isAdmin = isAdmin; }

void Account::Print(ConsoleTable &table)
{
    table += {std::to_string(GetId()), GetLogin(),
              GetPassword(), std::to_string(GetIsAdmin())};
}

bool stob(std::string s)
{
    auto result = false;

    std::istringstream is(s);
    is >> result;

    if (is.fail())
    {
        is.clear();
        is >> std::boolalpha >> result;
    }

    if (is.fail())
    {
        throw std::invalid_argument(s.append(" is not convertable to bool"));
    }

    return result;
}

void Account::ReadFromCSV(stringstream &file)
{

    string _id, _login, _password, _isAdmin;
    getline(file, _id, ';');
    getline(file, _login, ';');
    getline(file, _password, ';');
    getline(file, _isAdmin);

    this->SetId(stoi(_id));
    this->SetLogin(_login);
    this->SetPassword(_password);
    this->SetIsAdmin(stob(_isAdmin));
}

void Account::WriteToCSV(ofstream &file)
{
    file << GetId() << ";"
         << GetLogin() << ";"
         << GetPassword() << ";"
         << GetIsAdmin() << endl;
}

template <>
void CSV_Parser<Account>::SaveToFile()
{
    try
    {
        ConsoleTable table{"ID", "‹ƒˆ", "€‹œ", "€‚€ €„Œˆˆ‘’€’€"};
        _SaveToFile(table);
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        Sleep(100);
    }
}
template <>
void CSV_Parser<Account>::ReadFromFile()
{
    ConsoleTable table{"ID", "‹ƒˆ", "€‹œ", "€‚€ €„Œˆˆ‘’€’€"};
    _ReadFromFile(table);
}

// template <>
// void CSV_Parser<Account>::DeleteElement()
// {

// }

// template <>
// void CSV_Parser<Account>::AddElement()
// {

// }
