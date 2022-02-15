#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char* filename = "in.txt"; //имя файла
    size_t length = 0; //длина текста в файле
    char* buf = 0; //массив значений файла
    char* circle = "0018"; //массив для проверки кода окружности по WKT
    int proverka = 0; //переменная для проверки
    int j = 0; //итератор для передвижения по массиву buf
    fstream fs; // поток ввода вывода
    fs.open(filename, ios::in); //открываем файл
        if (fs.is_open())
        {
            fs.seekg(0, ios::end);// измеряем
            length = fs.tellg();    // файл
            buf = new char[1 + length]; //выделяем место
            buf[length] = 0;
            for (int i = length; i > 0; i--) //i отвечает за передвижение по файлу, j по массиву
            {   
                fs.seekg(-i, ios::end);
                buf[j]= fs.get();
//                cout << buf[j]; // вывод считанных значений
                j++;
            }
//            cout << endl;
            fs.close();
        }

        else // ошибка открытия файла
        {
            cout << "Файл не был открыт:\n1) Проверьте корректность названия файла\n2) Файл отсутвует или поврежден\n";
            return 1;
        }
    for (int i = 0; i < 4; i++) // сравнение кода окружности и полученных с файла значений
    {
        if (buf[i] != circle[i])
            break;
        proverka++;
    }
    if (proverka == 4) // проверка на удачное сравнение кода окружности
        cout << "Circle!" << endl;
    else // ошибка некоректных полученных значений
        cout << "Error: no Circle :(" << endl;

    return 0;
}