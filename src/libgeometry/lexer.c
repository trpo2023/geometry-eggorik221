#include <ctype.h>
#include <stdlib.h>

#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

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

void getPointData(Point* p, int* num)
{
    p->x = getNumber(num);
    *num -= 1;
    p->y = getNumber(num);
    *num -= 1;
}