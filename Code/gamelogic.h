#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

int CheckForValidTurns(struct Board *gameboard, int player);
struct Board CheckIfValidTurn (struct Board gameboard, int inputPosZ, int inputPosX);
void CheckIfNearStones (int validDirections[], struct Board gameboard, int posZ, int posX);
int CheckIfValidDirection (int Directions[], int directionIsValid[], int posZ, int posX, struct Board *gameboard, int coordinateZ[], int coordinateX[]);
struct Board PlaceStones(struct Board board, int posZ, int posX, int directionIsValid[], int coordinateZ[], int coordinateX[]);

#endif // GAMELOGIC_H_INCLUDED
