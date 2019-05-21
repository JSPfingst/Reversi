#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int GetColumn()
{
    int x = 0;

    do{
        printf("X-Koordinate eingeben(1-8):");
        fflush(stdin);
        scanf("%d",&x);
    }while(x > 8 || x < 1);

    return x;
};

char GetRow()
{
    char y;

    do{
        printf("Y-Koordinate eingeben(A-H):");
        fflush(stdin);
        scanf("%c",&y);
    }while(toupper(y) < 65 || toupper(y) > 72);

    return y;
};

int GetUserChoice()
{
    int input = getch();

    if(input >= 49 && input <= 51)
    {
        return input - 48;
    }
    else
    {
        return 0;
    }
}
