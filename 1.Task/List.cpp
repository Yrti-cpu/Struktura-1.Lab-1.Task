#include "List.h"


List::List()
{
    head = tail = nullptr;//при инициализации указатели являются нулевыми 
}
List::~List()
{
    while (head != nullptr)//пока указатель на голову ненулевой
    {
        Node* temp = head;//создаем новый указатель на текущую голову
        head = head->GetpNext();//присваиваем голове адрес следующей записи через геттер
        delete temp;//удаляем указатель
    }
}
List::List(const List& l)
{
}
void List::push_back(Time travel_time, Time departure_time, short train_number, char train_type, std::string destination)
{
    if (IsEmpty())//если пустой
    {
        head = tail = new Node(travel_time, departure_time, train_number, train_type, destination);//создаем новую запись и присваиваем голове и хвосту ее адрес
    }
    else
    {
        Node* current = tail;//создаем указатель на хвост
        current->SetpNext(new Node(travel_time, departure_time, train_number, train_type, destination));//присваиваем указателю адрес новой записи через геттер
        tail = current->GetpNext();//присваиваем хвосту адрес последней записи
    }
    
}
bool List::IsEmpty()
{
    return head == nullptr;
}
void List::pop_back()
{
    system("CLS");
    if (!IsEmpty())//если список не пустой
    {
        Node* current = head;//создаем указатель на голову
        while (current->GetpNext()->GetpNext() != nullptr)//доходим до предпоследней записи
        {
            current = current->GetpNext();
        }
        Node* toDelete = current->GetpNext();//создаем указатель на последний элемент 
        current->SetpNext(current->GetpNext()->GetpNext());//указатель pNext предпоследей записи является нулевым
        delete toDelete;//удаляем последнюю запись
        tail = current;//передвигаем указатель хвоста
        std::cout << "Запись успешно удалена!" << std::endl;

    }
    else
    {
        std::cout << "Список пуст!\n";

    }
}
void List::show()
{
    system("CLS");
    if (!IsEmpty())//если не пустой список
    {
        system("CLS");
        short count = 1;//счетчик записей
        Node* current = head;//указатель на голову
        std::string str = "";
        //вывод шапки
        std::cout << "|" << std::setw(3) << "N" << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
        std::cout << "------------------------------------------------------------------------------------" << std::endl;
        while (current != nullptr)//пока не конец записей выводим информацию по полям класса Node
        {
            str = current->StrTrainType();
            std::cout << "|" << std::setw(3) << count << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(14) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            current = current->GetpNext();//передвигаем указатель на следующую запись
            count++;
        }

    }
    else
    {
        std::cout << "Список пуст!\n";

    }
    
}//пофиксить вывод
void List::searchInfo()
{
    system("CLS");
    if (!IsEmpty())//если не пустой
    {
        SetConsoleCP(1251);//перевод консоли в кодировку windows-1251 
        std::string destination;
        short hours, minutes;
        Node::CheckDestination(destination);//ввод и проверка 
        std::cout << "Введите нижнюю временную границу(ЧЧ:ММ):\n";
        std::cin >> hours;
        std::cin.ignore(1024, ':');
        std::cin >> minutes;
        Time t1(true, hours, minutes);//объявление объекта класса Time
        std::cout << "Введите верхнюю временную границу(ЧЧ:ММ):\n";
        std::cin >> hours;
        std::cin.ignore(1024, ':');
        std::cin >> minutes;
        Time t2(true, hours, minutes);//объявление объекта класса Time
        if (t1 <= t2)//если нижняя временная граница меньше или равна верхней
        {
            system("CLS");
            std::cout << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
            std::cout << "--------------------------------------------------------------------------------" << std::endl;
            bool flag = false;
            Node* current = head;
            std::string str = "";
            while (current != nullptr)//пока есть записи
            {
                //проверка на нужное место назначения без учета регистра и принадлежность временному интревалу
                if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && t1 <= current->GetDepartureTime() && current->GetDepartureTime() <= t2)
                {
                    str = current->StrTrainType();
                    std::cout << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(15) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
                    std::cout << "--------------------------------------------------------------------------------" << std::endl;
                    flag = true;
                }
                current = current->GetpNext();
            }
            if (!flag)
                system("CLS");
                std::cout << "Поездов следующих до " << destination << " в данный временной интервал не найдено" << std::endl;
            
        }
        else
        {
            std::cout << "Неправильно введен временной интервал!\n";
            return;
        }
        
        SetConsoleCP(866);//возвращаем кодировку 866 консоли 
    }
    else
    {
        std::cout << "Список пуст!\n";
    }
}
void List::searchMin()
{
    system("CLS");
    if (!IsEmpty())
    {
        SetConsoleCP(1251);
        std::string destination;
        Node::CheckDestination(destination);
        char train_type = 0;
        std::cout << "Чтобы определить поезд, доезжающий до " << destination << " за наименьшее время:" << std::endl;
        Node::CheckTrainType(train_type);
        system("CLS");
        bool flag = false;
        Node* current = head;
        std::string str = "";
        switch (train_type)
        {
        case 49: str = "скорый"; break;
        case 50: str = "экспресс"; break;
        case 51: str = "пассажирский"; break;
        }
        bool flag_time = true;
        Time min_time;//объявление нулевого (все поля равны 0) объекта класса Time
        while (current != nullptr)
        {
            //поиск минимального затраченного на поездку времени с учетом типа поезда и места назначения
            if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && current->GetTrainType() == train_type && (current->GetTravelTime() <= min_time || flag_time))
            {
                min_time = current->GetTravelTime();
                flag = true;
                flag_time = false;
            }
            current = current->GetpNext();
        }
        current = head;
        //если записи найдены, то выводим их
        if (flag)
        {
            std::cout << "|" << std::setw(17) << "Пункт назначения" << "|" << std::setw(13) << "Тип поезда" << "|" << std::setw(13) << "Номер поезда" << "|" << std::setw(18) << "Время отправления" << "|" << std::setw(13) << "Время в пути" << "|" << std::endl;
            std::cout << "--------------------------------------------------------------------------------" << std::endl;

            while (current != nullptr)
            {
                if (!_strcmpi(current->GetDestination().c_str(), destination.c_str()) && current->GetTrainType() == train_type && current->GetTravelTime() == min_time)
                {

                    std::cout << "|" << std::setw(17) << current->GetDestination() << "|" << std::setw(13) << str << "|" << std::setw(13) << current->GetTrainNumber() << "|" << std::setw(15) << current->GetDepartureTime() << "|" << std::setw(10) << current->GetTravelTime() << "|" << std::endl;
                    std::cout << "--------------------------------------------------------------------------------" << std::endl;
                }
                current = current->GetpNext();
            }


        }

        else
            std::cout << "Поездов типа " << str << " следующих до " << destination << " не найдено" << std::endl;
        SetConsoleCP(866);
    }
    else
    {
        std::cout << "Список пуст!\n";
    }
    
}
void List::UploadData(std::string path)
{
    if (IsEmpty())//если список пустой, то прерываем работу метода
    return;
    SetConsoleCP(1251);
    Node* current = head;
    std::string entry = "";
    std::fstream fs;
    fs.exceptions(std::fstream::badbit | std::fstream::failbit);
    try
    {
        remove(path.c_str());//удаляем старый файл
        fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app | std::fstream::binary);//создаем одноименный файл на чтение и запись
        while (current != nullptr)//записываем в файл наш список (поля отделяются пробелом, а записи  - \n
        {
            if (entry.empty()) 
            {
                entry = current->GetDestination() + " " + std::to_string(current->GetTrainType()) + " " + std::to_string(current->GetTrainNumber()) + " " + to_string(current->GetDepartureTime()) + " " + to_string(current->GetTravelTime());
                fs << entry;
            }
            else
            {
                entry = current->GetDestination() + " " + std::to_string(current->GetTrainType()) + " " + std::to_string(current->GetTrainNumber()) + " " + to_string(current->GetDepartureTime()) + " " + to_string(current->GetTravelTime());

                fs << "\n" << entry;
            }
            current = current->GetpNext();
        }
            
        SetConsoleCP(866);

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;//если возникла ошибка
        std::cout << "Ошибка открытия файла!\n";
        system("pause");
    }
    fs.close();//закрываем файл
}
void List::DownloadData(std::string path)
{
    std::ifstream fin;
    fin.open(path, std::ifstream::binary);//открываем файл на чтение
    if (!fin.is_open())//если файла нет, то прекращаем работу метода
        return;
    if (fin.peek() == EOF)//аналогично, если файл пустой
        return;
    std::string row;
    short i = 5;
    while (!fin.eof())//идем по файлу пока не конец
    {
        std::string* result = new std::string[i];//массив строк
        short count = 0;
        row = "";
        getline(fin, row);//считываем строку
        std::istringstream input(row);//добавляем в поток 
        while (!input.eof())//пока не конец потока
        {
            std::string str;
            input >> str;
            result[count] = str;//добавляем в массив 
            count++;
        }
        push_back(to_Time(result[4]), to_Time(result[3]), atoi(result[2].c_str()), atoi(result[1].c_str()), result[0]);//добавляем в список
        delete[] result;//удаляем результирующий массив 
        input.clear();//чистим поток input
    }
    fin.close();//закрываем файл
}

