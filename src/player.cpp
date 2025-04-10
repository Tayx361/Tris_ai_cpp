#include "player.h"
#include <iostream>
#include "interface.h"

void choose_move(char tavola[3][3], int mossa) {
    int coordinate[2];

    do {
        std::cout << "Inserire la riga (0-2): "; std::cin >> coordinate[0];
        while(coordinate[0] < 0 || coordinate[0] > 2) {
            std::cout << "Valore non valido. Riprovare. "; std::cin >> coordinate[0];
        }

        std::cout << "Inserire la colonna (0-2): "; std::cin >> coordinate[1];
        while(coordinate[1] < 0 || coordinate[1] > 2) {
            std::cout << "Valore non valido. Riprovare. "; std::cin >> coordinate[1];
        }

        if(!is_legal(tavola, coordinate)){
          std::cout << "Mossa illegale! \n";
        }
    } while(!is_legal(tavola, coordinate));

    if(mossa % 2 == 0) {
        tavola[coordinate[0]][coordinate[1]] = 'X';
    } else {
        tavola[coordinate[0]][coordinate[1]] = 'O';
    }
}
