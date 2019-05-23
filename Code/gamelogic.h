#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

struct Board CheckIfValidDirection (int Directions[],int posZ,int posX, struct Board gameboard);
void CheckIfNearStones (int validDirections[], struct Board gameboard, int posZ, int posX);
struct Board CheckIfValidTurn (struct Board gameboard, int inputPosZ, int inputPosX);
int CheckIfFieldBlocked (struct Board gameboard,int posZ,int inputPosX);

#endif // GAMELOGIC_H_INCLUDED
