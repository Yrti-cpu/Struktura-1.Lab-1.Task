#pragma once
#include "Time.h"
#include <conio.h>
class Node
{
public:
    Node(Time travel_time = Time(), Time departure_time = Time(), short train_number = short(), char train_type = char(), std::string destination = std::string(), Node* pNext = nullptr);//конструктор класса
    //проверка полей данных
    static std::string CheckDestination(std::string& destination);
    static char CheckTrainType(char& train_type);
    static short CheckTrainNumber(short& train_number);
    std::string StrTrainType();//из чара в строку для вывода в консоль
    //геттеры
    std::string GetDestination() { return destination; }
    short GetTrainNumber() { return train_number; }
    char GetTrainType() { return train_type; }
    Time GetDepartureTime() { return departure_time; }
    Time GetTravelTime() { return travel_time; }
private:
    Node* pNext;//указатель на следующий узел данных
    //поля данных
    std::string destination;
    short train_number;
    char train_type;
    Time departure_time;
    Time travel_time;

};

