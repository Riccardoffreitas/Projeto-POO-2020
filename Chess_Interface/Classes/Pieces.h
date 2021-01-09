class piece
{
	protected:
		bool white, alive;
		int oldPosition[2];
		int newPosition[2];
	public:
		void move();
		void setData(int position[2], bool old);
		piece(bool color, bool state, int position[2]);
};
