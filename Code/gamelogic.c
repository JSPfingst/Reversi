/**
File which handles all game operations regarding the logic of the game
**/
#include <stdio.h>
#include "board.h"
#include "gamelogic.h"

void AITurn()
{

}

///
/// Checks whether the current player has a valid turn.
///
/// board: A pointer to the games game state structure.
///
/// returns: 1 if at least one valid turn exists, 0 if not.
///
int CheckForValidTurns(struct Board *gameboard, int player)
{
    int turnIsValid = 0;
    int directions[8];
    int validDirections[8];
    int coordinateZ[8];
    int coordinateX[8];

    for(int row = 1; row <= 8; row++)
    {
        for(int column = 0; column <= 8; column++)
        {
            if (gameboard->field[row][column] == 0)
            {
                CheckIfNearStones(directions, *gameboard, row, column);
                turnIsValid = CheckIfValidDirection(directions, validDirections, row, column, gameboard, coordinateZ, coordinateX);

                if(turnIsValid)
                {
                    //At least one valid turn exists. Return 1
                    return turnIsValid;
                }
            }
        }
    }

    //No valid turn found. Return 0
    return 0;
}
///
/// Main function of the gamelogic
/// Checks if the played stone is a valid turn and turns the needed stones
///

struct Board CheckIfValidTurn (struct Board gameboard, int inputPosZ, int inputPosX) {
    int turnIsValid = 0;
    int directions[8];
    int validDirections[8];
    int coordinateZ[8];
    int coordinateX[8];

    if(CheckForValidTurns(&gameboard, gameboard.currentPlayer))
    {
        if (gameboard.field[inputPosZ][inputPosX] == 0) {                                   /// if field not blocked
            CheckIfNearStones(directions, gameboard, inputPosZ, inputPosX);					/// checks if there are enemy stones around it
            turnIsValid = CheckIfValidDirection(directions, validDirections, inputPosZ, inputPosX, &gameboard, coordinateZ, coordinateX); ///checks if the directions are valid
            if(turnIsValid)
            {
                gameboard = PlaceStones(gameboard, inputPosZ, inputPosX, validDirections, coordinateZ, coordinateX); /// turns the stones effected by the new set stone

                //Set the next players turn or end the game, if both players had to pass once
                if(UpdateCurrentPlayer(&gameboard) == 0)
                {
                    gameboard.gameIsOngoing = 0;
                }
            }
        }
    }

    return gameboard;
}
///
/// Checks id there is an enemy stone around the placed stone and returns an array with possible directions as given in
/// possible direction = 1 not possible = 0
///

void CheckIfNearStones (int validDirections[], struct Board gameboard, int posZ, int posX) {


if (gameboard.currentPlayer == 1) {

    if (gameboard.field[posZ+1][posX-1] == 2) {						///Checks for the first stone around if its an enemy stone
        validDirections[0] = 1;                                     ///Sets the direction as possible
    }
    else {
        validDirections[0] = 0;
    }
    if (gameboard.field[posZ+1][posX] == 2) {
        validDirections[1] = 1;
    }
    else {
        validDirections[1] = 0;
    }
    if (gameboard.field[posZ+1][posX+1] == 2) {
        validDirections[2] = 1;
    }
    else {
        validDirections[2] = 0;
    }
    if (gameboard.field[posZ][posX-1] == 2) {
        validDirections[3] = 1;
    }
    else {
        validDirections[3] = 0;
    }
    if (gameboard.field[posZ][posX+1] == 2) {
        validDirections[4] = 1;
    }
    else {
        validDirections[4] = 0;
    }
    if (gameboard.field[posZ-1][posX-1] == 2) {
        validDirections[5] = 1;
    }
    else {
        validDirections[5] = 0;
    }
    if (gameboard.field[posZ-1][posX] == 2) {
        validDirections[6] = 1;
    }
    else {
        validDirections[6] = 0;
    }
    if (gameboard.field[posZ-1][posX+1] == 2) {
        validDirections[7] = 1;
    }
    else {
        validDirections[7] = 0;
    }
}
else {
    if (gameboard.field[posZ+1][posX-1] == 1) {				///Checks for Player 2
        validDirections[0] = 1;
    }
    else {
        validDirections[0] = 0;
    }
    if (gameboard.field[posZ+1][posX] == 1) {
        validDirections[1] = 1;
    }
    else {
        validDirections[1] = 0;
    }
    if (gameboard.field[posZ+1][posX+1] == 1) {
        validDirections[2] = 1;
    }
    else {
        validDirections[2] = 0;
    }
    if (gameboard.field[posZ][posX-1] == 1) {
        validDirections[3] = 1;
    }
    else {
        validDirections[3] = 0;
    }
    if (gameboard.field[posZ][posX+1] == 1) {
        validDirections[4] = 1;
    }
    else {
        validDirections[4] = 0;
    }
    if (gameboard.field[posZ-1][posX-1] == 1) {
        validDirections[5] = 1;
    }
    else {
        validDirections[5] = 0;
    }
    if (gameboard.field[posZ-1][posX] == 1) {
        validDirections[6] = 1;
    }
    else {
        validDirections[6] = 0;
    }
    if (gameboard.field[posZ-1][posX+1] == 1) {
        validDirections[7] = 1;
    }
    else {
        validDirections[7] = 0;
    }
}
}

///
/// function which checks if the possible directions are valid
/// Checks if there is an own stone in the given direction and returns if the direction is valid as 1
///
int CheckIfValidDirection (int Directions[], int directionIsValid[], int posZ, int posX, struct Board *gameboard, int coordinateZ[], int coordinateX[]) {
int i;
int valid = 0;

for (int j=0;j<8;j++){
    directionIsValid[j] = 0;
}

if (Directions[0] == 1) {
    i = 2;
    while(posZ+i <= 8 && posX-i >= 1 && gameboard->field[posZ+i][posX-i] != 0) {  ///Checks for the given direction if there is an own stone
        if(gameboard->field[posZ+i][posX-i] == gameboard->currentPlayer) {
            directionIsValid[0] = 1;
            valid = 1;

			///Saves the coordinates of the last own stone in this direction
            coordinateZ[0] = posZ+i;
            coordinateX[0] = posX-i;
        }
        i++;
    }
  }
if (Directions[1] == 1) {
    i = 2;
    while(posZ+i <= 8 && gameboard->field[posZ+i][posX] != 0) {

        if(gameboard->field[posZ+i][posX] == gameboard->currentPlayer) {
            directionIsValid[1] = 1;
            valid = 1;
            coordinateZ[1] = posZ+i;
            coordinateX[1] = posX;
        }
        i++;
    } ;
  }
if (Directions[2] == 1) {
    i = 2;
    while(posZ+i <= 8 && posX+i <= 8 && gameboard->field[posZ+i][posX+i] != 0) {

        if(gameboard->field[posZ+i][posX+i] == gameboard->currentPlayer) {
            directionIsValid[2] = 1;
            valid = 1;
            coordinateZ[2] = posZ+i;
            coordinateX[2] = posX+i;
        }
        i++;
    }
  }
if (Directions[3] == 1) {
    i = 2;
    while( posX-i >= 1 && gameboard->field[posZ][posX-i] != 0)  {

        if(gameboard->field[posZ][posX-i] == gameboard->currentPlayer) {
            directionIsValid[3] = 1;
            valid = 1;
            coordinateZ[3] = posZ;
            coordinateX[3] = posX-i;
        }
            i++;

    }
  }
if (Directions[4] == 1) {
    i = 2;
    while( posX+i <= 8 && gameboard->field[posZ][posX+i] != 0) {

        if(gameboard->field[posZ][posX+i] == gameboard->currentPlayer) {
            directionIsValid[4] = 1;
            valid = 1;
            coordinateZ[4] = posZ;
            coordinateX[4] = posX+i;
        }
        i++;
    }
  }
if (Directions[5] == 1) {
    i = 2;
    while( posZ-i >= 1 && posX-i >= 1 && gameboard->field[posZ-i][posX-i] != 0) {

        if(gameboard->field[posZ-i][posX-i] == gameboard->currentPlayer) {
            directionIsValid[5] = 1;
            valid = 1;
            coordinateZ[5] = posZ-i;
            coordinateX[5] = posX-i;
        }
        i++;
    }
  }
if (Directions[6] == 1) {
    i = 2;
    while( posZ-i >= 1 && gameboard->field[posZ-i][posX] != 0) {

            if(gameboard->field[posZ-i][posX] == gameboard->currentPlayer) {
                directionIsValid[6] = 1;
                valid = 1;
                coordinateZ[6] = posZ-i;
                coordinateX[6] = posX;
            }
            i++;
    }
  }
if (Directions[7] == 1) {
    i = 2;
    while( posZ-i >= 1 && posX+i <= 8 && gameboard->field[posZ-i][posX+i] != 0) {

        if(gameboard->field[posZ-i][posX+i] == gameboard->currentPlayer) {
            directionIsValid[7] = 1;
            valid = 1;
            coordinateZ[7] = posZ-i;
            coordinateX[7] = posX+i;
        }
        i++;
    }
  }
    return valid;
}
///
/// Switches all stones between the set stone and the last own stone in the valid directions to the colour of the current player
///
struct Board PlaceStones(struct Board gameboard, int posZ, int posX, int directionIsValid[], int coordinateZ[], int coordinateX[])
{
    int i = 0;

    if (directionIsValid[0] == 1) {   ///gets a valid directions
        i = 0;
        do {
            gameboard.field[posZ+i][posX-i] = gameboard.currentPlayer;
            i++;
        } while (posZ+i <= coordinateZ[0] && posX-i >= coordinateX[0]);   ///gets the coordinates of the last own stone
    }

    if (directionIsValid[1] == 1) {
        i = 0;
        do {
            gameboard.field[posZ+i][posX] = gameboard.currentPlayer;
            i++;
        } while (posZ+i <= coordinateZ[1] && posX >= coordinateX[1]);
    }

    if (directionIsValid[2] == 1) {
        i = 0;
        do {
            gameboard.field[posZ+i][posX+i] = gameboard.currentPlayer;
            i++;
        } while (posZ+i <= coordinateZ[2] && posX+i <= coordinateX[2]);
    }

    if (directionIsValid[3] == 1) {
        i = 0;
        do {
            gameboard.field[posZ][posX-i] = gameboard.currentPlayer;
            i++;
        } while (posZ <= coordinateZ[3] && posX-i >= coordinateX[3]);
    }

    if (directionIsValid[4] == 1) {
        i = 0;
        do {
            gameboard.field[posZ][posX+i] = gameboard.currentPlayer;
            i++;
        } while (posZ <= coordinateZ[4] && posX+i <= coordinateX[4]);
    }

    if (directionIsValid[5] == 1) {
        i = 0;
        do {
            gameboard.field[posZ-i][posX-i] = gameboard.currentPlayer;
            i++;
        } while (posZ-i >= coordinateZ[5] && posX-i >= coordinateX[5]);
    }

    if (directionIsValid[6] == 1) {
        i = 0;
        do {
            gameboard.field[posZ-i][posX] = gameboard.currentPlayer;
            i++;
        } while (posZ-i >= coordinateZ[6] && posX >= coordinateX[6]);
    }

    if (directionIsValid[7] == 1) {
        i = 0;
        do {
            gameboard.field[posZ-i][posX+i] = gameboard.currentPlayer;
            i++;
        } while (posZ-i >= coordinateZ[7] && posX+i <= coordinateX[7]);
    }

    return gameboard;
}
