#include "board.h"
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

long starttimer()
{
    time_t now;
	time(&now);
	return now;
}

long currenttime(long starttime)
{
    long gametime;
    time_t now;
	time(&now);
	gametime = now - starttime;
	return gametime;
}

