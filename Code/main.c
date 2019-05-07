#include "board.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct Board board = GenerateStartingBoard();

    printBoard(board);

    return 0;
}
