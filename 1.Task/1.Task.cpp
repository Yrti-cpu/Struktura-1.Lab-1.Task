#include "Menu.h"

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
    DownloadData(l1, path); //загрузка данных из бинарного файла
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

            ShowData(l1);
            system("pause");
            break;

        case 51:

            DeleteData(l1);
            system("pause");
            break;
        case 52:

            SearchData(l1);
            system("pause");
            break;

        case 53:
            SearchMINData(l1);
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