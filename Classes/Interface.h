class Interface{
	private:
		int pieceSelected;
	public:
		bool printOld, printNew;
		int oldPos[2], newPos[2];
		interface();
		void Event_Left(int x, int y, int board[][8]);
		void Event_Right();
};
