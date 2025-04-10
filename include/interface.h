#include <iostream>

void fill_board(char tavola[3][3]);
void display_board(char tavola[3][3]);
bool is_legal(char tavola[3][3], int coordinate[]);
bool has_won(char tavola[3][3], int mossa);
void choose_move(char tavola[3][3], int mossa);
bool is_board_full(char tavola[3][3]);