#include "Interface.h"
#include "Pieces.h"

//PEAO BRANCO
pawn WP1(true, true, 0, 6, 11);
pawn WP2(true, true, 1, 6, 12);
pawn WP3(true, true, 2, 6, 13);
pawn WP4(true, true, 3, 6, 14);
pawn WP5(true, true, 4, 6, 15);
pawn WP6(true, true, 5, 6, 16);
pawn WP7(true, true, 6, 6, 17);
pawn WP8(true, true, 7, 6, 18);

//PEAO PRETO
pawn BP1(false, true, 0, 1, 71);
pawn BP2(false, true, 1, 1, 72);
pawn BP3(false, true, 2, 1, 73);
pawn BP4(false, true, 3, 1, 74);
pawn BP5(false, true, 4, 1, 75);
pawn BP6(false, true, 5, 1, 76);
pawn BP7(false, true, 6, 1, 77);
pawn BP8(false, true, 7, 1, 78);

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
					WP1.move(newPos, board);
					return 0;
			}
			break;
		case 12:
			if (WP2.validMovement(oldPos, newPos, board)){
					WP2.move(newPos, board);
					return 0;
			}
			break;
		case 13:
			if (WP3.validMovement(oldPos, newPos, board)){
					WP3.move(newPos, board);
					return 0;
			}
			break;
		case 14:
			if (WP4.validMovement(oldPos, newPos, board)){
					WP4.move(newPos, board);
					return 0;
			}
			break;
		case 15:
			if (WP5.validMovement(oldPos, newPos, board)){
					WP5.move(newPos, board);
					return 0;
			}
			break;
		case 16:
			if (WP6.validMovement(oldPos, newPos, board)){
					WP6.move(newPos, board);
					return 0;
			}
			break;
		case 17:
			if (WP7.validMovement(oldPos, newPos, board)){
					WP7.move(newPos, board);
					return 0;
			}
			break;
		case 18:
			if (WP8.validMovement(oldPos, newPos, board)){
					WP8.move(newPos, board);
					return 0;
			}
			break;
		
		//TORRE BRANCA
		case 21:
			return 1;
			break;
			
		//PEAO PRETO
		case 71:
			if (BP1.validMovement(oldPos, newPos, board)){
				BP1.move(newPos, board);
				return 0;
			}
			break;
		case 72:
			if (BP2.validMovement(oldPos, newPos, board)){
				BP2.move(newPos, board);
				return 0;
			}
			break;
		case 73:
			if (BP3.validMovement(oldPos, newPos, board)){
				BP3.move(newPos, board);
				return 0;
			}
			break;
		case 74:
			if (BP4.validMovement(oldPos, newPos, board)){
				BP4.move(newPos, board);
				return 0;
			}
			break;
		case 75:
			if (BP5.validMovement(oldPos, newPos, board)){
				BP5.move(newPos, board);
				return 0;
			}
			break;
		case 76:
			if (BP6.validMovement(oldPos, newPos, board)){
				BP6.move(newPos, board);
				return 0;
			}
			break;
		case 77:
			if (BP7.validMovement(oldPos, newPos, board)){
				BP7.move(newPos, board);
				return 0;
			}
			break;
		case 78:
			if (BP8.validMovement(oldPos, newPos, board)){
				BP8.move(newPos, board);
				return 0;
			}
			break;
			
		//TORRE PRETA
		case 81:
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

