class piece
{
	protected:
		bool white, alive;
		int position[2];
		int ID;
	public:
		void move(int newPos[2], int board [8][8]);
		void setData(int pos[2], bool old);
		piece(bool color, bool state, int posX, int posY, int number);
};

class pawn : public piece
{
	public:
		
		pawn(bool color, bool state, int posX, int posY, int number);
		
		int validMovement (int oldPos[2], int newPos[2], int board[][8]);
};

class king : public piece
{
	public:
	 	
		king(bool color, bool state, int posX, int posY, int number);
		
		int validMovement (int oldPos[2], int newPos[2], int board[][8]);
};
		
