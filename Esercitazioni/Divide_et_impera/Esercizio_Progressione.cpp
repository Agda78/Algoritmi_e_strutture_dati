#include <stdio.h>

int trova_mancante(int arr[], int n) {
    int primo = arr[0];
    int ultimo = arr[n - 1];
    int d = (ultimo - primo) / n;

    int inizio = 0, fine = n - 1;
    while (inizio <= fine) {
        int meta = (inizio + fine) / 2;
        int valore_atteso = primo + meta * d;

        if (arr[meta] != valore_atteso) {
            // Se arr[meta] non è il valore atteso, manca l'elemento in questa metà
            if (meta > 0 && arr[meta - 1] == valore_atteso - d) {
                return valore_atteso;
            }
            fine = meta - 1;
        } else {
            // L'elemento mancante è nella metà destra
            inizio = meta + 1;
        }
    }
    return -1; // Caso di errore, non dovrebbe accadere se l'input è corretto
}

int main() {
    int arr[] = {3,6,12,15,18,21};
    int dim = sizeof(arr)/sizeof(arr[0]);

    int mancato = trova_mancante(arr, dim);
    printf("%d\n", mancato);

    return 0;
}
