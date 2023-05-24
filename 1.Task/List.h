#pragma once
#include "Time.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <fstream>


class List
{
public:
    List();//конструктор списка
    ~List();//деструктор списка
    List(const List& other);//конструктор копирования
    List& operator=(const List& other);//оператор присваивания
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//добавление узла в конец списка
    bool IsEmpty();//проверка на пустоту
    void pop_back();//удаление последнего узла
    
    void show();//вывод в консоль всего списка
    void searchInfo();//поиск поездов по месту и временнному интервалу 
    void searchMin();//поиск самомого быстрого поезда по месту и типу
    void UploadData(std::string path);//выгрузка в файл 
    void DownloadData(std::string path);
    //проверка полей данных
    static std::string CheckDestination(std::string& destination);
    static char CheckTrainType(char& train_type);
    static short CheckTrainNumber(short& train_number);
    
private:
    class Node
    {
    public:
        Node(Time travel_time = Time(), Time departure_time = Time(), short train_number = short(), char train_type = char(), std::string destination = std::string(), Node* pNext = nullptr)//конструктор класса
        {
            //проверка входных данных
            this->destination = CheckDestination(destination);
            this->train_type = CheckTrainType(train_type);
            this->train_number = CheckTrainNumber(train_number);
            this->departure_time = departure_time;
            this->travel_time = travel_time;
        }
        std::string StrTrainType()//из чара в строку для вывода в консоль 
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
        void PrintOne(int count, std::string st)//вывод 1 элемента списка
        {
            std::cout << "|" << std::setw(3) << count << "|" << std::setw(17) << destination << "|" << std::setw(13) << st << "|" << std::setw(13) << train_number << "|" << "\t\t" << departure_time << "|" << "\t      " << travel_time << "|" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
        }
        Node* pNext;//указатель на следующий узел данных
        //поля данных
        std::string destination;
        short train_number;
        char train_type;
        Time departure_time;
        Time travel_time;

    };
    Node* head;//голова списка
    Node* tail;//хвост списка
};
void PrintHat();//вывод шапки
