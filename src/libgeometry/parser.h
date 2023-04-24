#pragma once
#include <stdio.h>
#include <math.h> 
#include <string.h>
#include <stdlib.h>

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