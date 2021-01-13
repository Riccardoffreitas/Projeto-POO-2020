class piece
{
	protected:
		bool white, alive;
		int oldPos[2];
		int newPos[2];
	public:
		void move();
		void setData(int position[2], bool old);
		piece(bool color, bool state, int position[2]);
};

class whitePawn : public piece
{
	public:
		
		whitePawn(bool color, bool state, int position[2]);
		
		int validMovement (int oldPos[2], int newPos[2], int board[][8]);
};
