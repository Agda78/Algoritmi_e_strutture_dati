#include <iostream>
using namespace std;

int mancante(int A[], int inizio, int fine, int d) {
    if (inizio >= fine) {
        return 0;  // Caso base, nessun numero mancante in questo intervallo
    }

    int q = (fine + inizio) / 2;

    // Verifica se l'elemento mancante è tra A[q] e A[q+1]
    if (A[q+1] - A[q] != d) {
        return A[q] + d;  // Trova il numero mancante e ritorna
    }

    // Ricerca nella metà sinistra o destra
    int sol_1 = mancante(A, inizio, q, d);
    if (sol_1 != 0) {
        return sol_1;  // Se trovato nella metà sinistra, ritorna
    }

    return mancante(A, q + 1, fine, d);  // Altrimenti, cerca nella metà destra
}

int main() {
    int A[] = {3,6,12,15,18,21};  // Esempio con un elemento mancante
    int dim = sizeof(A) / sizeof(A[0]);

    int d = (A[dim - 1] - A[0]) / dim;  // Calcola la differenza d teorica
    int num_manc = mancante(A, 0, dim - 1, d);

    cout << "Il valore mancante è: " << num_manc << endl;
    return 0;
}
