#include "ai.h"
#include "interface.h"
#include <cstdlib>

void random_choose_move(char tavola[3][3], int mossa){
  int coordinate[2];
  do{
    coordinate[0] = rand() % 3;
    coordinate[1] = rand() % 3;
    // std::cout << coordinate[0] << " " << coordinate[1] << std::endl;
  }while(!is_legal(tavola, coordinate));

  if(mossa % 2 == 0){
    tavola[coordinate[0]][coordinate[1]] = 'X';
  }
  else{
    tavola[coordinate[0]][coordinate[1]] = 'O';
  }

}
