#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

struct Board
{
    int field[9][9];
    int currentPlayer;
    int scorePlayer1, scorePlayer2;
    int time;
};

struct Board GenerateStartingBoard();

#endif // BOARD_H_INCLUDED
