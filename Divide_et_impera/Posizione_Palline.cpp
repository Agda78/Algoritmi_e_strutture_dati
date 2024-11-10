#include <iostream>
using namespace std;

int cerca_valore(int D, int I, int start){
    int point = start;
    
    // Controllo il caso base in cui sia arrivato alla soluzione
    if (D == 1){
        return point;
    }

    // In base a come vado ad esplorare l'albero comprendo in che direzione andare
    // e di conseguenza quale path dover seguire
    return cerca_valore(D - 1, (I + (I % 2)) / 2, (point * 2) - (I % 2) + 1);
}

int main(){
    
    int N;
    int D;
    int I;


    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> D >> I;
        cout << "Valore raggiunto (D = "<<D<<"; I = "<<I<<"): " << cerca_valore(D,I,1) << endl;
    }
}