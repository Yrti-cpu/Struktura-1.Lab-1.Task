#pragma once
#include "List.h"

char menu();//����
void DataAddition(List& l);//���������� ������
void ShowData(List& l);//����� ���� �������
void DeleteData(List& l);//�������� �������� ������
void SearchData(List& l);//����� ������� �� ����� � ����������� ���������
void SearchMINData(List& l);//����� �������� �������� ������ �� ����� � ����
void DownloadData(List& l, std::string path);//�������� ������� ������ �� �����
