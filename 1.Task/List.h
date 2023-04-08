#pragma once
#include "Node.h"
#include <iomanip>
#include <Windows.h>
#include <sstream>
#include <fstream>

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
    Node* head;//голова списка
    Node* tail;//хвост списка
};

