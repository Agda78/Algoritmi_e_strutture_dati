#include <iostream>
#define MAX_IN 10

using namespace std;

int counter = 0;
int N = 0;

bool is_safe(int board[MAX_IN][MAX_IN], int row, int col){
    // Controllo della colonna sopra la posizione corrente
    int i = row;
    while (i >= 0) {
        if (board[i][col] == 1) {
            return false;
        }
        i--;
    }

    // Controllo Diagonale Sinistra in alto
    i = row;
    int j = col;
    while (i >= 0 && j >= 0) { // finché siamo nei limiti della scacchiera
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }

    // Controllo Diagonale Destra in alto
    i = row;
    j = col;
    while (i >= 0 && j < N) { // finché siamo nei limiti della scacchiera
        if (board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }

    return true; // Se non ci sono conflitti, la posizione è sicura
}

void backtracking(int board[][MAX_IN], int row){
    if (row == N){
        counter++;
        return;
    }

    for (int i = 0; i < N; i++){
        if (is_safe(board, row, i)){  // Aggiungiamo condizione di sicurezza
            board[row][i] = 1;
            backtracking(board, row + 1);
            board[row][i] = 0; // Backtrack: rimuovi regina
        }
    }
}

int main(){
    N = 8;
    counter = 0;
    int board[MAX_IN][MAX_IN] = {0}; // Inizializza tutta la scacchiera a 0

    backtracking(board, 0);

    cout << "Numero di possibili combinazioni: " << counter << endl;
    return 0;
}
