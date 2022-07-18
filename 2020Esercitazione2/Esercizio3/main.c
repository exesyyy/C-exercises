#include <stdio.h>


/*
Il massimo comun denominatore (MCD) di 2 numeri interi x ed y è il piu grande
numero intero per il quale possono essere entrambi divisi.

Dati 34 e 20 l'MCD è 2, in quanto 2 è il numero massimo divisore proprio comune a entrambi i numeri.
In questa esercitazione vedremo l'algoritmo di Euclide per il calcolo dell'MCD
che funziona su una coppia di numeri x >= 0, y >= 0 e x >= y.

Consideriamo inizialmente il caso di 2 numeri interi x e y, con x > y ed y > 0.

1) Calcolo il resto r della divisione tra x ed y.
Ovviamente 0 <= r < y.

2) Se r = 0, allora MCD(x, y) = y

3) Altrimenti se r > 0:
    1) assegno ad x il valore di x
    2) assegno ad y il valore di r
    3) torno al passo 1.
    
Questi punti vengono iterati quando r > 0.


Alcune condizioni particolari:

 - Se y = 0 allora MCD(x, 0) = x in quanto 0 è divisibile per qualsiasi numero diverso da 0 e quindi anche da x.
 - Per definizione poniamo MCD(0,0) = 0
 - MCD (x, x) = x
 

Scrivi un programma che acquisisca i 2 numeri da standard input, prima x e poi x, e stampi il risultato
dell'algortimo di Euclide.
Nel caso di condizioni errate, ad esempio x < y, il programma deve stampare -1.

*/

int main() {
    
    int x, y, mcd;

    scanf("%d", &x);
    scanf("%d", &y);

    if(x < y || x < 0 || y < 0) {
        mcd = -1;
    }else if(x == 0 && y == 0) {
        mcd = 0;
    }else if(x == y) {
        mcd = x;
    }else if(y == 0) {
        mcd = x;
    }else{
        int resto;
        do {
        resto = x % y;
        if(resto == 0) {
            mcd = y;
        }else{
            x = y;
            y = resto;
        }
        }while (resto != 0);
    }

    printf("%d", mcd);

    return 0;
}