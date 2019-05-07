#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int getX()
{
    int x = 0;
    do{
    printf("X-Koordinate eingeben(1-8):");
    fflush(stdin);
    scanf("%d",&x);
    }while(x > 8 || x < 1);

    return x;
};

char getY()
{
    char y;
    do{
    printf("Y-Koordinate eingeben(A-H):");
    fflush(stdin);
    scanf("%c",&y);
    }while(y < 97 || y > 104);

    return y;
};
