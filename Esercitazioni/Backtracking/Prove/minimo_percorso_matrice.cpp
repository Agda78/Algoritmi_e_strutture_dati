#include <iostream>
using namespace std;

#define MAX_PERCORSO 6

typedef struct{
    int riga;
    int colonna;
}Passo;

int min_percorso = INT32_MAX;
int min_percorso_passi[MAX_PERCORSO];
int num_righe;

void generate_candidates(int M[][MAX_PERCORSO], Passo passo, int costo_passo, Passo possibili[]){
    int i = 0;
    if ((M[passo.riga - 1][passo.colonna + 1] + costo_passo < min_percorso)){
        possibili[i].colonna = passo.colonna + 1;
        possibili[i++].riga = (passo.riga - 1 + num_righe) % num_righe;
        //candidates[i++] = M[passo.riga - 1][passo.colonna + 1];
    }
    if (M[passo.riga][passo.colonna + 1] + costo_passo < min_percorso){
        possibili[i].colonna = passo.colonna + 1;
        possibili[i++].riga = passo.riga;
        
        //candidates[i++] = M[passo.riga][passo.colonna + 1];
    }
    if (passo.riga < (num_righe - 1) && (M[passo.riga + 1][passo.colonna + 1] + costo_passo < min_percorso)){
        possibili[i].colonna = passo.colonna + 1;
        possibili[i++].riga = (passo.riga + 1) % num_righe;
        
        //candidates[i++] = M[passo.riga + 1][passo.colonna + 1];
    }
    
    if (i < 3){
        possibili[i].colonna = -1;
        possibili[i].riga = -1;
        
        //candidates[i] = NULL;
    }
}

void calcola_min_percorso(int M[][MAX_PERCORSO], int colonne, Passo passo,  int costo_passo, int passi[]){
    if (passo.colonna == colonne - 1){
        if (costo_passo < min_percorso){
            min_percorso = costo_passo;
            for (int i = 0; i < colonne; i++){
                min_percorso_passi[i] = passi[i];
            }
        }
        return;
    }

    Passo possibili[3];
    generate_candidates(M, passo, costo_passo, possibili);

    int i = 0;
    while (possibili[i].riga >= 0 && possibili[i].colonna >= 0 && i < 3){
        passi[passo.colonna + 1] = possibili[i].riga + 1;
        calcola_min_percorso(M, colonne, possibili[i], costo_passo + M[possibili[i].riga][possibili[i].colonna], passi);
        i++;
    }
}

int main(int argc, char const *argv[]){
    
    // Dichiarazione prima matrice (mi scocciavo di implementare l'input esterno)
    int matrix1 [5][6] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 8, 6, 4}
    };
    
    // Dichiarazione seconda matrice
    int matrix2[5][6] = {
        {3, 4, 1, 2, 8, 6},
        {6, 1, 8, 2, 7, 4},
        {5, 9, 3, 9, 9, 5},
        {8, 4, 1, 3, 2, 6},
        {3, 7, 2, 1, 2, 3}
    };
    
    // Elementi utili al fine di far partire l'algoritmo
    num_righe = 5;
    Passo passo_iniziale;
    int passi[6];


    // Inizio della ricerca sulla prima matrice
    for (int i=0; i < 5; i++){
        passo_iniziale.colonna = 0;
        passo_iniziale.riga = i;
        passi[0] = i + 1;
        calcola_min_percorso(matrix1, 6, passo_iniziale, matrix1[passo_iniziale.riga][passo_iniziale.colonna], passi);

    }

    // Stampa dei risultati per la prima matrice
    cout << "Il percorso minimo per matrix1 e': ";
    for (int i = 0; i < 6; i++)
        cout << min_percorso_passi[i] << "  ";
    cout << "\nCon costo totale del percorso: " << min_percorso << endl;
    
    // Reset delle statistiche
    min_percorso = INT32_MAX;

    // Inizio ricerca sulla successiva matrice
    for (int i=0; i < 5; i++){
        passo_iniziale.colonna = 0;
        passo_iniziale.riga = i;
        passi[0] = i + 1;
        calcola_min_percorso(matrix2, 6, passo_iniziale, matrix2[passo_iniziale.riga][passo_iniziale.colonna], passi);

    }

    // Stampa dei risultati per la seconda matrice
    cout << "Il percorso minimo per matrix2 e': ";
    for(int i = 0; i < 6; i++){
        cout << min_percorso_passi[i] << "  ";
    }
    cout << "\nCon costo totale del percorso: " << min_percorso << endl;
    return 0;
}

