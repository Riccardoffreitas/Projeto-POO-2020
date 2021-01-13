#include <iostream>
#include "Pieces.h"

piece::piece(bool color, bool state, int position[2])
{
	white = color;
	alive = state;
	oldPos[0] = position[0];
	oldPos[1] = position[1];
}

void piece::move()
{
	oldPos[0] = newPos[0];
	oldPos[1] = newPos[1];
}

void piece::setData(int position[2], bool old)
{
	if(old)
	{
		oldPos[0] = position[0];
		oldPos[1] = position[1];
	}
	else
	{
		newPos[0] = position[0];
		newPos[1] = position[1];
	}
}
