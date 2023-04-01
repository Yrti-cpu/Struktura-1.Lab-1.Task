#include "List.h"


List::List()
{
    head = tail = nullptr;
}
List::~List()
{
    while (head != nullptr)
    {
        TimeTable* temp = head;
        head = head->pNext;
        delete temp;
    }
}
void List::push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination)
{
    if (IsEmpty())
    {
        head = tail = new TimeTable(travel_time, departure_time, train_number, train_type, destination);
    }
    else
    {
        TimeTable* current = tail;
        current->pNext = new TimeTable(travel_time, departure_time, train_number, train_type, destination);
        tail = current->pNext;
    }
    
}
bool List::IsEmpty()
{
    return head == nullptr;
}
void List::pop_back()
{
    TimeTable* current = head;
    while (current->pNext->pNext!= nullptr)
    {
        current = current->pNext;
    }
    TimeTable* toDelete = current->pNext;
    current->pNext = current->pNext->pNext;
    delete toDelete;
    tail = current;
}
void List::show()
{
    short count = 1;
    TimeTable* current = head;
    std::string str = "";
    while (current != nullptr)
    {
        str = current->GetTraintype();
        std::cout << "|" << std::setw(3) << count << "|" << std::setw(17) << current->destination << "|" << std::setw(13) << str << "|" << std::setw(13) << current->train_number << "|" << std::setw(15) << current->departure_time << "|" << std::setw(10) << current->travel_time << "|" << std::endl;
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        current = current->pNext;
        count++;
    }
}
void List::searchInfo(std::string destination, Time &time1, Time &time2)
{
    bool flag = false;
    TimeTable* current = head;
    std::string str = "";
    while (current != nullptr)
    {
        if (!_strcmpi(current->destination.c_str(), destination.c_str()) && time1 <= current->departure_time && current->departure_time <= time2)
        {
            str = current->GetTraintype();
            std::cout << "|" << std::setw(17) << current->destination << "|" << std::setw(13) << str << "|" << std::setw(13) << current->train_number << "|" << std::setw(15) << current->departure_time << "|" << std::setw(10) << current->travel_time << "|" << std::endl;
            std::cout << "--------------------------------------------------------------------------------" << std::endl;
            flag = true;
        }
        current = current->pNext;
    }
    if(!flag)
        std::cout << "\n\n\nПоездов следующих до " << destination << " в данный временной интервал не найдено" << std::endl;
}
void List::searchMin(std::string destination)
{
    char train_type = 0;
    CheckTrainType(train_type);
    system("CLS");
    bool flag = false;
    TimeTable* current = head;
    std::string str = "";
    switch (train_type)
    {
    case 49: str = "скорый"; break;
    case 50: str = "экспресс"; break;
    case 51: str = "пассажирский"; break;
    }
    bool flag_time = true;  
    Time min_time;
    while (current != nullptr)
    {
        if (!_strcmpi(current->destination.c_str(), destination.c_str()) && current->train_type == train_type && (current->travel_time <= min_time || flag_time))
        {
            min_time = current->travel_time;
            flag = true;
            flag_time = false;
        }
        current = current->pNext;
    }
    current = head;
    if (flag)
    {
        std::cout << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;

        while (current != nullptr)
        {
            if (!_strcmpi(current->destination.c_str(), destination.c_str()) && current->train_type == train_type && current->travel_time == min_time)
            {
               
                std::cout << "|" << std::setw(17) << current->destination << "|" << std::setw(13) << str << "|" << std::setw(13) << current->train_number << "|" << std::setw(15) << current->departure_time << "|" << std::setw(10) << current->travel_time << "|" << std::endl;
                std::cout << "--------------------------------------------------------------------------------" << std::endl;
            }
            current = current->pNext;
        }

        
    }
        
    else 
        std::cout << "Поездов типа " << str << " следующих до " << destination << " не найдено" << std::endl;
}
void List::UploadData(std::string path)
{
    if (IsEmpty())
    return;
    SetConsoleCP(1251);
    TimeTable* current = head;
    std::string entry = "";
    std::fstream fs;
    fs.exceptions(std::fstream::badbit | std::fstream::failbit);
    try
    {
        remove(path.c_str());
        fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app | std::fstream::binary);
        while (current != nullptr)
        {
            if (entry.empty()) 
            {
                entry = current->destination + " " + std::to_string(current->train_type) + " " + std::to_string(current->train_number) + " " + to_string(current->departure_time) + " " + to_string(current->travel_time);
                fs << entry;
            }
            else
            {
                entry = current->destination + " " + std::to_string(current->train_type) + " " + std::to_string(current->train_number) + " " + to_string(current->departure_time) + " " + to_string(current->travel_time);

                fs << "\n" << entry;
            }
            current = current->pNext;
        }
            
        SetConsoleCP(866);

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
        std::cout << "Ошибка открытия файла!\n";
        system("pause");
    }
    fs.close();
}
std::string CheckDestination(std::string& destination)
{
    /*std::cout << "Неверно указан пункт назначения, попробуйте еще раз:" << std::endl;
    while (!(std::cin >> destination));*/ // не подходит, так как при считывании из файла тоже запрашивает ввод с клавиатуры
    while (destination.empty())
    {
        std::cout << "Неверно указан пункт назначения, попробуйте еще раз:" << std::endl;
        std::cin >> destination;
    }
    return destination;
}
char CheckTrainType(char& train_type)
{
    while (train_type != 49 && train_type != 50 && train_type != 51)
    {
        std::cout << "Выберите тип поезда:\n" << "1.скорый\n" << "2.экспресс\n" << "3.пассажирский" << std::endl;
        train_type = _getch();
    }
    return train_type;
}
short CheckTrainNumber(short& train_number)
{
    while (train_number <= 0)
    {
        std::cout << "Неверно указан номер поезда, попробуйте еще раз:" << std::endl;
        std::cin >> train_number;
    }
    return train_number;
}