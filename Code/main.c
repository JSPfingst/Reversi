#include "board.h"
#include "output.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int endGame = 0;
    int column;
    char row;
    struct Board board = GenerateStartingBoard();
    board.starttime = starttimer();

    while (endGame == 0)
    {
        board.currentPlayer = 1;
        board.currenttime = currenttime(board.starttime);

        printBoard(board);

        column = GetColumn();
        row = GetRow();

        board.field[GetRowIndex(row)][column] = board.currentPlayer;
            }


    return 0;
}
