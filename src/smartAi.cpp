#include "ai.h"
#include "interface.h"

void win(char tavola[3][3], int mossa){ 
  char personaggio;
  //bool did_win = false;

  if (mossa % 2 == 0) {
      personaggio = 'X';
  } else {
      personaggio = 'O';
  }

  for(int i=0; i<3; i++){
    for(int j=0; j<3;j++){
      if(tavola[i][j] == ' '){
        tavola[i][j] = personaggio;
        if(!has_won(tavola, mossa)){
          tavola[i][j] = ' ';
        }
        else{
          return;
        }
      }   
    }
}

}

void prevent_loss(char tavola[3][3], int mossa, bool &has_changed){
  char avversario;

  if (mossa % 2 == 0) {
      avversario = 'O';
  } else {
      avversario = 'X';
  }

  char personaggio;

  if (mossa % 2 == 0) {
      personaggio = 'X';
  } else {
      personaggio = 'O';
  }

  for(int i=0; i<3; i++){
    for(int j=0; j<3;j++){
      if(tavola[i][j] == ' '){

        tavola[i][j] = avversario;
        
        if(!has_won(tavola, (mossa + 1))){
          tavola[i][j] = ' ';
        }

        else{
          tavola[i][j] = personaggio;
          has_changed = true;
          return;
        }
      }
    }
  }
}

void smartAi_choose_move(char tavola[3][3], int mossa){
  char personaggio;

  if (mossa % 2 == 0) {
      personaggio = 'X';
  } else {
      personaggio = 'O';
  }
 
  win(tavola, mossa);

  if(!has_won(tavola, mossa)){
    bool has_changed = false;
    prevent_loss(tavola, mossa, has_changed);
    if(!has_changed){
      if(tavola[1][1] == ' '){
        tavola[1][1] = personaggio; 
      }
      else{
        random_choose_move(tavola, mossa);
      }
    }
  }
}
