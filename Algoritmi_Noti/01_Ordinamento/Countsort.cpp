#include <iostream>
using namespace std;


void stampa_array(int A[], int dim){
    cout << "Stampa array: " << endl;
    for (int i = 0; i < dim; i++){
        cout << A[i] << "   ";
    }    
}

void count_sort(int A[], int dim, int k){
    int C[k + 1];
    int B[dim];

    // Inizializzazione dell'array di frequenza
    for (int i = 0; i < k + 1; i++){
        C[i] = 0;
    }
    
    for (int i = 0; i < dim; i++){
        C[A[i]]++;
    }

    for (int i = 1; i < k + 1; i++){
        C[i] = C[i-1] + C[i];
    }
    
    for (int i = dim - 1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    
    stampa_array(B, dim);

}


int main(){
    int A[] = {9, 5, 3, 2, 7, 9, 4};
    int dim = sizeof(A)/sizeof(A[0]);

    // Come k bisogna inserire il valore massimo
    // Presente all'interno dell'array
    stampa_array(A, dim);
    count_sort(A, dim, 9);

    return 0;
}