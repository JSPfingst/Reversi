#include "board.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    char y;
    struct Board board = GenerateStartingBoard();
    printBoard(board);
    getX();
    getY();

    return 0;
}
