#pragma once
#include <iostream>
#include <string>


class Time
{
public:
    Time();//����������� �� ���������
    Time(bool state, short hours, short minutes);//����������� � �����������
    Time(const Time& t);//����������� �����������
    //�������
    short GetHour() { return hours; }
    short GetMinutes() { return minutes; }
    //�������
    void SetHour(short hours) { this->hours = hours; }
    void SetMinutes(short minutes) { this->minutes = minutes; }
    //���������� ���������� ���������
    bool operator ==(const Time other);
    bool operator <=(const Time other);
    //���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& os, Time time);
    //������� �� ����������������� ���� Time � ��� string
    friend std::string to_string(const Time &time);
private:
    short hours;
    short minutes;
};
Time to_Time(std::string str);