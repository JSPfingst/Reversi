#include <stdio.h>

void printPossibleCharacters()
{
    for(int c = 0; c <= 254; c++)
    {
        printf("%i: '%c'\n", c, c);
    }
}

void printBoard()
{
    ///
    /// Create a standard Reversi board for testing purposes.
    ///
    int board[9][9];
    for(int zeile = 8; zeile >= 0; zeile--)
    {
        for(int spalte = 0; spalte <= 8; spalte++)
        {
            if(zeile == 0)
            {
                board[zeile][spalte] = 3;
            }
            else
            {
                if(spalte == 0)
                {
                    board[zeile][spalte] = 3;
                }
                else
                {
                    board[zeile][spalte] = 0;
                }
            }
        }
    }
    board[4][4] = 1;
    board[4][5] = 2;
    board[5][5] = 1;
    board[5][4] = 2;

    ///
    /// Prints the field to the console, using a predefined two-dimensional
    /// integer array.
    ///
    for(int zeile = 8; zeile >= 0; zeile--)
    {
        for(int spalte = 0; spalte <= 8; spalte++)
        {
            switch(board[zeile][spalte])
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
