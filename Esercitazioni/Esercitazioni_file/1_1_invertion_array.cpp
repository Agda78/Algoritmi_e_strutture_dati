#include <iostream>
using namespace std;

int countAndMerge(int arr[], int l, int m, int r) {
  
    // Implementazione del Merge classico (unico cambiamento nell'if del primo ciclo while)

    int n1 = m - l + 1, n2 = r - m;

    
    int left[n1], right[n2];
    
    // Prendo il risultato del primo sottalbero
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    
    // Prendo il risultato del secondo sottalbero
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Dichiarazione di variabili utilitarie e di controllo
    int res = 0;
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {

        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        else {
            arr[k++] = right[j++];
            
            // Nel caso sia un elemento del sott'albero di destra ad essere minore
            // Allora questo sarebbe potuto essere stato invertito con tutti i suoi precedenti (presupposti
            // minori di lui). Pertanto si incrementa di un punteggio pari a n1 - i (dimensione attuale del restante
            // array da mergiare L)
            res += (n1 - i);
        }
    }

    // Merge degli elementi rimanenti
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Effettiva implementazione del "merge" dei vari risultati di count
int countInv(int arr[], int l, int r) {
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Divido il sottoproblema in due parti
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Vado a mergiare le soluzioni provenienti dai due sottalberi
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

// Maschera della chiamata a funzione
int inversionCount(int arr[], int n) {
    return countInv(arr, 0, n - 1);
}

int main(){
    int arr[] = {2,4,1,3,5};
    
    int dim = sizeof(arr)/sizeof(arr[0]);

    int res = inversionCount(arr, dim);

    cout << "Il numero di inversioni e': " << res << endl;
}