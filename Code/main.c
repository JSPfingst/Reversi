#include "board.h"
#include "output.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Board board = GenerateStartingBoard();

    board.field[GetRowIndex('A')][1] = 1;

    printBoard(board);

    return 0;
}
