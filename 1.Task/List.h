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
    List(const List& other);//����������� �����������
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//���������� ���� � ����� ������
    bool IsEmpty();//�������� �� �������
    void pop_back();//�������� ���������� ����
    friend void PrintOne(int count, Node* current, std::string st);//����� 1 �������� ������
    void show();//����� � ������� ����� ������
    void searchInfo();//����� ������� �� ����� � ����������� ��������� 
    void searchMin();//����� �������� �������� ������ �� ����� � ����
    void UploadData(std::string path);//�������� � ���� 
    void DownloadData(std::string path);
private:
    Node* head;//������ ������
    Node* tail;//����� ������
};
void PrintHat();//����� �����
