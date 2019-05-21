#include "board.h"
#include <conio.h>
#include <ctype.h>
#include <time.h>

///
/// Create a standard Reversi board for testing purposes.
///
/// returns: An instance of the Board structure containing
///          a new Reversi field.
///
struct Board GenerateStartingBoard()
{
    struct Board board;

    board.currentPlayer = 1;
    board.time = 0;
    board.pauseDuration = 0;
    board.isPaused = 0;
    board.selectedRow = 1;
    board.selectedColumn = 1;

    /*
     * The starting point of the Reversi board is on the bottom left,
     * therefore the rows are iterated decrementally.
     */
    for(int row = 8; row >= 0; row--)
    {
        for(int column = 0; column <= 8; column++)
        {
            if(row == 0)
            {
                board.field[row][column] = 3;
            }
            else
            {
                if(column == 0)
                {
                    board.field[row][column] = 3;
                }
                else
                {
                    board.field[row][column] = 0;
                }
            }
        }
    }

    //Place the four default stones.
    board.field[4][4] = 1;
    board.field[4][5] = 2;
    board.field[5][5] = 1;
    board.field[5][4] = 2;

    return board;
};

///
/// Updates the currentPlayer member of the given Board structure.
///
/// board: The current game state of the game.
///
/// returns: The game state, with the updated currentPlayer member.
///
struct Board UpdateCurrentPlayer(struct Board board)
{
    if(board.currentPlayer == 1)
    {
        board.currentPlayer = 2;
    }
    else if(board.currentPlayer == 2)
    {
        board.currentPlayer = 1;
    }

    return board;
}

///
/// Determines the array index of the row based on its label.
///
/// row: The character label of the row.
///
/// returns: The array index of the row.
///
int GetRowIndex(char row)
{
    int rowIndex = (int)(toupper(row)) - 64;

    return rowIndex;
}

///
/// Returns the current time in seconds.
///
/// returns: The current time in seconds.
///
long GetCurrentTime()
{
    time_t now;
	time(&now);
	return now;
}

///
/// Pauses the game and returns the duration of the pause in seconds,
/// when the game is resumed.
///
/// returns: The duration of the pause in seconds.
///
int PauseGame()
{
    time_t pauseStart = time(&pauseStart), pauseEnd = 0;
    int key = 0;

    while(pauseEnd == 0)
    {
        if(kbhit())
        {
            key = getch();

            if(key == 79)
            {
                return -1;
            }

            //Game unpaused => get the end time of the pause
            if(key == 112)
            {
                pauseEnd = time(&pauseEnd);
            }
        }
    }

    //Return the duration of the pause
    return pauseEnd - pauseStart;
}
