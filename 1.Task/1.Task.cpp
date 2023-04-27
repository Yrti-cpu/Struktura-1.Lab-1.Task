#include "List.h"

char menu();//меню
void DataAddition(List& l);//добавление записи

int main(int argc, char* argv[])
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    string path  = "";
    bool menucall = true;
    if (argv[1] != NULL)
    {
        path = argv[1];
    }
    else
    {
        cout << "Введите имя файла:\n";//ввод имени файла
        while (!(std::cin >> path));

    }
    List l1;//объявление пустого массива
    l1.DownloadData(path); //загрузка данных из бинарного файла
    //реализайция меню
    while (menucall)
    {
        switch (menu())
        {
        case 49:

            DataAddition(l1);
            system("pause");
            break;

        case 50:

            l1.show();
            system("pause");
            break;

        case 51:

            l1.pop_back();
            system("pause");
            break;
        case 52:

            l1.searchInfo();
            system("pause");
            break;

        case 53:
            l1.searchMin();
            system("pause");
            break;
        case 54:
            menucall = false;
            break;

        }
    }
    l1.UploadData(path);//выгрузка запесей списка в файл
    return 0;
}

char menu()
{
    char i = 1;
    while (i != 49 && i != 50 && i != 51 && i != 52 && i != 53 && i != 54)
    {
        system("CLS");
        std::cout << "1.Добавление записи\n";
        std::cout << "2.Просмотр записей\n";
        std::cout << "3.Удаление последней записи\n";
        std::cout << "4.Поиск записей(по пункту назначения, времени)\n";
        std::cout << "5.Поиск самого быстрого поезда(по пункту назначения, типу)\n";
        std::cout << "6.Выход\n";
        i = _getch();

    }

    return i;
}
void DataAddition(List& l)
{
    system("CLS");
    SetConsoleCP(1251);
    std::cout << "Введите данные о поезде:" << std::endl;
    std::string destination;
    Node::CheckDestination(destination);
    char train_type = 0;
    Node::CheckTrainType(train_type);
    short train_number = 0;
    Node::CheckTrainNumber(train_number);
    short hours, minutes;
    std::cout << "Время отправления(ЧЧ:ММ):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t1(true, hours, minutes);
    std::cout << "Время в пути(ЧЧ:ММ):\n";
    std::cin >> hours;
    std::cin.ignore(1024, ':');
    std::cin >> minutes;
    Time t2(false, hours, minutes);
    l.push_back(t2, t1, train_number, train_type, destination);
    std::cout << "Запись успешно сохранена!\n";
    SetConsoleCP(866);
}