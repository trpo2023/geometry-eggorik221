#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 30

typedef struct point {
    double x;
    double y;
} Point;

typedef struct circle {
    Point p;
    double r;
} Circle;

void errPrint(int num, int errnum)
{
    for (int i = 0; i < num; i++)
        putchar(' ');
    putchar('^');
    printf("\n");
    switch (errnum) {
    case 1:
        printf("Error at column 0: expected 'circle'\n");
        exit(0);
        break;

    case 2:
        printf("Error at column %d: expected '<double>'\n", num + 1);
        exit(0);
        break;
    case 3:
        printf("Error at column %d: expected ')'\n", num);
        exit(0);
        break;

    case 4:
        printf("Error at column %d: unexpected token\n", num);
        exit(0);
        break;
    case 5:
        printf("Error at column %d: excepcted '(' in line\n", num);
        exit(0);
        break;
    }
}

double getNumber(int* num)
{
    char current_ch;
    char temp[SIZE];
    int cnt = 0;
    char* end;
    while ((current_ch = getchar()) != ')') {
        temp[cnt] = current_ch;
        if (temp[cnt] == ' ') {
            cnt++;
            break;
        }
        if (temp[cnt] == '.') {
            cnt++;
            continue;
        }
        if (temp[cnt] == ',') {
            cnt++;
            cnt++;
            getchar();
            break;
        }
        if (temp[cnt] == ')') {
            cnt++;
            break;
        }
        if (temp[cnt] == '(') {
            errPrint(*num + cnt, 3);
            exit(0);
        }
        if (temp[cnt] != '.' && (!isdigit(temp[cnt]))) {
            errPrint(*num + cnt, 2);
            exit(0);
        }
        cnt++;
    }
    *num += cnt + 1;
    return strtod(temp, &end);
}

void getPointData(Point* p, int* num)
{
    p->x = getNumber(num);
    *num -= 1;
    p->y = getNumber(num);
    *num -= 1;
}

void tokenControl(int* num)
{
    char current_ch = getchar();
    if (current_ch != '\n') {
        if (current_ch != ' ') {
            errPrint(*num, 4);
            exit(0);
        } else {
            if (getchar() == '\n')
                exit(0);
            else {
                *num += 1;
                errPrint(*num, 4);
            }
        }
    }
}

void getCircleData(Circle* circle, int* num)
{
    getPointData(&circle->p, num);
    circle->r = getNumber(num);
    tokenControl(num);
}

void printInfo(Circle* circle)
{
    printf("circle(%f %f, %f)\n", circle->p.x, circle->p.y, circle->r);
    double perimeter = 2 * M_PI * circle->r;
    double area = M_PI * circle->r * circle->r;
    printf("perimeter = %f\n", perimeter);
    printf("area = %f\n", area);
}

void countingCircleInfo(double *perimetr, double *area, double r)
{
	*perimetr = 2 * M_PI * r;
	*area = M_PI * r * r;
}

int main()
{
    char str[SIZE];
    char current_ch;
    int symbnum = 0;
    char stop_ch = '(';
    Circle circle;
    do {
        current_ch = getchar();

        if (current_ch == '(') {
            if (strcmp(str, "circle") == 0) {
                str[symbnum++] = current_ch;
                getCircleData(&circle, &symbnum);
                printInfo(&circle);
                exit(0);
            } else {
                errPrint(0, 1);
            }
        }
        str[symbnum++] = current_ch;
        if (symbnum > 6 && (strchr(str, stop_ch) == NULL))
            errPrint(0, 5);
        if (current_ch == '\n' || current_ch == EOF)
            break;
    } while (1);

    if (symbnum < 6 || current_ch == '\n')
        errPrint(0, 1);
    return 0;
}
