#include "board.h"
#include <conio.h>
#include <ctype.h>
#include <time.h>

///
/// Create a standard Reversi board for testing purposes.
///
/// board: A pointer to the game state structure of the game.
///
void GenerateStartingBoard(struct Board *board)
{
    //Set the default values for the boards members
    board->updated = 1;
    board->gameIsOngoing = 1;
    board->currentPlayer = 1;
    board->scorePlayer1 = 2;
    board->scorePlayer2 = 2;
    board->starttime = GetCurrentTime();
    board->time = 0;
    board->isPaused = 0;
    board->pauseDuration = 0;
    board->selectedRow = 1;
    board->selectedColumn = 1;

    /*
     * The starting point of the Reversi board is on the bottom left,
     * therefore the rows are iterated decrementally.
     */
    for(int row = 1; row <= 8; row++)
    {
        for(int column = 1; column <= 8; column++)
        {
            board->field[row][column] = 0;
        }
    }

    //Place the four default stones.
    board->field[4][4] = 1;
    board->field[4][5] = 2;
    board->field[5][4] = 2;
    board->field[5][5] = 1;
};

///
/// Updates the currentPlayer member of the given Board structure.
///
/// board: The current game state of the game.
///
/// returns: The game state, with the updated currentPlayer member.
///
void UpdateCurrentPlayer(struct Board *board)
{
    if(board->currentPlayer == 1)
    {
        board->currentPlayer = 2;
    }
    else if(board->currentPlayer == 2)
    {
        board->currentPlayer = 1;
    }
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
