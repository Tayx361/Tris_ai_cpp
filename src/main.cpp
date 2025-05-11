#include <iostream>
#include <cstdlib> 
#include <ctime>

#include "interface.h"
#include "player.h"
#include "ai.h" 
int main() {
    srand(time(0));

    char tavola[3][3];
    fill_board(tavola);

    int mossa = 0, difficolta;

    std::cout << "Benvenuto! Inserire una difficolta':\n0: Umano vs Umano\n1: IA che fa mosse a caso\n2: IA semi-intelligente\n3: IA fortissima\n";
    std::cin >> difficolta;
    while(difficolta < 0 || difficolta > 3){
      std::cout << "Errore! Input non valido, riprovare.\n";
      std::cin >> difficolta;
    }

    while(true) {
        display_board(tavola);
        if(mossa % 2 == 0){
          choose_move(tavola, mossa);
        }
        else{
          switch(difficolta){
            case 0:{
              choose_move(tavola, mossa);
            }
            case 1:{
              random_choose_move(tavola, mossa);
              break;
            }
            case 2:{
              smartAi_choose_move(tavola, mossa);
            }
            case 3:{
              minimaxMakeMove(tavola, mossa);
            }
          }
        }

        if(has_won(tavola, mossa)) {
            display_board(tavola);
            if(mossa % 2 == 0){
              std::cout << "VINCE X \n";
            }
            else{
              std::cout << "VINCE O \n";
            }
            break;
        }

        if(is_board_full(tavola)) {
            display_board(tavola);
            std::cout << "PAREGGIO!" << std::endl;
            break;
        }

        mossa++;
    }

    return 0;
}

