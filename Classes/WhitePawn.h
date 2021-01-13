#include "Pieces.h"
class whitePawn : public piece
{
	public:
		
		whitePawn();
		
		int validMovement (int oldX, int oldY, int newX, int newY);
};
