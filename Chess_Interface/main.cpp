// Case 1 = 235 235 208 (RGB)
// Case 2 = 119 147 85 (RGB)
// Case em destaque = 246 246 105 (RGB)
	
#include "../Classes/Interface.h"	
#include <SFML/Graphics.hpp>
#include <iostream>

#define rows 8
#define columns 8

// Define a posição inicial das peças
int board[8][8] = 							//IDEIA : Podemos iniciar o board em branco e fazer com que as 
    { 81, 91,101,111,121,102, 92, 82,		//classes das pecas editem a variavel board colocando-se em 
      71, 72, 73, 74, 75, 76, 77, 78, 		//cada casa. Assim podemos fazer as verificacoes de validade 
      0, 0, 0, 0, 0, 0, 0, 0,				//na propria classe da peca e caso seja valido realizamos o
      0, 0, 0, 0, 0, 0, 0, 0,				//movimento
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      11, 12, 13, 14, 15, 16, 17, 18,
      21, 31, 41, 51, 61, 42, 32, 22};	
      
/* OLD BOARD ======================================================
   
int board[8][8] = 						
    { 8, 9,10,11,12,10, 9, 8,	
      7, 7, 7, 7, 7, 7, 7, 7, 	
      0, 0, 0, 0, 0, 0, 0, 0,			
      0, 0, 0, 0, 0, 0, 0, 0,			
      0, 0, 0, 0, 0, 0, 0, 0,           
      0, 0, 0, 0, 0, 0, 0, 0,           
      1, 1, 1, 1, 1, 1, 1, 1,   
      2, 3, 4, 5, 6, 4, 3, 2};	  
=============================================================== */ 

int main(){
	
	Interface Chess_Window;
	
	sf::RenderWindow window(sf::VideoMode(rows*100, columns*100), "Xadrez");
    sf::RectangleShape grid[rows][columns];
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
					
				case sf::Event::MouseButtonPressed:		//espera por um clique

					if(sf::Mouse::Left == event.mouseButton.button){	//botao esquerdo
						
						sf::Vector2i localPosition = sf::Mouse::getPosition(window); // Pega a posição do mouse referente a janela
						Chess_Window.Event_Left(localPosition.x, localPosition.y, board);   // Chama a rotina responsável pelos eventos do clique esquerdo
						
						
					} else if(sf::Mouse::Right == event.mouseButton.button){ // botao direito
						
						Chess_Window.Event_Right();	 // Chama a rotina responsável pelos eventos do clique direito
					
					}
					break;
			}
        }
		
        window.clear();
        
		// Desenha todas as informações na janela
		for(int i=0;i<rows;i++){
	        for(int j=0;j<columns;j++){
	            grid[i][j].setSize(cellSize);
	            grid[i][j].setOutlineColor(sf::Color::Black);
	            grid[i][j].setPosition(i*cellSize.x + 0.5f, j*cellSize.y + 0.5f);
	            
	            // Desenha todos os blocos do tabuleiro
				if((i+j)%2 != 0){
	            	grid[i][j].setFillColor(sf::Color(119,147,85));
				} else {
					grid[i][j].setFillColor(sf::Color(235,235,208));
				}
	            
				// Destaca as casas selecionadas para indicar o movimento	            
				if(Chess_Window.printOld){
		        	grid[Chess_Window.oldPos[0]][Chess_Window.oldPos[1]].setFillColor(sf::Color(246,246,105));
				} else if(Chess_Window.printNew){
		        	grid[Chess_Window.oldPos[0]][Chess_Window.oldPos[1]].setFillColor(sf::Color(246,246,105));
					grid[Chess_Window.newPos[0]][Chess_Window.newPos[1]].setFillColor(sf::Color(246,246,105));
				}
				
	            window.draw(grid[i][j]);

	            // Coloca os sprites nas posições do tabuleiro conforme a matriz board
	            if (board[j][i] != 0){
					sprite[(board[j][i])/10 - 1].setPosition(i*cellSize.x + 0.5f, j*cellSize.y + 0.5f);
	            	window.draw(sprite[(board[j][i])/10 - 1]);
				}
        	}
    	}
		
		// Exibe tudo realizado pelo comando window.draw na tela
        window.display();
    }
    
    return 0;
}
