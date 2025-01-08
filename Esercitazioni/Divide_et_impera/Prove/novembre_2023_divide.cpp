#include <iostream>
using namespace std;

int first_max_occurrences(int A[], int inizio, int fine){
    int dim = (fine - inizio + 1);
    int mid = inizio + dim/2;
    
    // Tale if prevede vari casi. Il caso in cui siamo all'ultimo elemento
    // o che ci troviamo in un caso di endpoint o startpoint (valori di picco)
    if((mid == 0 || A[mid] >= A[mid - 1]) && (mid == fine || A[mid] >= A[mid + 1])){
        return A[mid];
    }

    // Altrimenti vedo dove andare
    if(mid > 0 && A[mid] <= A[mid - 1]){
        // Vai a sinistra (in questo caso trova prima 5)
        return first_max_occurrences(A, inizio, mid - 1);
    }

    // Vai a destra
    return first_max_occurrences(A, mid + 1, fine);
    
}

int main(){
    int A[] = {3,3};
    int dim = sizeof(A)/sizeof(A[0]);

    int max = first_max_occurrences(A, 0, dim - 1);

    cout << "Il primo massimo locale trovato e': " << max << endl;

    return EXIT_SUCCESS;
}