#include <iostream>
using namespace std;

void stampa_array(int A[], int dim){
    cout << "Stampa Array: " << endl;
    for(int i = 0; i < dim; i++){
        cout << A[i] << "   ";
    }
    cout << endl;
}

int partition(int A[], int inizio, int fine){
    
    int pivot = A[fine];
    int p1 = 0;
    int p2 = 0;
    int temp = 0;

    for (int i = inizio; i < fine; i++){
        if(A[i] < pivot){
            //SWAP
            temp = A[i];
            A[i] = A[p1];
            A[p1] = temp;

            p1++;
            p2++;
        }else{
            p2++;
        }
    }
    
    // Posizionamento del pivot
    temp = A[p1];
    A[p1] = A[fine];
    A[fine] = temp;

    return p1;
}

void quicksort(int A[], int inizio, int fine){
    if (inizio < fine){
        int q = partition(A, inizio, fine);
        quicksort(A,inizio, q - 1);
        quicksort(A, q + 1, fine);
    }
}

int calcola_casa(int A[], int dim){
    quicksort(A,0,dim-1);
    stampa_array(A, dim);

    int mediana = dim/2;

    return A[mediana];
}

int main(){
    
    int A[] = {3, 2, 4, 6};
    int dim = sizeof(A)/sizeof(A[0]);

    int casa = calcola_casa(A, dim);

    cout << "Posizione della casa ottimale: " << casa << endl;
    
    return 0;
}
