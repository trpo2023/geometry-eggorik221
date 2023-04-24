#include <math.h>
#include <stdlib.h>

#include <libgeometry/calcul.h>

double calcul_perimetr(Circle* circle)
{
    double perimeter = 2 * M_PI * circle->r;
    return perimeter;
}

double calcul_area(Circle* circle)
{
    double area = M_PI * circle->r * circle->r;
    return area;
}

void get_circle_demmision(Circle* circle)
{
    circle->perimeter = calcul_perimetr(circle);
    circle->area = calcul_area(circle);
}