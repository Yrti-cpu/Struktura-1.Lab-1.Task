#include "menu.h"

char menu()
{
    char i = 1;
    while(i != 49 && i != 50 && i != 51 && i != 52 && i != 53 && i != 54)
    {
            system("CLS");
            std::cout << "1.���������� ������\n";
            std::cout << "2.�������� �������\n";
            std::cout << "3.�������� ��������� ������\n";
            std::cout << "4.����� �������(�� ������ ����������, �������)\n";
            std::cout << "5.����� ������ �������� ������(�� ������ ����������, ����)\n";
            std::cout << "6.�����\n";
            i = _getch();
       
    } 

    return i;
}
void DataAddition(List& l)
{
    system("CLS");
    SetConsoleCP(1251);
    std::cout << "������� ������ � ������:" << std::endl;
    std::cout << "����� ����������:" << std::endl;
    std::string destination;
    std::cin >> destination;
    std::cout << "��� ������:\n1.������\n" << "2.��������\n" << "3.������������" << std::endl;
    char train_type = 0;
    train_type = _getch();
    short train_number = 0;
    std::cout << "������� ����� ������\n";
    std::cin >> train_number;
    short hours, minutes;
    std::cout << "����� �����������(��:��):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t1(true, hours, minutes);
    std::cout << "����� � ����(��:��):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t2(false, hours, minutes);
    l.push_back(t2,t1, train_number, train_type, destination);
    std::cout << "������ ������� ���������!\n";
    SetConsoleCP(866);
}
void ShowData(List& l)
{
    
    if (l.IsEmpty())
    {
        std::cout << "������ ����!\n";
        return;
    }
    
    l.show();
}
void SearchData(List& l)
{
    system("CLS");
    if (l.IsEmpty())
    {
        std::cout << "������ ����\n";
        return;
    }
    SetConsoleCP(1251);
    std::string destination;
    short hours, minutes;
    std::cout << "������� ����� ����������:\n";
    while (!(std::cin >> destination));
    std::cout << "������� ������ ��������� �������(��:��):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t1(true, hours, minutes);
    std::cout << "������� ������� ��������� �������(��:��):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t2(true, hours, minutes);
    if (t1 <= t2) 
    {
        system("CLS");
        std::cout << "|" << std::setw(17) << "����� ����������" << "|" << std::setw(13) << "��� ������" << "|" << std::setw(13) << "����� ������" << "|" << std::setw(18) << "����� �����������" << "|" << std::setw(13) << "����� � ����" << "|" << std::endl;
        std::cout << "--------------------------------------------------------------------------------" << std::endl;
        l.searchInfo(destination, t1, t2);
        SetConsoleCP(866);
    }
    else
    {
        std::cout << "����������� ������ ��������� ��������\n";
        return;
    }
    
    
}
void SearchMINData(List& l)
{
    system("CLS");
    if (l.IsEmpty())
    {
        std::cout << "������ ����\n";
        return;
    }
    SetConsoleCP(1251);
    std::string destination;
    std::cout << "������� ����� ����������:\n";
    while (!(std::cin >> destination));
    std::cout << "����� ���������� �����, ���������� �� " << destination << " �� ���������� �����:" << std::endl;
    l.searchMin(destination);
    SetConsoleCP(866);

}
void DownloadData(List& l, std::string path)
{
    std::ifstream fin;
    fin.open(path, std::ifstream::binary);
    if (!fin.is_open())
    {
        return;
    }
    if (fin.peek() == EOF)
        return;
    std::string row;
    short i = 5;
    while (!fin.eof())
    {
    std::string* result = new std::string[i];
    short count = 0;
    row = "";
    getline(fin, row);
    std::istringstream input(row);
    while (!input.eof())
    {
    std::string str;
    input >> str;
    result[count] = str;
    count++;
    }
    l.push_back(to_Time(result[4]), to_Time(result[3]), atoi(result[2].c_str()), atoi(result[1].c_str()), result[0]);
    delete[] result;
    input.clear();
    }
    fin.close();
}
    
        

    
   
