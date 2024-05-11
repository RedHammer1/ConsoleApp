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
    bool error = false;
    system("cls");
    lastID = elementList.size() + 1;
    cout << "Пожалуйста, добавьте новый аккаунт!!" << endl;

    string login, password;
    bool isAdmin;

    cout << "Введите логин: " << std::endl;
    login = Controller::GetFRCL_str(error);

    if (!error)
    {
        cout << "Введите пароль: " << std::endl;
        password = Controller::GetFRCL_str(error);
    }

    if (!error)
    {
        cout << "Введите права доступа: " << std::endl;
        isAdmin = Controller::GetFRCL_bool(error);
    }

    if (!error)
    {
        Account *el = new Account(lastID, login,
                                  password, isAdmin);
        AddElement(el);

        ContinueFunc([this]()
                     { AddFunc(); });
    }
}

void AccountContainer::ChangeFunc()
{
    bool error = false;
    int id = _ChangeFunc();
    if (id == -1)
    {
        return;
    }
    int cid = 0;
    cout << "Введите какие данные вы бы хотели изменить (счёт идёт с логина (от 0 до 2)): " << endl;
    cout << ">>> ";
    cin >> cid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (cid >= 0 && cid <= 4)
    {
        switch (cid)
        {
        case 0:
            elementList[id]->SetLogin(Controller::GetFRCL_str(error));
            break;
        case 1:
            elementList[id]->SetPassword(Controller::GetFRCL_str(error));
            break;
        case 2:
            elementList[id]->SetIsAdmin(Controller::GetFRCL_bool(error));
            break;
        default:
            break;
        }
        SaveToFile();
        ContinueFunc(
            [this]()
            { ChangeFunc(); });
    }

    return;
}
