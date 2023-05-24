#include "List.h"

List::List()
{
    head = tail = nullptr;//��� ������������� ��������� �������� �������� 
}
List::~List()
{
    while (head != nullptr)//���� ��������� �� ������ ���������
    {
        Node* temp = head;//������� ����� ��������� �� ������� ������
        head = head->pNext;//����������� ������ ����� ��������� ������ ����� ������
        delete temp;//������� ���������
    }
}
List::List(const List& other)
{
    this->head = this->tail = nullptr;
    Node* current = other.head;
    while (current != nullptr)
    {
        this->push_back(current->travel_time, current->departure_time, current->train_number, current->train_type, current->destination);
        current = current->pNext;
    }
}
List& List::operator=(const List& other)
{
    if (head == other.head)//�������� �� ����������������. ���� ����� � ������ ������� ��������� �� ���� ������� ������, ������� ������
        return *this;
    while (!this->IsEmpty())
    {
        this->pop_back();
    }
    this->head = this->tail = nullptr;
    Node* current = other.head;
    while (current != nullptr)
    {
        this->push_back(current->travel_time, current->departure_time, current->train_number, current->train_type, current->destination);
        current = current->pNext;
    }
    return *this;
}
void List::push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination)
{
    if (IsEmpty())//���� ������
    {
        head = tail = new Node(travel_time, departure_time, train_number, train_type, destination);//������� ����� ������ � ����������� ������ � ������ �� �����
    }
    else
    {
        Node* current = tail;//������� ��������� �� �����
        current->pNext =  new Node(travel_time, departure_time, train_number, train_type, destination);//����������� ��������� ����� ����� ������ ����� ������
        tail = current->pNext;//����������� ������ ����� ��������� ������
    }
    
}
bool List::IsEmpty()
{
    return head == nullptr;
}
void List::pop_back()
{
    system("CLS");
    if (IsEmpty())//���� ������ ������
    {
        std::cout << "������ ����!\n";
        return;
    }
    if (head->pNext == nullptr)
    {
        head = tail = nullptr;
        std::cout << "������ ������� �������!" << std::endl;
        return;
    }
    Node* current = head;//������� ��������� �� ������
    while (current->pNext->pNext != nullptr)//������� �� ������������� ������
    {
        current = current->pNext;
    }
    Node* toDelete = current->pNext;
    current->pNext = current->pNext->pNext;//��������� pNext ������ ������������ ������ ���������� �������
    delete toDelete;//������� ��������� ������
    tail = current;//����������� ��������� ������
    std::cout << "������ ������� �������!" << std::endl;
}
void List::show()
{
    system("CLS");
    if (!IsEmpty())//���� �� ������ ������
    {
        short count = 1;//������� �������
        Node* current = head;//��������� �� ������
        std::string str = "";
        PrintHat();//����� �����
        while (current != nullptr)//���� �� ����� ������� ������� ���������� �� ����� ������ Node
        {
            str = current->StrTrainType();
            current->PrintOne(count, str);//����� 1 �������� ������
            current = current->pNext;//����������� ��������� �� ��������� ������
            count++;
        }

    }
    else
    {
        std::cout << "������ ����!\n";

    }
    
}//��������� �����
void List::searchInfo()
{
    system("CLS");
    if (!IsEmpty())//���� �� ������
    {
        SetConsoleCP(1251);//������� ������� � ��������� windows-1251 
        std::string destination;
        short hours, minutes;
        List::CheckDestination(destination);//���� � �������� 
        std::cout << "������� ������ ��������� �������(��:��):\n";
        std::cin >> hours;
        std::cin.ignore(1024, ':');
        std::cin >> minutes;
        Time t1(true, hours, minutes);//���������� ������� ������ Time
        std::cout << "������� ������� ��������� �������(��:��):\n";
        std::cin >> hours;
        std::cin.ignore(1024, ':');
        std::cin >> minutes;
        Time t2(true, hours, minutes);//���������� ������� ������ Time
        if (t1 <= t2)//���� ������ ��������� ������� ������ ��� ����� �������
        {
            system("CLS");
            PrintHat();//����� �����
            bool flag = false;
            short count = 1;//������� �������
            Node* current = head;
            std::string str = "";
            while (current != nullptr)//���� ���� ������
            {
                //�������� �� ������ ����� ���������� ��� ����� �������� � �������������� ���������� ���������
                if (!_strcmpi(current->destination.c_str(), destination.c_str()) && t1 <= current->departure_time && current->departure_time <= t2)
                {
                    str = current->StrTrainType();
                    current->PrintOne(count, str);//����� 1 �������� ������
                    flag = true;
                    count++;
                }
                current = current->pNext;
            }
            if (!flag)
            {
                system("CLS");
                std::cout << "������� ��������� �� " << destination << " � ������ ��������� �������� �� �������" << std::endl;
            }
                
        }
        else
        {
            std::cout << "����������� ������ ��������� ��������!\n";
            return;
        }
        
        SetConsoleCP(866);//���������� ��������� 866 ������� 
    }
    else
    {
        std::cout << "������ ����!\n";
    }
}
void List::searchMin()
{
    system("CLS");
    if (!IsEmpty())
    {
        SetConsoleCP(1251);
        std::string destination;
        List::CheckDestination(destination);
        char train_type = 0;
        std::cout << "����� ���������� �����, ���������� �� " << destination << " �� ���������� �����:" << std::endl;
        List::CheckTrainType(train_type);
        system("CLS");
        bool flag = false;
        short count = 1;//������� �������
        Node* current = head;
        std::string str = "";
        switch (train_type)
        {
        case 49: str = "������"; break;
        case 50: str = "��������"; break;
        case 51: str = "������������"; break;
        }
        bool flag_time = true;
        Time min_time;//���������� �������� (��� ���� ����� 0) ������� ������ Time
        while (current != nullptr)
        {
            //����� ������������ ������������ �� ������� ������� � ������ ���� ������ � ����� ����������
            if (!_strcmpi(current->destination.c_str(), destination.c_str()) && current->train_type == train_type && (current->travel_time <= min_time || flag_time))
            {
                min_time = current->travel_time;
                flag = true;
                flag_time = false;
            }
            current = current->pNext;
        }
        current = head;
        //���� ������ �������, �� ������� ��
        if (flag)
        {
            PrintHat();//����� �����
            while (current != nullptr)
            {
                if (!_strcmpi(current->destination.c_str(), destination.c_str()) && current->train_type == train_type && current->travel_time == min_time)
                {

                    current->PrintOne(count, str);//����� 1 �������� ������
                    count++;
                }
                current = current->pNext;
            }
        }
        else
            std::cout << "������� ���� " << str << " ��������� �� " << destination << " �� �������" << std::endl;
        SetConsoleCP(866);
    }
    else
    {
        std::cout << "������ ����!\n";
    }
    
}
void List::UploadData(std::string path)
{
    remove(path.c_str());//������� ������ ����
    if (IsEmpty())//���� ������ ������, �� ��������� ������ ������
    return;
    SetConsoleCP(1251);
    Node* current = head;
    std::string entry = "";
    std::fstream fs;
    fs.exceptions(std::fstream::badbit | std::fstream::failbit);
    try
    {
        fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app | std::fstream::binary);//������� ����������� ���� �� ������ � ������
        while (current != nullptr)//���������� � ���� ��� ������ (���� ���������� ��������, � ������  - \n
        {
            if (entry.empty()) 
            {
                entry = current->destination + " " + std::to_string(current->train_type) + " " + std::to_string(current->train_number) + " " + to_string(current->departure_time) + " " + to_string(current->travel_time);
                fs << entry;
            }
            else
            {
                entry = current->destination + " " + std::to_string(current->train_type) + " " + std::to_string(current->train_number) + " " + to_string(current->departure_time) + " " + to_string(current->travel_time);

                fs << "\n" << entry;
            }
            current = current->pNext;
        }
            
        SetConsoleCP(866);

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;//���� �������� ������
        std::cout << "������ �������� �����!\n";
        system("pause");
    }
    fs.close();//��������� ����
}
void List::DownloadData(std::string path)
{
    std::ifstream fin;
    fin.open(path, std::ifstream::binary);//��������� ���� �� ������
    if (!fin.is_open())//���� ����� ���, �� ���������� ������ ������
        return;
    if (fin.peek() == EOF)//����������, ���� ���� ������
        return;
    std::string row;
    short i = 5;
    while (!fin.eof())//���� �� ����� ���� �� �����
    {
        std::string* result = new std::string[i];//������ �����
        short count = 0;
        row = "";
        getline(fin, row);//��������� ������
        std::istringstream input(row);//��������� � ����� 
        while (!input.eof())//���� �� ����� ������
        {
            std::string str;
            input >> str;
            result[count] = str;//��������� � ������ 
            count++;
        }
        push_back(to_Time(result[4]), to_Time(result[3]), atoi(result[2].c_str()), atoi(result[1].c_str()), result[0]);//��������� � ������
        delete[] result;//������� �������������� ������ 
        input.clear();//������ ����� input
    }
    fin.close();//��������� ����
}
void PrintHat()
{
    std::cout << "|" << std::setw(3) << "N" << "|" << std::setw(17) << "����� ����������" << "|" << std::setw(13) << "��� ������" << "|" << std::setw(13) << "����� ������" << "|" << std::setw(18) << "����� �����������" << "|" << std::setw(13) << "����� � ����" << "|" << std::endl;
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
}
std::string List::CheckDestination(std::string& destination)
{
    while (destination.empty())
    {
        system("cls");
        std::cout << "����� ����������:" << std::endl;
        std::cin >> destination;
    }
    return destination;
}
char List::CheckTrainType(char& train_type)
{
    while (train_type != 49 && train_type != 50 && train_type != 51)
    {
        system("cls");
        std::cout << "�������� ��� ������:\n" << "1.������\n" << "2.��������\n" << "3.������������" << std::endl;
        train_type = _getch();
    }
    return train_type;
}
short List::CheckTrainNumber(short& train_number)
{
    while (train_number <= 0)
    {
        system("cls");
        std::cout << "������� ����� ������:" << std::endl;
        std::cin >> train_number;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
    }
    return train_number;
}