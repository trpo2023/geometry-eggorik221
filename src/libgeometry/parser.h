#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct point {
    double x;
    double y;
} Point;

typedef struct circle {
    Point p;
    double r;
    double perimeter;
    double area;
} Circle;

void getCircleData(Circle* circle, int* num);
void printInfo(Circle* circle);
void parser(void);