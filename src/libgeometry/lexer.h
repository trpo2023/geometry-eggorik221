#pragma once
#include <stdio.h>

#include <libgeometry/parser.h>

void errPrint(int num, int errnum);
void getPointData(Point* p, int* num);
void tokenControl(int* num);
double getNumber(int* num);