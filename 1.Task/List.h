#pragma once
#include "Time.h"
#include <conio.h>
#include <Windows.h>
#include <sstream>
#include <fstream>


class List
{
public:
    List();//����������� ������
    ~List();//���������� ������
    List(const List& other);//����������� �����������
    List& operator=(const List& other);//�������� ������������
    void push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination);//���������� ���� � ����� ������
    bool IsEmpty();//�������� �� �������
    void pop_back();//�������� ���������� ����
    
    void show();//����� � ������� ����� ������
    void searchInfo();//����� ������� �� ����� � ����������� ��������� 
    void searchMin();//����� �������� �������� ������ �� ����� � ����
    void UploadData(std::string path);//�������� � ���� 
    void DownloadData(std::string path);
    //�������� ����� ������
    static std::string CheckDestination(std::string& destination);
    static char CheckTrainType(char& train_type);
    static short CheckTrainNumber(short& train_number);
    
private:
    class Node
    {
    public:
        Node(Time travel_time = Time(), Time departure_time = Time(), short train_number = short(), char train_type = char(), std::string destination = std::string(), Node* pNext = nullptr)//����������� ������
        {
            //�������� ������� ������
            this->destination = CheckDestination(destination);
            this->train_type = CheckTrainType(train_type);
            this->train_number = CheckTrainNumber(train_number);
            this->departure_time = departure_time;
            this->travel_time = travel_time;
        }
        std::string StrTrainType()//�� ���� � ������ ��� ������ � ������� 
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
        void PrintOne(int count, std::string st)//����� 1 �������� ������
        {
            std::cout << "|" << std::setw(3) << count << "|" << std::setw(17) << destination << "|" << std::setw(13) << st << "|" << std::setw(13) << train_number << "|" << "\t\t" << departure_time << "|" << "\t      " << travel_time << "|" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
        }
        Node* pNext;//��������� �� ��������� ���� ������
        //���� ������
        std::string destination;
        short train_number;
        char train_type;
        Time departure_time;
        Time travel_time;

    };
    Node* head;//������ ������
    Node* tail;//����� ������
};
void PrintHat();//����� �����
