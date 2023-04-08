#pragma once
#include <iostream>
#include <string>


class Time
{
public:
    Time();//конструктор по умолчанию
    Time(bool state, short hours, short minutes);//конструктор с параметрами
    Time(const Time& t);//конструктор копирования
    //геттеры
    short GetHour() { return hours; }
    short GetMinutes() { return minutes; }
    //сеттеры
    void SetHour(short hours) { this->hours = hours; }
    void SetMinutes(short minutes) { this->minutes = minutes; }
    //перегрузка операторов сравнения
    bool operator ==(const Time other);
    bool operator <=(const Time other);
    //перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, Time time);
    //перевод из пользовательского типа Time в тип string
    friend std::string to_string(const Time &time);
private:
    short hours;
    short minutes;
};
Time to_Time(std::string str);