#include "board.h"
#include <stdio.h>

void printPossibleCharacters()
{
    for(int c = 0; c <= 254; c++)
    {
        printf("%i: '%c'\n", c, c);
    }
}

///
/// Prints the field to the console, using a predefined two-dimensional
/// integer array.
///
void printBoard(struct Board board)
{
    for(int zeile = 8; zeile >= 0; zeile--)
    {
        for(int spalte = 0; spalte <= 8; spalte++)
        {
            switch(board.field[zeile][spalte])
            {
            case 0:
                printf("  | ");
                break;
            case 1:
                printf("%c | ", 177);
                break;
            case 2:
                printf("%c | ", 219);
                break;
            case 3:
                if(zeile == 0)
                {
                    if(spalte != 0)
                    {
                        printf("%c | ", spalte + 48);
                    }
                    else
                    {
                        printf("  | ");
                    }
                }
                else
                {
                    printf("%c | ", zeile + 64);
                }
                break;
            }
        }

        printf("\n");
    }
}
