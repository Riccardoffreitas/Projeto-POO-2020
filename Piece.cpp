#include <iostream>
#include "Pieces.h"

piece::piece(bool color, bool state, int position[2])
{
	white = color;
	alive = state;
	oldPosition[0] = position[0];
	oldPosition[1] = position[1];
}

void piece::move()
{
	oldPosition[0] = newPosition[0];
	oldPosition[1] = newPosition[1];
}

void piece::setData(int position[2], bool old)
{
	if(old)
	{
		oldPosition[0] = position[0];
		oldPosition[1] = position[1];
	}
	else
	{
		newPosition[0] = position[0];
		newPosition[1] = position[1];
	}
}
