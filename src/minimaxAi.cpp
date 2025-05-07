#include "ai.h"
#include "interface.h"

int minimax(char tavola[3][3], int mossa, char maxPlayer){
    char personaggio;
    (mossa%2==0) ? personaggio = 'X' : personaggio = 'O';

    bool done = false;
    int eval = 0;

    for(int i=0; i<3; i++){

        if(done) break;

        for(int j=0; j<3; j++){
            if(tavola[i][j] != ' '){
                tavola[i][j] = personaggio;
                if(has_won(tavola, mossa) && personaggio == maxPlayer){
                    eval = 1;
                    tavola[i][j] = ' ';
                    done = true;
                    break;
                }
                else if(has_won(tavola, mossa)){
                    eval = -1;
                    tavola[i][j] = ' ';
                    done = true;
                    break;
                }
                else{
                    //tavola[i][j] = ' ';
                    mossa++;
                    minimax(tavola, mossa);
                }
            }
        }
    }

    return eval;
}