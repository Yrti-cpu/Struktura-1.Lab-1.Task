#pragma once
#include "List.h"

char menu();//меню
void DataAddition(List& l);//добавление записи
void ShowData(List& l);//вывод всех записей
void SearchData(List& l);//поиск поездов по месту и временнному интервалу
void SearchMINData(List& l);//поиск самомого быстрого поезда по месту и типу
void DownloadData(List& l, std::string path);//загрузка запесей списка из файла
