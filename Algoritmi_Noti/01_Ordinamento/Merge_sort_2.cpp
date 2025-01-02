#include <iostream>
using namespace std;

void merge(int A[], int p , int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    // Genero i sotto Array
    for(int i = 0; i < n1 ; i++){
        L[i] = A[p + i];
    }

    for(int i = 0; i < n2; i++){
        R[i] = A[q + 1 + i];
    }
    
    // Considerando i sotto-array ordinati vado a ricomporli nel principale
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]){
            A[p + k] = L[i++];
        }else{
            A[p + k] = R[j++];
        }
        k++;
    }

    while (i<n1){
        A[p + k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        A[p + k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int A[], int p, int r){
    if (p < r)
    {
        int q = (p+r-1)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
    
}

void print_array(int A[], int n){
    for(int i = 0; i < n ; i++)
        cout << A[i] << "  ";
    cout << endl;
}

int main(){
    // Caso di test
    int A[] = {9,8,7,6,5,4,3,2,1};
    int lunghezza = sizeof(A)/sizeof(A[0]);

    cout << "Array di partenza: " << endl;
    print_array(A, lunghezza);

    merge_sort(A, 0, lunghezza - 1);

    print_array(A, lunghezza);
}