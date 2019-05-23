#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED

void CheckIfValidDirection (int Directions[8],int posZ,int posX, struct Board gameboard);
int CheckIfNearStones (struct Board gameboard, int posZ, int posX);
void CheckIfValidTurn (struct Board gameboard, int inputPosZ, int inputPosX);
int CheckIfFieldBlocked (struct Board gameboard,int posZ,int inputPosX);

#endif // GAMELOGIC_H_INCLUDED
