/*
Vogliamo scrivere una funzione che elimina dei caratteri da una stringa. Per farlo, la funzione riceve in input una stringa
ed un intero. Ogni bit in posizione i dell'intero, leggendolo da destra verso sinistra, conterrà 1 se il carattere i-mo della
stringa va mantenuto, 0 altrimenti. Vediamo un esempio:
Consideriamo la strigna "Hello_world" e l'intero 11. Se scriviamo in binario 11 otteniamo la scrittura 1011.
Leggendolo da destra verso sinistra abbiamo che si devono tenere i caratteri H, e, e la seconda l, quindi 
la stringa risultante sarà Hel.

Proviamo un altro esempio sempre sulla stessa stringa ma col numero 67 la cui rappresentazione binaria è
1000011. La stringa in output sarà Hew. Se sono presenti degli 1 quando la stringa è terminata, vanno ignorati.
Per esempio, data la stringa "Ab" e il numero 255, l'output sarà "Ab".

Le stringhe sulle quali lavoriamo hanno dimensione massima 200 caratteri (compreso il fine stringa).

Attenzione, le posizioni fanno sempre riferimento alla stringa originale! Per esempio, la stringa "Hello world" con
l'intero 64 darà come risultato "w".

Suggerimenti: il fatto che l'intero vada letto in rappresentazione binaria da destra verso sinistra facilita 
l'esercizio. Infatti, non è necessario calcolare tutti i bit e poi decidere cosa fare della stringa, ma basta
ricordare che per conoscere l'ultimo bit del numero n basta controllare se ne sia pari (0) o dispari (1). 
Per passare al prossimo bit, si divide n per due e si ripete l'operazione.

Per risolvere questo esercizio, potete assumere che l'input non contenga alcuno spazio.
Non controllare i numeri in negativo.
*/


#include <stdio.h>
#include <string.h>

#define DIM 200
void comprimi(char str[], int n) {
    /*Add here your code. Define new functions if needed*/

    char supp[DIM];
    int i = 0;
    int j = 0;

    while(str[i] != '\0') {

        if(n % 2 == 1) {
            supp[j] = str[i];
            j++;
        }
        i++;
        n = n / 2;
    }

    supp[j] = '\0';
    strcpy(str, supp);

}
int main() {
    char str[DIM];
    int num;
    scanf("%s", str);
    scanf("%d", &num);
    comprimi(str, num); /*usare il side effect!*/
    printf("%s\n",str);
    return 0;
}