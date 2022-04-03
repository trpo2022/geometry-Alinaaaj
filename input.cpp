#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>

#include <cctype>

using namespace std;

struct Circle {
    double x;
    double y;
    double r; //радиус
};

int main()
{
    string file_in, word_in;
    string buffer;
    string digitSymbol = "";
    char schet[8];
    Circle o;
    int check = 0;
    string circle = "circle";

    cout << "Input file name: ";
    cin >> file_in;

    fstream in(file_in, ios::in);
    if (!in.good()) //проверка на открытие файла
    {
        clog << "Couldn't open file.\n";
        exit(1);
    }

    while (getline(in, buffer)) //запись строки из файла в строку буффер
    {
        for (int i = 0; i < buffer.size(); i++) {
            buffer[i] = tolower(buffer[i]); //перевод строки в нижний регистр
        }

        while (buffer.find("  ", 0) != -1) //поиск и удаление лишних пробелов
        {
            buffer.replace(buffer.find("  ", 0), 2, " ");
        }

        cout << buffer << endl;
        int c = 0;
        double d[3] = {0};
        if (buffer.find(circle, 0) != -1) {
            for (int i = buffer.find(circle, 0); i < buffer.size();
                 i++) //парсинг чисел
            {
                if (buffer[i] == '(')
                    check = 1;
                if (check) {
                    if (isdigit(buffer[i]) || buffer[i] == '.'
                        || buffer[i] == '-') //проверка на число
                        digitSymbol += buffer[i];
                    if (isspace(buffer[i])
                        || buffer[i] == ')') //если встречено пробел или )
                    {
                        d[c++] = atof(digitSymbol.c_str());
                        digitSymbol.clear();
                    }
                }
            }
            o.x = d[0];
            o.y = d[1];
            o.r = d[2];
            cout << endl << "Circle found:" << endl;
            cout << "X = " << o.x << endl;
            cout << "Y = " << o.y << endl;
            cout << "R = " << o.r << endl;
        } else
            clog << "Unknown figure!" << endl;
        buffer.clear();
    }
    in.close();

    return 0;
}