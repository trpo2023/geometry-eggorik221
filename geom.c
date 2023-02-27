#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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



int main(){
    char str[Size];
    char curch =getchar();
    int symbnum = 0;
    Circle circle;
    do
    {
        if (curch == '('){
            if (strcmp(str, "circle") == 0){
                //Get info about circle
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