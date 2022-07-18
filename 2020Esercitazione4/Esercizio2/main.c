#include <stdio.h>
/*Dato un array v di interi di 10 elementi e un intero s, scrivere 
una funzione che ritorni 1 se v ha almeno una coppia di elementi distinti
che sommano ad s.
Ad esempio:
[2,4,4,5] ammette come somma 8 ma non 4 (non si può usare due volte il numero 2).

Scrivere un programma che legga l'array da standard input e stampi "SI" se la somma è presente o "NO" altrimenti.

Suggerimento "almeno due distinti elementi": in un array possiamo avere più coppie di numeri 
distinti che sommano ad s. 
Ad esempio: in [3,4,6,7] le coppie (3,7) e (4,6) sommani entrambe a 10
e sono composte da numeri distinti, per l'esercizio è sufficiente individuare "almeno" una coppia.

Non serve quindi analizzare il power set del vettore, ovvero l'insieme di tutte le combinazioni
di numeri di lunghezza 0...10, per ora limitiamo l'esercizio alle coppie.
*/

void leggi_array(int v[], int s) {
    int i;
    for(i = 0; i < s; i++) {
        scanf("%d", &v[i]);
    }
}


int somma_presente(int v[], int s, int target) {
    int i, j, found;
    
    found = 0;

    for(i = 0; i < s && !found; i++) {
        for(j = i + 1; j < s && !found; j++) {
            if(v[i] + v[j] == target) {
                found = 1;
            }
        }
    }

    return found;
}


int main() {
    int vet[10];
    int target;
    leggi_array(vet, 10);
    scanf("%d", &target);
    
    if (somma_presente(vet, 10, target))
        printf("SI");
    else
        printf("NO");
    
    return 0;
}