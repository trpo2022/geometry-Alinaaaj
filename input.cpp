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

/*struct Triangle {
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;
};*/

int main()
{
    string file_in, word_in;
    string buffer;
    string digitSymbol = "";
    char schet[8];
    Circle o;
    // Triangle tri;
    int check = 0;
    string circle = "circle";
    // string triangle = "triangle";

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
        /*double t[13] = {0};
        if (buffer.find(triangle , 0)!=-1)
        {
           for (int i = buffer.find(triangle , 0); i < buffer.size(); i++)
        //парсинг чисел
            {
                if (buffer[i] == '(')
                    check = 1;
                if (check)
                {
                    if (isdigit(buffer[i]) || buffer[i] == '.' || buffer[i]
        =='-')                         //проверка на число digitSymbol +=
        buffer[i]; if (isspace(buffer[i]) || buffer[i] == ')') //если встречено
        пробел или )
                    {
                        d[i%13] = atof(digitSymbol.c_str());
                        digitSymbol.clear();
                    }
                }

            }
            tri.x1 = t[0];
            tri.y1 = t[1];
            tri.x2 = t[5];
            tri.y2 = t[7];
            tri.x3 = t[10];
            tri.y3 = t[12];
            cout << "X1 = " << tri.x1 << endl;
            cout << "Y1 = " << tri.y1 << endl;
            cout << "X2 = " << tri.x2 << endl;
            cout << "Y2 = " << tri.y2 << endl;
            cout << "X3 = " << tri.x3 << endl;
            cout << "Y3 = " << tri.y3 << endl;
        }*/
        buffer.clear();
    }
    in.close();

    return 0;
}