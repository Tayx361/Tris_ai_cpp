void random_choose_move(char tavola[3][3], int mossa);
bool can_win(char tavola[3][3]);
void smartAi_choose_move(char tavola[3][3], int mossa);
void prevent_loss(char tavola[3][3], int mossa);

int fine_partita(char tavola[3][3], int mossa, char maxPlayer);
int minimax(char tavola[3][3], int mossa, char maxPlayer);
void minimaxMakeMove(char tavola[3][3], int mossa);