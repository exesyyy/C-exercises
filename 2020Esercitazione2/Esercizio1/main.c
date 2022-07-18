#include <stdio.h>

/*
Scrivi un programma che disegni un triangolo di base n e altezza (n+1)/2.
Per esempio se n = 5 abbiamo il seguente triangolo;

  *
 ***
*****

1) n deve essere positivo e dispari, ripetere la lettura di n da standard input
fintanto che soddisfa la condizione.

2) usare gli spazi per staccare gli * dal bordo di sinistra.

3)non mettere nessuno spazio dopo l'ultimo * ma usare il carattere \n per andare a capo.

*/

int main() {
    
    int n, altezza;

    do {
        scanf("%d", &n);
    }while (n <= 0 || n % 2 == 0);

    altezza = (n + 1) / 2;

    for(int i = 1; i <= altezza; i++) {
        
        for(int j = 1; j <= (altezza-i); j++) 
            printf(" ");
        
        for(int k = 1; k <= (i*2)-1; k++) 
            printf("*");
        
        printf("\n");
    }


    return 0;
}
