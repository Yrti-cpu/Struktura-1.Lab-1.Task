#pragma once
#include "Node.h"
#include <iomanip>
#include <Windows.h>
#include <sstream>
#include <fstream>

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
    Node* head;//������ ������
    Node* tail;//����� ������
};

