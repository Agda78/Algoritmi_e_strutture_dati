#include <iostream>
using namespace std;

void stampa_array(int A[], int dim){
cout << "Print Array: " << endl;
    for (size_t i = 0; i < dim; i++){
        cout << A[i] << "   ";
    }
    cout << endl;
}

int partition(int A[], int p, int dim){
    int pivot = A[dim];
    int p1 = p;
    int p2 = p;
    int aux = 0;

    for(int i = p; i < dim; i++){
        if(A[i] <= pivot){
            aux = A[i];
            A[i] = A[p1];
            A[p1] = aux;
            p1++;
            p2++;
        }else{
            p2++;
        }
    }

    A[dim] = A[p1];
    A[p1] = pivot;

    return p1;
}

void Quicksort(int A[], int p, int dim){
    if (p < dim){
        int q = partition(A, p, dim);
        Quicksort(A, p, q-1);
        Quicksort(A, q+1, dim);
    }
}

int main(){
    //Impostazione dell'input
    int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int dim = sizeof(A)/sizeof(A[0]);

    //Esecuzione dell'algoritmo e valutazione tramite i log
    stampa_array(A,dim);
    Quicksort(A, 0, dim - 1);
    stampa_array(A,dim);
}