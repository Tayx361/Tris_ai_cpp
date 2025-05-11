#include "ai.h"
#include "interface.h"

#include <algorithm>

int fine_partita(char tavola[3][3], int mossa, char maxPlayer){
	char personaggio;
	(mossa%2==0) ? personaggio = 'X' : personaggio = 'O';

	if(has_won(tavola, mossa) && personaggio == maxPlayer){
		return 1;	
	}
	else if(has_won(tavola, mossa) && personaggio != maxPlayer){
		return -1;
	}
	else if(is_board_full(tavola)){
		return 0;
	}

	return -2;
}

int minimax(char tavola[3][3], int mossa, char maxPlayer){
	char personaggio;
    (mossa%2==0) ? personaggio = 'X' : personaggio = 'O';
	int eval;
	
	int punteggio = fine_partita(tavola, mossa, maxPlayer);

	if(punteggio != -2){
		return punteggio;	
	}

	if(maxPlayer == personaggio){
		eval = -1;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(tavola[i][j] == ' '){
					tavola[i][j] = personaggio; 
					eval = std::max(eval, minimax(tavola, mossa+1, maxPlayer));
					tavola[i][j] = ' ';
				}
			}
		}
		return eval;
	}
	
	else{
		eval = 1;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(tavola[i][j] == ' '){
					tavola[i][j] = personaggio; 
					eval = std::min(eval, minimax(tavola, mossa+1, maxPlayer));
					tavola[i][j] = ' ';
				}	
			}
		}
		return eval;
	}
}

void minimaxMakeMove(char tavola[3][3], int mossa){
	char personaggio;
	(mossa%2==0) ? personaggio = 'X' : personaggio = 'O';
	
	int migliorPunteggio = -2;
	int migliorX = 0, migliorY = 0;
	int currentScore;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(tavola[i][j] == ' '){
				tavola[i][j] = personaggio;
				currentScore = minimax(tavola, mossa+1, personaggio);
				tavola[i][j] = ' ';
				if(currentScore > migliorPunteggio){
					migliorPunteggio = currentScore;
					migliorX = i;
					migliorY = j;
				}
			}
		}
	}	

	tavola[migliorX][migliorY] = personaggio;
}