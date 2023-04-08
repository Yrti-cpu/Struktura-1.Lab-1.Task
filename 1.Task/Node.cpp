#include "Node.h"

Node::Node(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination, Node* pNext)
{
    this->destination = CheckDestination(destination);
    this->train_type = CheckTrainType(train_type);
    this->train_number = CheckTrainNumber(train_number);
    this->departure_time = departure_time;
    this->travel_time = travel_time;
}
std::string Node::CheckDestination(std::string& destination)
{
    while (destination.empty())
    {
        std::cout << "����� ����������:" << std::endl;
        std::cin >> destination;
    }
    return destination;
}
char Node::CheckTrainType(char& train_type)
{
    while (train_type != 49 && train_type != 50 && train_type != 51)
    {
        std::cout << "�������� ��� ������:\n" << "1.������\n" << "2.��������\n" << "3.������������" << std::endl;
        train_type = _getch();
    }
    return train_type;
}
short Node::CheckTrainNumber(short& train_number)
{
    while (train_number <= 0)
    {
        std::cout << "������� ����� ������:" << std::endl;
        std::cin >> train_number;
    }
    return train_number;
}
std::string Node::StrTrainType()
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
