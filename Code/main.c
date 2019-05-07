#include "board.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    char y;
    struct Board board = GenerateStartingBoard();
    printBoard(board);
    x = getX();
    y = getY();

    board.field[GetRowIndex(y)][x] = 1;
    printBoard(board);

    return 0;
}
