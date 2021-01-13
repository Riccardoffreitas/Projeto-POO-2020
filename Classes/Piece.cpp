#include <iostream>
#include "Pieces.h"

piece::piece(bool color, bool state, int posX, int posY, int number)
{
	white = color;
	alive = state;
	position[0] = posX;
	position[1] = posY;
	ID = number;
}

void piece::move(int newPos[2], int board [8][8])
{
	board[position[1]][position[0]] = 0;
	board[newPos[1]][newPos[0]] = ID;
	position[0] = newPos[0];
	position[1] = newPos[1];
}

void piece::setData(int pos[2], bool old)
{
	if(old)
	{
		position[0] = pos[0];
		position[1] = pos[1];
	}
	/*
	else
	{
		newPos[0] = position[0];
		newPos[1] = position[1];
	}
	*/
}
