#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;
 
int main()
{
    string file_in, word_in;
    char buffer[100];
    string s;

    cout << "Input file name: ";
    cin >> file_in;
    
    ifstream in(file_in.c_str(), ios::in);
    if (!in.good())
    {
        clog << "Couldn't open file.\n";
        exit(1);
    }
    
    while(in.getline(buffer, 100)) 
    {
            if(strcasestr(buffer, "circle"))
                cout << buffer << endl;
            if(strcasestr(buffer, "triangle"))
                cout << buffer << endl;
            if(strcasestr(buffer, "polygon"))
                cout << buffer << endl;   
    }
    in.close();
 
    return 0;
}