#include "board.h"

///
/// Create a standard Reversi board for testing purposes.
///
struct Board GenerateStartingBoard()
{
    struct Board board;
    for(int zeile = 8; zeile >= 0; zeile--)
    {
        for(int spalte = 0; spalte <= 8; spalte++)
        {
            if(zeile == 0)
            {
                board.field[zeile][spalte] = 3;
            }
            else
            {
                if(spalte == 0)
                {
                    board.field[zeile][spalte] = 3;
                }
                else
                {
                    board.field[zeile][spalte] = 0;
                }
            }
        }
    }
    board.field[4][4] = 1;
    board.field[4][5] = 2;
    board.field[5][5] = 1;
    board.field[5][4] = 2;

    return board;
};
