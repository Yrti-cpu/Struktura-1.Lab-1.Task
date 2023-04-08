#include "List.h"


List::List()
{
    head = tail = nullptr;
}
List::~List()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->GetpNext();
        delete temp;
    }
}
void List::push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination)
{
    if (IsEmpty())
    {
        head = tail = new Node(travel_time, departure_time, train_number, train_type, destination);
    }
    else
    {
        Node* current = tail;
        current->SetpNext(new Node(travel_time, departure_time, train_number, train_type, destination));
        tail = current->GetpNext();
    }
    
}
bool List::IsEmpty()
{
    return head == nullptr;
}
void List::pop_back()
{
    if (!IsEmpty())
    {
        Node* current = head;
        while (current->GetpNext()->GetpNext() != nullptr)
        {
            current = current->GetpNext();
        }
        Node* toDelete = current->GetpNext();
        current->SetpNext(current->GetpNext()->GetpNext());
        delete toDelete;
        tail = current;
        std::cout << "Запись успешно удалена!" << std::endl;

    }
    else
    {
        std::cout << "Список пуст!\n";

    }
}
void List::show()
{
    if (!IsEmpty())
    {
        system("CLS");
        short count = 1;
        Node* current = head;
        std::string str = "";
        std::cout << "|" << std::setw(3) << "N" << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        while (current != nullptr)
        {
            str = current->StrTrainType();
            std::cout << "|" << std::setw(3) << count << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(15) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            current = current->GetpNext();
            count++;
        }

    }
    else
    {
        std::cout << "Список пуст!\n";

    }
    
}
void List::searchInfo(std::string destination, Time &time1, Time &time2)
{

    bool flag = false;
    Node* current = head;
    std::string str = "";
    while (current != nullptr)
    {
        if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && time1 <= current->GetDepartureTime() && current->GetDepartureTime() <= time2)
        {
            str = current->StrTrainType();
            std::cout << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(15) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
            std::cout << "--------------------------------------------------------------------------------" << std::endl;
            flag = true;
        }
        current = current->GetpNext();
    }
    if(!flag)
        std::cout << "\n\n\nПоездов следующих до " << destination << " в данный временной интервал не найдено" << std::endl;
}
void List::searchMin(std::string destination)
{
    char train_type = 0;
    Node::CheckTrainType(train_type);
    system("CLS");
    bool flag = false;
    Node* current = head;
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
        if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && current->GetTrainType() == train_type && (current->GetTravelTime() <= min_time || flag_time))
        {
            min_time = current->GetTravelTime();
            flag = true;
            flag_time = false;
        }
        current = current->GetpNext();
    }
    current = head;
    if (flag)
    {
        std::cout << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;

        while (current != nullptr)
        {
            if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && current->GetTrainType() == train_type && current->GetTravelTime() == min_time)
            {
               
                std::cout << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(15) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
                std::cout << "--------------------------------------------------------------------------------" << std::endl;
            }
            current = current->GetpNext();
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
    Node* current = head;
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
                entry = current->GetDestination() + " " + std::to_string(current->GetTrainType()) + " " + std::to_string(current->GetTrainNumber()) + " " + to_string(current->GetDepartureTime()) + " " + to_string(current->GetTravelTime());
                fs << entry;
            }
            else
            {
                entry = current->GetDestination() + " " + std::to_string(current->GetTrainType()) + " " + std::to_string(current->GetTrainNumber()) + " " + to_string(current->GetDepartureTime()) + " " + to_string(current->GetTravelTime());

                fs << "\n" << entry;
            }
            current = current->GetpNext();
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
