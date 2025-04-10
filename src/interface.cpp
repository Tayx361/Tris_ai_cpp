#include "interface.h"
#include <iostream>
#include "player.h"

// Definizioni delle funzioni
void fill_board(char tavola[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tavola[i][j] = ' ';
        }
    }
}

void display_board(char tavola[3][3]) {
    std::system("clear");
    std::cout << "    0   1   2  " << std::endl;

    for(int i = 0; i < 3; i++) {
        std::cout << "  -------------" << std::endl;
        std::cout << i << " | ";

        for(int j = 0; j < 3; j++) {
            std::cout << tavola[i][j] << " | ";
        }

        std::cout << std::endl;
    }

    std::cout << "  -------------" << std::endl;
}

bool is_legal(char tavola[3][3], int coordinate[]) {
    if(tavola[coordinate[0]][coordinate[1]] != ' ') {
        // std::cout << "Mossa illegale!" << std::endl
        return false;
    } else {
        return true;
    }
}

bool has_won(char tavola[3][3], int mossa) {
    char personaggio;

    if (mossa % 2 == 0) {
        personaggio = 'X';
    } else {
        personaggio = 'O';
    }

    // Controllo le diagonali
    if((tavola[0][0] == tavola[1][1] && tavola[0][0] == tavola[2][2]) && tavola[0][0] == personaggio) {
        return true;
    } else if((tavola[0][2] == tavola[1][1] && tavola[0][2] == tavola[2][0]) && tavola[0][2] == personaggio) {
        return true;
    }

    // Controllo le righe
    else if((tavola[0][0] == tavola[0][1] && tavola[0][0] == tavola[0][2]) && tavola[0][0] == personaggio) {
        return true;
    } else if((tavola[1][0] == tavola[1][1] && tavola[1][0] == tavola[1][2]) && tavola[1][0] == personaggio) {
        return true;
    } else if((tavola[2][0] == tavola[2][1] && tavola[2][0] == tavola[2][2]) && tavola[2][0] == personaggio) {
        return true;
    }

    // Controllo le colonne
    else if((tavola[0][0] == tavola[1][0] && tavola[0][0] == tavola[2][0]) && tavola[0][0] == personaggio) {
        return true;
    } else if((tavola[0][1] == tavola[1][1] && tavola[0][1] == tavola[2][1]) && tavola[0][1] == personaggio) {
        return true;
    } else if((tavola[0][2] == tavola[1][2] && tavola[0][2] == tavola[2][2]) && tavola[0][2] == personaggio) {
        return true;
    }

    return false;
}

bool is_board_full(char tavola[3][3]) {
    int conta_occupate = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tavola[i][j] != ' ') {
                conta_occupate++;
            }
        }
    }

    if(conta_occupate == 3 * 3) {
        return true;
    } else {
        return false;
    }
}
