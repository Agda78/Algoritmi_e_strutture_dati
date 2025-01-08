// Tale algoritmo ha una complessità pari a: O(min(n,m))
// ed è data dal while principale.
// Ci sono soluzioni che impiegano un tempo O(lg(k)), k = min(n,m)
// ma non sono state affrontate da me

#include <iostream>
using namespace std;

int find_k_value(int a[], int n, int b[], int m, int k){
    // Presupponiamo sempre che k < n + m
    
    // Contatore primo array
    int i = 0;

    // Contatore secondo array
    int j = 0;

    // Contatore terzo array
    int c = 0;

    // Immagazinnatore del risultato
    int result = 0;

    // Fase simile a quella di merge, ma modificata
    while (i < n && j < m){
        if (a[i] > b[j]){
            result = b[j];
            j++;
        }else{
            result = a[i];
            i++;
        }

        if (c == k - 1){
            return result;
        }
        c++;        
    }

    // Calcolo del numero di valori rimanenti
    int rimanenti = k - c;

    // Verifico se ho esaurito il primo array
    // Altrimenti risalgo subito al valore
    if (i < n){
        return a[i + rimanenti - 1];
    }

    // Verifico se ho esaurito il secondo array
    // altrimenti risalgo subito al valore prefissato
    if (j < m){
        return b[j + rimanenti - 1];
    }

    return 0;
}

int main(){
    int a[] = {100, 112, 256, 349, 770};
    int b[] = {72, 86, 113, 119, 265, 445, 892};

    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);

    int k = 7;

    int res = find_k_value(a, n, b, m, k);

    cout << "Il valore alla posizione " << k << " e': " << res << endl;

    return 0;
}