
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;
ifstream File; //����
string text; //������ ������

void OpenFile(string &FileName) //�������-�������� ��������� �������� �����
{
    File.open(FileName);
    if (!File.is_open())
    {
        cout << "\n��� ������������� ��������� ��������� ����, ������� ���������� �������!" << endl;
        exit(0);
    }
}

#define N 1 //����� ����������
#define E 2 //����� ������������
#define L 3 //����� ������ �������
int T[2][41] =  //��������� ������ ��� �������������� ������� �� ����������� ������-����� (��� ���������� ������) 
{
{1,2,3,4,6,7,8,9,10,11,13,14,16,17,19,21,22,23,24,25,26,27,28,31,33,35,36,38,39,40,43,44,45,46,47,49,50,52,53,55,56},
{E,N,E,N,L,N,E,N,E,N,E,N,N,E,N,N,E,N,L,E,N,E,N,N,N,N,L,N,E,N,N,E,N,E,N,E,N,N,E,N,N}
};
int F[2][15] = //���������� �����������, �� ��� ������������� �������
{
    {5,12,15,18,20,29,30,32,34,37,41,42,48,51,54},
    {E,L,E,L,E,E,L,E,E,E,E,L,L,E,L}
};
/*
������ ������� T ��.: �� ������ �1 ��� ��� ����� "��" == T[0][0] => ����� ������������ ����� ������������ == T[1][0] 
*/

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Ne = 0, Ex = 0, Li = 0; //���������� ��� �������� ������ �� ����� ����������, ������������ � ��� �������������
    string FileName = "questions.txt";
    string Tanswer = "��";
    int scale = 0;
    int count = 0;
    int g = 0;
    //����� ��������� �����
    OpenFile(FileName); 
    for (int i = 0; i < 4; i++)
    {
        getline(File, text);
        cout << text << endl;
        Sleep(4000);
    }
    Sleep(2000);
    cout << endl << "--�������--"<<endl;
    //������ �� ������� � ���������� �����
    while (!File.eof())
    {
        getline(File, text);
        cout << endl << text << endl;
        count++;
        cin >> text;
        g = count;
        scale = 0;
        if (text == Tanswer)
        {
            for (int i = 0; (count >= T[0][i]); i++)
            {
                if (count == T[0][i]) scale = T[1][i];
            }
            
        }
        else 
        {
            for (int i = 0; (count >= F[0][i]); i++)
            {
                if (count == F[0][i]) scale = F[1][i];
            }
        }

        if (scale == 1)Ne++;
        else
        {
            if (scale == 2)Ex++;
            else  if (scale == 3) Li++;
        }
        system("cls");
    }
    File.close();
       //����������� ����������
        if (Li <= 5)
        {
            if (Ex <= 12)
            {
                if (Ne <= 12) FileName = "phlegmatic.txt";
                else FileName = "melancholic.txt";
            }
            else
            {
                if (Ne <= 12) FileName = "sanguine.txt";
                else FileName = "choleric.txt";
            }
        }
        else
        {
            cout << "\n � ���������, � ��� ������� ����� ���� ������������� � �������, ��� ��������������� � ��������� ����������������� ���������";
            cout << "\n� ����������������� �� ���������� ���������. ����������, �������� ���� ������ ����� ��������� �����.";
            return 0;
        }
        //����� ����������
        OpenFile(FileName);
        while (!File.eof())
        {
            text = "";
            getline(File, text);
            cout << text << endl;
            Sleep(1000);
        }
        File.close();  
}
