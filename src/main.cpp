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

    int mossa = 0;

    while(true) {
        display_board(tavola);
        if(mossa % 2 == 0){
          choose_move(tavola, mossa);
        }
        else{
          minimaxMakeMove(tavola, mossa);
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

