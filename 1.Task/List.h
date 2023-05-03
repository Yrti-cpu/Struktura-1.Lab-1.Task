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
    List(const List& other);//конструктор копирования
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//добавление узла в конец списка
    bool IsEmpty();//проверка на пустоту
    void pop_back();//удаление последнего узла
    friend void PrintOne(int count, Node* current, std::string st);//вывод 1 элемента списка
    void show();//вывод в консоль всего списка
    void searchInfo();//поиск поездов по месту и временнному интервалу 
    void searchMin();//поиск самомого быстрого поезда по месту и типу
    void UploadData(std::string path);//выгрузка в файл 
    void DownloadData(std::string path);
private:
    Node* head;//голова списка
    Node* tail;//хвост списка
};
void PrintHat();//вывод шапки
