#include "Interface.h"
#include "Pieces.h"

int WP1pos[2] = {0,7};	//nao consegui inicializar a classe sem criar uma variavel pra posical inicial

whitePawn WP1(true, true, WP1pos);
whitePawn WP2(true, true, WP1pos);
whitePawn WP3(true, true, WP1pos);
whitePawn WP4(true, true, WP1pos);
whitePawn WP5(true, true, WP1pos);
whitePawn WP6(true, true, WP1pos);
whitePawn WP7(true, true, WP1pos);
whitePawn WP8(true, true, WP1pos);

int movementValid(int oldPos[2], int newPos[2], int board[8][8]){

	//nao deixa comer pecas da sua cor
	if (board[newPos[1]][newPos[0]] != 0){
		if ((board[oldPos[1]][oldPos[0]] <= 61 && board[newPos[1]][newPos[0]] <=61) || (board[oldPos[1]][oldPos[0]] >= 71 && board[newPos[1]][newPos[0]] >= 71) ){
			return 0;
		}
	}
	
	switch (board[oldPos[1]][oldPos[0]]){				
		//PEAO BRANCO
		case 11:
			if (WP1.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 12:
			if (WP2.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 13:
			if (WP3.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 14:
			if (WP4.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 15:
			if (WP5.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 16:
			if (WP6.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 17:
			if (WP7.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
		case 18:
			if (WP8.validMovement(oldPos, newPos, board)){
					return 1;
			}
			break;
			
		//PEAO PRETO
		case 71:
			return 1;
			break;
	}

return 0; // Caso nao valide o movimento, retorna 0 para que nao execute
}

Interface::interface(){
	printOld = false;
	printNew = false;
	pieceSelected = 0;
	oldPos[0] = 0;
	oldPos[1] = 0;
	newPos[0] = 0;
	newPos[1] = 0;
}

void Interface::Event_Left(int x, int y, int board[][8]){
	if(!printOld){		//se print old false
		oldPos[0] = x/100;	//captura a posicao do clique
		oldPos[1] = y/100;
		if(board[oldPos[1]][oldPos[0]] != 0){		//se nao for zero (casa vazia) seleciona a peca
			pieceSelected = board[oldPos[1]][oldPos[0]];
			printOld = true;					//seta printOld para que no proximo evento de botao esquerdo não entre no mesmo escopo
			printNew = false;
		} else {
			printOld = false;					// se for uma casa vazia, não faz nada
			printNew = false;
		}		
	} else if (printOld && !printNew){			//caso uma peca esteja selecionada
		newPos[0] = x/100; 	//captura a posicao de destino
		newPos[1] = y/100;
		
		if(movementValid(oldPos,newPos,board)){
			board[oldPos[1]][oldPos[0]] = 0;
			board[newPos[1]][newPos[0]] = pieceSelected;
			printOld = false;
			printNew = true;
		}
	}
}

void Interface::Event_Right(){
	printOld = false;
	printNew = false;
}

