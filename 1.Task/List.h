#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "Time.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <fstream>

//������� �������� ������� ������
std::string CheckDestination(std::string& destination);
char CheckTrainType(char& train_type);
short CheckTrainNumber(short& train_number);


class List
{
public:

    List();//����������� ������
    ~List();//���������� ������
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//���������� ���� � ����� ������
    bool IsEmpty();//�������� �� �������
    void pop_back();//�������� ���������� ����
    void show();//����� � ������� ����� ������
    void searchInfo(std::string destination, Time& time1, Time& time2);//����� ������� �� ����� � ����������� ��������� 
    void searchMin(std::string destination);//����� �������� �������� ������ �� ����� � ����
    void UploadData(std::string path);//�������� � ���� 

private:
    class  TimeTable
    {
    public:
        TimeTable(Time travel_time, Time departure_time, short train_number = short(), char train_type = char(), std::string destination = std::string(), TimeTable* pNext = nullptr)//����������� ������
        {
            this->destination = CheckDestination(destination);
            this->train_type = CheckTrainType(train_type);
            this->train_number = CheckTrainNumber(train_number);
            this->departure_time = departure_time;
            this->travel_time = travel_time;
        }
        //������ ���� ������
        std::string GetTraintype()
        {
            std::string str = "";
            switch (train_type)
            {
            case 49: str = "������"; break;
            case 50: str = "��������"; break;
            case 51: str = "������������"; break;
            }
            return str;
        }
        TimeTable* pNext;//��������� �� ��������� ����
        //������
        std::string destination;
        short train_number;
        char train_type;
        Time departure_time;
        Time travel_time;

    };
    TimeTable* head;//������ ������
    TimeTable* tail;//����� ������
};

