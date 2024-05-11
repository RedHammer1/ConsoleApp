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
        ConsoleTable table{"ID", "ЛОГИН", "ПАРОЛЬ", "ПРАВА АДМИНИСТРАТОРА"};
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
    ConsoleTable table{"ID", "ЛОГИН", "ПАРОЛЬ", "ПРАВА АДМИНИСТРАТОРА"};
    _ReadFromFile(table);
}

bool AccountContainer::Authenticate(std::string login, std::string password)
{
    for (auto *acc : elementList)
    {
        if (acc->GetLogin() == login && acc->GetPassword() == password)
        {
            return true;
        }
    }
    return false;
}
bool AccountContainer::CheckLogin(std::string login)
{
    for (auto *acc : elementList)
    {
        if (acc->GetLogin() == login)
        {
            return true;
        }
    }
    return false;
}

bool AccountContainer::CheckIsAdmin()
{
    for (auto *acc : elementList)
    {
        if (acc->GetIsAdmin())
        {
            return true;
        }
    }
    return false;
}

void AccountContainer::SaveToFile()
{
    try
    {
        ConsoleTable table{"ID", "ЛОГИН", "ПАРОЛЬ", "ПРАВА ДОСТУПА"};
        _SaveToFile(table);
    }
    catch (std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
        Sleep(100);
    }
}

void AccountContainer::ReadFromFile()
{
    ConsoleTable table{"ID", "ЛОГИН", "ПАРОЛЬ", "ПРАВА ДОСТУПА"};
    _ReadFromFile(table);
}

void AccountContainer::AddFunc()
{
    system("cls");
    lastID = elementList.size() + 1;
    cout << "Пожалуйста, добавьте новый аккаунт!!" << endl;

    string login, password, isAdmin;
    bool _isAdmin;
    cout << "Введите логин пользователя: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, login);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите пароль: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, password);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Введите права доступа: " << std::endl;
    cout << "<<<" << std::endl;
    try
    {
        getline(cin, isAdmin);
        _isAdmin = stob(isAdmin);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Account *el = new Account(lastID, login,
                              password, _isAdmin);
    AddElement(el);

    ContinueFunc([this]()
        { AddFunc(); });
}

void CinemaContainer::ChangeFunc()
{
    int id = _ChangeFunc();
    if (id == -1)
    {
        return;
    }

    cout << "Введите какие данные вы бы хотели изменить: " << endl;
    cout << ">>> ";
    // elementList[id]
}
