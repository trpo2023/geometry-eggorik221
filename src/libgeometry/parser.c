#include <stdio.h>

#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

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

void parser(void)
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
}