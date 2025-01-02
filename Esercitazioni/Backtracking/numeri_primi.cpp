#include <iostream>
using namespace std;

#define MAX_PRIME_NUMBERS 50

int S = 0;
int N = 0;

// I casi di test per il seguente progetto sono stati inseriti in un file
// di testo con il seguente contenuto:
/*
3
63 3 5
23 3 2
17 1 5
*/
// Che ha mostrato i risultati corretti

// Invece le seguenti due funzioni le ho fatte generare ad un AI
// poichè la traccia non ne richiedeva una propria implementazione
// ed esse sono ad oggi un problema effettivamente vasto per poter
// essere ancora affrontate (vedi distribuzione dei numeri primi [Congettura (o Ipotesi) di Riemann)]

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Funzione per ottenere i numeri primi in un intervallo e salvarli in un array
int generaNumeriPrimi(int min, int max, int primi[]) {
    int count = 0;
    for (int i = min; i <= max; ++i) {
        if (isPrime(i)) {
            if (count < MAX_PRIME_NUMBERS) {
                primi[count] = i; // Inserisci il numero primo nell'array
                count++;
            } else {
                std::cout << "L'array è pieno. Aumenta maxDimensione per salvare più numeri primi.\n";
                break;
            }
        }
    }
    return count; // Ritorna il numero di primi trovati
}


// Le funzioni sottostanti sono state prodotte da me
// anche se ai fini del compito basta la scrittura della
// funzione "trova_combinazioni", che sfrutta la tecnica
// del backtracking
int sum(int array[], int dim){
    int somma = 0;
    for (int i = 0; i < dim; i++){
        somma += array[i];
    }
    return somma;
}

void stampa_array(int array[], int dim){
    cout << "\nStampa Array: " << endl;
    for (int i = 0; i < dim; i++){
        cout << array[i] << "   ";
    }
    cout << endl; 
}

void trova_combinazioni(int primes[], int chosen[], int prime_count, int num_chosen, int current_sum, int start_index){
        
        // Controllo dei casi base che possono essere:
        //          - Raggiungimento della somma effettiva (soluzione)
        //          - Sforamento del valore massimo di elementi

        if (current_sum == S) {
            // Nel caso della soluzione essa viene stampata
            stampa_array(chosen, num_chosen);
        }

        if (num_chosen == N){
            // Nel caso N sia arrivato a saturazione allora non si continua l'esplorazione
            // su tale "ramo"
            return;
        }
        
    // Avvio della parte di controllo su tutti i possibili casi
    for (int i = start_index; i < prime_count; i++) {

        // Controllo se l'elemento che aggiungo è adatto alla soluzione (is_safe)
        if (current_sum + primes[i] > S){
             continue;
        }

        // Avvio eventuale della ricorsione per l'esplorazione di possibili soluzioni
        chosen[num_chosen] = primes[i];
        trova_combinazioni(primes, chosen, prime_count, num_chosen + 1, current_sum + primes[i], i + 1);
    }
}

int main(){
    
    // Variabile descrivente il numero di casi di test
    // viene impostata dopo con l'input
    int test_cases = 0;

    // Variabile contenente il numero primo minimo da cui partire
    int P = 0;
    
    // Inserimento del numero di casi di test
    cin >> test_cases;

    // Ciclo per provare tutti i casi di test
    for (int i = 0; i < test_cases; i++){
        cout << "CASO DI TEST [" << i + 1 << "]" << endl;
        
        // Presa in input dei valori principali dell'algoritmo
        cin >> S >> N >> P;

        // Creazione e generazione dei possibili candidati
        // ad essere parte della soluzione (numeri primi tra P ed S)
        int primi[MAX_PRIME_NUMBERS];
        int dim = generaNumeriPrimi(P + 1,S,primi);

        // Generazione del contenitore della possibile soluzione
        int elementi_scelti[N] = {0};    

        // Avvio del processo di backtracking per l'esplorazione delle soluzioni
        trova_combinazioni(primi, elementi_scelti, dim, 0, 0, 0);
    }
}