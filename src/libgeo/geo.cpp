#include "geo.h"
Circle FindCircle(string buffer)
{
    Circle o;
    int c = 0;
    string digitSymbol = "";
    string circle = "circle";
    bool check = false;
    double d[3];
    for (int i = 0; i < 3; i++) {
        d[i] = 0;
    }
    for (unsigned int i = buffer.find(circle, 0); i < buffer.size();
         i++) //парсинг чисел
    {
        if (buffer[i] == '(')
            check = true;
        if (check) {
            if (isdigit(buffer[i]) || buffer[i] == '.'
                || buffer[i] == '-') //проверка на число
                digitSymbol += buffer[i];
            else if (isspace(buffer[i]) || buffer[i] == ')') //если
                                                             //встречено
                                                             //пробел
                                                             //или )
            {
                d[c++] = atof(digitSymbol.c_str());
                digitSymbol.clear();
            } else if (buffer[i] != ',' && buffer[i] != '(')
                cout << "Incorrect format!!! --> "
                     << "<" << buffer[i] << ">" << endl;
        }
    }
    o.x = d[0];
    o.y = d[1];
    o.r = d[2];

    o.square = Pi * o.r * o.r;
    o.perimeter = 2 * Pi * o.r;

    return o;
}
Triangle FindTriangle(string buffer)
{
    Triangle tr;
    double tri[8];
    int tmp = 0;
    int check = 0;
    string digitSymbol = "";
    for (int i = 0; i < 8; i++) {
        tri[i] = 0;
    }
    for (unsigned int i = buffer.find("triangle", 0); i < buffer.size();
         i++) //парсинг чисел
    {
        if (buffer[i] == '(')
            check++;
        if (check == 2) {
            if (isdigit(buffer[i]) || buffer[i] == '.'
                || buffer[i] == '-') //проверка на число
                digitSymbol += buffer[i];
            else if (isspace(buffer[i]) || (buffer[i] == ')')) //если
                                                               //встречено
                                                               //пробел
                                                               //или )
            {
                if (buffer[i - 1] != ')') {
                    tri[tmp++] = atof(digitSymbol.c_str());
                    digitSymbol.clear();
                }
            } else if (buffer[i] != ',' && buffer[i] != '(')
                cout << "Incorrect format!!! --> "
                     << "<" << buffer[i] << ">" << endl;
        }
    }
    tr.coord1[0] = tri[0];
    tr.coord1[1] = tri[1];
    tr.coord2[0] = tri[2];
    tr.coord2[1] = tri[3];
    tr.coord3[0] = tri[4];
    tr.coord3[1] = tri[5];
    tr.coord4[0] = tri[6];
    tr.coord4[1] = tri[7];

    double a
            = sqrt(pow(tr.coord2[0] - tr.coord1[0], 2)
                   + pow(tr.coord2[1] - tr.coord1[1], 2));
    double b
            = sqrt(pow(tr.coord3[0] - tr.coord2[0], 2)
                   + pow(tr.coord3[1] - tr.coord2[1], 2));
    double c
            = sqrt(pow(tr.coord4[0] - tr.coord3[0], 2)
                   + pow(tr.coord4[1] - tr.coord3[1], 2));

    tr.pTriangle = a + b + c;
    tr.sTriangle
            = sqrt((tr.pTriangle / 2) * (tr.pTriangle / 2 - a)
                   * (tr.pTriangle / 2 - b) * (tr.pTriangle / 2 - c));
    return tr;
}
void geometryWork(string file_in)
{
    double circleMass[10][3] = {0};
    int schet = -1;
    fstream in(file_in, ios::in);
    if (!in.good()) //проверка на открытие файла
    {
        clog << "Couldn't open file.\n";
        exit(1);
    }
    string buffer;
    string digitSymbol = "";
    string circle = "circle";
    int count = 1;
    while (getline(in, buffer)) //запись строки из файла в строку буффер
    {
        cout << count << ") ";
        count++;
        for (unsigned int i = 0; i < buffer.size(); i++) {
            buffer[i] = tolower(buffer[i]); //перевод строки в нижний регистр
        }

        while (buffer.find("  ", 0)
               != (size_t)-1) //поиск и удаление лишних пробелов
        {
            buffer.replace(buffer.find("  ", 0), 2, " ");
        }

        cout << buffer << endl;

        if (buffer.find(circle, 0) != (size_t)-1) {
            Circle o = FindCircle(buffer);
            schet++;
            if (schet > 0) {
                circleMass[schet][0] = o.x;
                circleMass[schet][1] = o.y;
                circleMass[schet][2] = o.r;
            }
            cout << "******************************" << endl;
            cout << "Circle found:" << endl;
            cout << "Area = " << o.square << endl;
            cout << "Perimeter = " << o.perimeter << endl;
            cout << "******************************" << endl;
        } else if (buffer.find("triangle", 0) != (size_t)-1) {
            Triangle tr = FindTriangle(buffer);
            cout << "******************************" << endl;
            cout << "Triangle found:" << endl;
            cout << "Area = " << tr.sTriangle << endl;
            cout << "Perimeter = " << tr.pTriangle << endl;
            cout << "******************************" << endl;
        } else
            cout << "Unknown figure!" << endl;
        buffer.clear();
    }
    in.close();
    if (schet > 0) {
        double a;
        for (int i = 0; i < schet; i++) {
            for (int j = 0; j < schet; j++) {
                a = sqrt(
                        pow(circleMass[j + 1][0] - circleMass[i][0], 2)
                        + pow(circleMass[j + 1][1] - circleMass[i][1], 2));
                if (a == 0)
                    continue;
                if (a <= (circleMass[j + 1][2] + circleMass[i][2]))
                    cout << "Circle " << (i + 1) << " and " << (j + 2)
                         << " intersects" << endl;
            }
        }
    }
}
