// Square 1 = 235 235 208 (RGB)
// Square 2 = 119 147 85 (RGB)
	
#include <SFML/Graphics.hpp>
#include<iostream>

int rows = 8;
int columns = 8;
int oldPosition[2] = {0,0};
int newPosition[2] = {0,0};
int pieceSelected = 0;
bool printOld = false;
bool printNew = false;
bool clickOnce = false;
bool clickTwice = false;

	// Define a posição inicial das peças
int board[8][8] = 
    { 8, 9,10,11,12,10, 9, 8,
      7, 7, 7, 7, 7, 7, 7, 7, 
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      1, 1, 1, 1, 1, 1, 1, 1,
      2, 3, 4, 6, 5, 4, 3, 2};

int main(){
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Xadrez");
    sf::RectangleShape grid[columns][rows];
	sf::Vector2f cellSize(100, 100);
    
    // Carrega os arquivos dos sprites
	sf::Texture texture[12];
	sf::Sprite sprite[12];
	
	texture[0].loadFromFile("images/pawn_white.png");
    texture[1].loadFromFile("images/tower_white.png");
    texture[2].loadFromFile("images/knight_white.png");
    texture[3].loadFromFile("images/bishop_white.png");
    texture[4].loadFromFile("images/queen_white.png");
    texture[5].loadFromFile("images/king_white.png");
    
    texture[6].loadFromFile("images/pawn_black.png");
    texture[7].loadFromFile("images/tower_black.png");
    texture[8].loadFromFile("images/knight_black.png");
    texture[9].loadFromFile("images/bishop_black.png");
    texture[10].loadFromFile("images/queen_black.png");
    texture[11].loadFromFile("images/king_black.png");
        
    for (int i = 0; i < 12; i++){
		texture[i].setSmooth(true);
		sprite[i].setTexture(texture[i]);
	}

	// Processo realizado enquanto a janela fica aberta
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
					
				case sf::Event::MouseButtonPressed:
					if(sf::Mouse::Left == event.mouseButton.button){
						sf::Vector2i localPosition = sf::Mouse::getPosition(window);
						
						if(!printOld){
							oldPosition[0] = localPosition.x/100;
							oldPosition[1] = localPosition.y/100;
							if(board[oldPosition[1]][oldPosition[0]] != 0){
								pieceSelected = board[oldPosition[1]][oldPosition[0]];
								printOld = true;
								printNew = false;
							} else {
								printOld = false;
								printNew = false;
							}		
						} else if (printOld && !printNew){
							newPosition[0] = localPosition.x/100;
							newPosition[1] = localPosition.y/100;
							board[newPosition[1]][newPosition[0]] = pieceSelected;
							board[oldPosition[1]][oldPosition[0]] = 0;
							printOld = false;
							printNew = true;
						}
					}
					
					if(sf::Mouse::Right == event.mouseButton.button){
						printOld = false;
						printNew = false;
					}
					break;
			}
        }
		
        window.clear();
        
		// Desenha todas as informações na janela
		for(int i=0;i<columns;i++){
	        for(int j=0;j<rows;j++){
	            grid[i][j].setSize(cellSize);
	            grid[i][j].setOutlineColor(sf::Color::Black);
	            grid[i][j].setPosition(i*cellSize.x + 0.5f, j*cellSize.y + 0.5f);
	            
	            // Desenha todos os blocos do tabuleiro
				if((i+j)%2 != 0){
	            	grid[i][j].setFillColor(sf::Color(119,147,85));
				} else {
					grid[i][j].setFillColor(sf::Color(235,235,208));
				}
	            	            
				if(printOld){
		        	grid[oldPosition[0]][oldPosition[1]].setFillColor(sf::Color(246,246,105));
				} else if(printNew){
		        	grid[oldPosition[0]][oldPosition[1]].setFillColor(sf::Color(246,246,105));
					grid[newPosition[0]][newPosition[1]].setFillColor(sf::Color(246,246,105));
				}
				
	            
	            window.draw(grid[i][j]);

	            
	            if (board[j][i] != 0){
					sprite[board[j][i] - 1].setPosition(i*cellSize.x + 0.5f, j*cellSize.y + 0.5f);
	            	window.draw(sprite[board[j][i] - 1]);
				}
        	}
    	}
		
        window.display();
    }
    return 0;
}
 
