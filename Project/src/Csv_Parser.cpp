#include "../include/Csv_Parser.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <array>

using namespace std;

CSV_Parser::CSV_Parser(std::string filename)
{
    this->filename = filename;

    ifstream file(filename);

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string title, director, id;
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, director);
        int _id = stoi(id);

        Cinema *cinema = new Cinema(_id, title, director);
        cinemaList.push_back(cinema);
    }
    file.close();
}

std::wstring convertToWstring(const std::string& str)
{
	wchar_t* pWChr = new wchar_t[str.size()];
	size_t outSize;
	mbstowcs_s(&outSize, pWChr, str.size(), str.c_str(), str.size());

	std::wstring wStr(pWChr);
  delete[] pWChr;
	return wStr;
}

void CSV_Parser::SaveToFile()
{
    try
    {
        ofstream file(filename);

            for (int i = 0; i < cinemaList.size(); i++)
            {
                Cinema *cinema = cinemaList[i];
                file << cinema->GetId() << ";"
                     << cinema->GetTitle() << ";"
                     << cinema->GetDirector() << std::endl;

                     cout << cinema->GetId() << ";"
                     << cinema->GetTitle() << ";"
                     << cinema->GetDirector() << std::endl;
            }
        

        file.close();
    }
    catch (exception &ex)
    {
        cerr << ex.what() << endl;
        getchar();
    } 
}

void CSV_Parser::ReadFromFile()
{
    cinemaList.clear();
    ifstream file(this->filename);
    if (!file)
    {
        throw runtime_error("Ошибка в чтении файла");
    }
    
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string title, director, id;
        getline(ss, id, ';');
        getline(ss, title, ';');
        getline(ss, director);
        int _id = stoi(id);

        cinemaList.push_back( new Cinema(_id, title, director) );
    }
    file.close();

    for (int i = 0; i < cinemaList.size(); i++)
    {
        Cinema *cinema = cinemaList[i];
        std::cout << "ID: " << cinema->GetId() << "; " << "Название фильма: "
                  << cinema->GetTitle() << "; " << "ФИО режисера: "
                  << cinema->GetDirector() << std::endl;
    }
}

void CSV_Parser::AddCinema()
{
    lastID = cinemaList.size() + 1;
    cout << "Для добавления фильма в прокат, пожайлуйста, введите название фильма и ФИО режисера: " << endl;

    string title, director;
    cout << "Введите название фильма: ";
    try
    {
        std::cin >> title;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << "Введите ФИО режисера: ";
    try
    {
        std::cin >> director;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "Номер фильма #"<< lastID << " "<< title << " " << "Режисер:" << director  << endl;
    getchar();

    Cinema *cinemaItem = new Cinema(lastID, title, director);
    cinemaList.push_back(cinemaItem);
    SaveToFile();
}
void CSV_Parser::DeleteCinema()
{
    this->ReadFromFile();

    int id;
    cout << "Введить номер фильма для последующего удаления: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Cinema *_id = cinemaList[id - 1];

    auto it = std::find(cinemaList.begin(), cinemaList.end(), _id);
    if (it != cinemaList.end())
        cinemaList.erase(it);
}

void CSV_Parser::SortById(bool reverse)
{
    sort(
        cinemaList.begin(), cinemaList.end(),
        reverse ? [](Cinema *a, Cinema *b)
            { return a->GetTitle() > b->GetTitle(); }
                : [](Cinema *a, Cinema *b)
            { return a->GetTitle() < b->GetTitle(); });

    this->ReadFromFile();
}

void CSV_Parser::SortByTitle(bool reverse)
{
    this->ReadFromFile();
}