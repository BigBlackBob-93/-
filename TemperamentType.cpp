
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

using namespace std;
ifstream File; //файл
string text; //строка текста

void OpenFile(string &FileName) //функция-проверка успешного открытия файла
{
    File.open(FileName);
    if (!File.is_open())
    {
        cout << "\nДля использования программы необходим файл, который невозможно открыть!" << endl;
        exit(0);
    }
}

#define N 1 //шкала найротизма
#define E 2 //шкала экстраверсии
#define L 3 //шкала ложных ответов
int T[2][41] =  //двумерный массив для утвердительных ответов на соответсвие вопрос-шкала (для начисления баллов) 
{
{1,2,3,4,6,7,8,9,10,11,13,14,16,17,19,21,22,23,24,25,26,27,28,31,33,35,36,38,39,40,43,44,45,46,47,49,50,52,53,55,56},
{E,N,E,N,L,N,E,N,E,N,E,N,N,E,N,N,E,N,L,E,N,E,N,N,N,N,L,N,E,N,N,E,N,E,N,E,N,N,E,N,N}
};
int F[2][15] = //аналогично предыдущему, но для отрицательных ответов
{
    {5,12,15,18,20,29,30,32,34,37,41,42,48,51,54},
    {E,L,E,L,E,E,L,E,E,E,E,L,L,E,L}
};
/*
Чтение массива T пр.: на вопрос №1 был дан ответ "да" == T[0][0] => ответ соотвествует шкале экстраверсии == T[1][0] 
*/

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Ne = 0, Ex = 0, Li = 0; //переменные для подсчёта баллов по шкале нейротизма, экстраверсии и лжи соответсвенно
    string FileName = "questions.txt";
    string Tanswer = "да";
    int scale = 0;
    int count = 0;
    int g = 0;
    //вывод начальной фразы
    OpenFile(FileName); 
    for (int i = 0; i < 4; i++)
    {
        getline(File, text);
        cout << text << endl;
        Sleep(4000);
    }
    Sleep(2000);
    cout << endl << "--Поехали--"<<endl;
    //ответы на вопросы и начисление очков
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
       //определение результата
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
            cout << "\n К сожалению, у вас слишком высок балл неискренности в ответах, что свидетельствует о некоторой демонстративности поведения";
            cout << "\nи ориентированности на социальное одобрение. Пожалуйста, пройдите тест заново через некоторое время.";
            return 0;
        }
        //вывод результата
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
