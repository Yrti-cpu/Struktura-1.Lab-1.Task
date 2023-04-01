#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Time.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <fstream>

//функции проверки входных данных
std::string CheckDestination(std::string& destination);
char CheckTrainType(char& train_type);
short CheckTrainNumber(short& train_number);


class List
{
public:

    List();//конструктор списка
    ~List();//деструктор списка
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//добавление узла в конец списка
    bool IsEmpty();//проверка на пустоту
    void pop_back();//удаление последнего узла
    void show();//вывод в консоль всего списка
    void searchInfo(std::string destination, Time& time1, Time& time2);//поиск поездов по месту и временнному интервалу 
    void searchMin(std::string destination);//поиск самомого быстрого поезда по месту и типу
    void UploadData(std::string path);//выгрузка в файл 

private:
    class  TimeTable
    {
    public:
        TimeTable(Time travel_time, Time departure_time, short train_number = short(), char train_type = char(), std::string destination = std::string(), TimeTable* pNext = nullptr)//конструктор класса
        {
            this->destination = CheckDestination(destination);
            this->train_type = CheckTrainType(train_type);
            this->train_number = CheckTrainNumber(train_number);
            this->departure_time = departure_time;
            this->travel_time = travel_time;
        }
        //геттер типа поезда
        std::string GetTraintype()
        {
            std::string str = "";
            switch (train_type)
            {
            case 49: str = "скорый"; break;
            case 50: str = "экспресс"; break;
            case 51: str = "пассажирский"; break;
            }
            return str;
        }
        TimeTable* pNext;//указатель на следующий узел
        //данных
        std::string destination;
        short train_number;
        char train_type;
        Time departure_time;
        Time travel_time;

    };
    TimeTable* head;//голова списка
    TimeTable* tail;//хвост списка
};

