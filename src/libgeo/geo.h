#pragma once
#include <math.h>

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#define Pi 3.1415
using namespace std;

struct Circle {
    double x;
    double y;
    double r; //радиус
    double square;
    double perimeter;
};

struct Triangle {
    double coord1[2];
    double coord2[2];
    double coord3[2];
    double coord4[2];
    double sTriangle;
    double pTriangle;
};

void geometryWork(string file_in);