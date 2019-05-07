#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#define HEIGHT 8
#define WIDTH 8

///
/// The Board struct represents the current game state.
/// It contains the field, the score of each player, whose
/// turn it and how much time has passed.
///
struct Board
{
    int field[9][9];
    int currentPlayer;
    int scorePlayer1, scorePlayer2;
    int time;
};

struct Board GenerateStartingBoard();
int GetRowIndex(char row);

#endif // BOARD_H_INCLUDED
