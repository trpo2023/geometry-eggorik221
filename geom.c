#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Size 30

typedef struct point
{
    double x;
    double y;
} Point;

typedef struct circle
{
    Point p;
    double r;
} Circle;

double getNumber(int* num){
    char curch;
    char temp[Size];
    int cnt = 0;
    char* end;
    while ((curch=getchar()) != ')')
    {
        temp[cnt] = curch;
        if (temp[cnt] == ' '){
            cnt++;
            break;
        }
        if (temp[cnt] == '.'){
            cnt++;
            continue;
        }
        if (temp[cnt] == ','){
            cnt++;
            break;
        }
        if (temp[cnt] == ')'){
            cnt++;
            break;   
        }
        if(temp[cnt] == '('){
            //error
            exit(0);
        }
        if (temp[cnt] != '.' && (!isdigit(temp[cnt]))) {
                //error
                exit(0);
            }
        cnt++;
    }
    *num += cnt+1;
    return strtod(temp,&end);
}

void getPointData(Point* p, int* num){
    p->x = getNumber(num);
    *num -= 1;
    p->y = getNumber(num);
}

void getCircleData(Circle* circle, int* num){
    getPointData(&circle->p, num);
    getchar();
    circle->r = getNumber(num);
}

int main(){
    char str[Size];
    char curch =getchar();
    int symbnum = 0;
    Circle circle;
    do
    {
        if (curch == '('){
            if (strcmp(str, "circle") == 0){
                getCircleData(&circle, &symbnum);
            }
            else
            {
                puts("Error at column 0: expected 'circle'\n");
                exit(0);
            }
        }
        str[symbnum++] = curch;

    } while ((curch = getchar()) != '\n' || curch != EOF);

    return 0;
}