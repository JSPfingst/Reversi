/**
File which handles all game operations regarding the logic of the game
**/
#include <stdio.h>
#include "board.h"
#include "gamelogic.h"


int CheckIfFieldBlocked (struct Board gameboard,int posZ,int inputPosX) {
    if (gameboard.field[inputPosX][posZ] != 0) {
        return 1;
    }
    else {
        return 0;
    }
}


struct Board CheckIfValidTurn (struct Board gameboard, int inputPosZ, int inputPosX) {
int blocked = CheckIfFieldBlocked(gameboard,inputPosZ,inputPosX);
if (blocked == 0) {
    int directions[8];
    directions[0] = 0;
    CheckIfNearStones(directions,gameboard,inputPosZ,inputPosX);
    gameboard = CheckIfValidDirection(directions,inputPosZ,inputPosX,gameboard);
    }
return gameboard;
}


void CheckIfNearStones (int validDirections[], struct Board gameboard, int posZ, int posX) {


if (gameboard.currentPlayer == 1) {

    if (gameboard.field[posZ+1][posX-1] == 2) {
        validDirections[0] = 1;
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
    if (gameboard.field[posZ+1][posX-1] == 1) {
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
};

struct Board CheckIfValidDirection (int Directions[],int posZ,int posX,struct Board gameboard) {
int directionIsValid[8];
int i;
int valid = 0;
int coordinateZ[8];
int coordinateX[8];

for (int j=0;j<8;j++){
    directionIsValid[j] = 0;
}

if (Directions[0] == 1) {
    i = 2;
    while(posZ+i <= 8 && posX-i >= 1) {


        if(gameboard.field[posZ+i][posX-i] == gameboard.currentPlayer) {
            directionIsValid[0] = 1;
            valid = 1;
            coordinateZ[0] = posZ+i;
            coordinateX[0] = posX-i;
        }
        i++;

    } ;
  }
if (Directions[1] == 1) {
    i = 2;
    while(posZ+i <= 8) {

        if(gameboard.field[posZ+i][posX] == 1) {
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
    while(posZ+i <= 8 && posX+i <= 8) {

        if(gameboard.field[posZ+i][posX+i] == 1) {
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
    while( posX-i >= 1)  {

        if(gameboard.field[posZ][posX-i] == gameboard.currentPlayer) {
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
    while( posX+i <= 8 ) {

        if(gameboard.field[posZ][posX+i] == 2) {
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
    while( posZ-i >= 1 && posX-i >= 1 ) {

        if(gameboard.field[posZ-i][posX-i] == 2) {
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
    while( posZ-i >= 1 ) {

            if(gameboard.field[posZ-i][posX] == 2) {
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
    while( posZ-i >= 1 && posX+i <= 8) {

        if(gameboard.field[posZ-i][posX+i] == 2) {
            directionIsValid[7] = 1;
            valid = 1;
            coordinateZ[7] = posZ-i;
            coordinateX[7] = posX+i;
        }
        i++;
    }
  }


if (valid == 1) {
    if (directionIsValid[0] == 1) {
        i = 0;
        do {
            gameboard.field[posZ+i][posX-i] = gameboard.currentPlayer;
            i++;
        } while (posZ+i <= coordinateZ[0] && posX-i >= coordinateX[0]);
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
        } while (posZ <= coordinateZ[4] && posX-i <= coordinateX[4]);
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

 }
return gameboard;
}
