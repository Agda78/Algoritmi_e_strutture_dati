#include <iostream>
using namespace std;

// La logica di tale algoritmo si basa su un approccio divide et impera
// dove il controllo viene effettuato sul numero di volte in cui si è attraversato
// il nodo. Nel caso in cui sia pari, si va a sinistra, nell'altro caso a destra
// In base alla struttura dell'albero descritta nel problema, allora si procede
// al calcolo del nodo successivo e del valore ad esso associato
// Tale ciclo avviene dino a che non si è raggiunta la profondità richiesta dal caso di test

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

    // Variabili per la lettura integrale dell'input
    // Presupposto da file
    // lanciare: ./<nome_programma> < input.txt
    // Dove in "input.txt" è descritto l'input come da traccia  
    int N;
    int D;
    int I;

    // Leggo il numero di test cases
    cin >> N;

    // Prelevo i due valori adiacenti e testo il loro caso
    for (int i = 0; i < N; i++){
        cin >> D >> I;

        // Stampa del risultato proveniente dall'algoritmo implementato
        cout << "Valore raggiunto (D = "<<D<<"; I = "<<I<<"): " << cerca_valore(D,I,1) << endl;
    }
}