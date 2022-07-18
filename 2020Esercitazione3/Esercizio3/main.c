/*
In matematica, sono numeri amicabili o amicali o amici due numeri per cui la somma dei divisori
propri di uno (quindi escluso il numero stesso) è uguale all'altro e viceversa.

Un esempio classico è dato dalla coppia 220 e 284. I due numeri sono amicabili in quanto:

220 è divisibile per 1,2,4,5,10,11,20,22,44,55 e 11o e la loro somma risulta 284.
284 è divisibile per 1,2,4,71,142 che sommati danno proprio 220.

Scrivere un programma che dati due numeri naturali > 1 acquisiti da standard input,
stampi "SI" se sono amicabili oppure "NO" altrimenti.

Suggerimento: crea una funzione ausiliaria (di aiuto) che da un numero > 1 restituisca 
la somma dei suoi divisori propri. A questo punto il gioco è fatto...
*/


#include <stdio.h>

/*create your functions here*/
int sumDivs(int n) {

    int sum = 0;
    int div = n / 2;

    while(div != 0) {
        if(n % div == 0) {
            sum += div;
        }
    div--;
    }

    return sum;
}


int main() {
    
    int n1, n2;

    do {
        scanf("%d", &n1);
        scanf("%d", &n2);
    }while (n1 <= 1 || n2 <= 1);

    if(sumDivs(n1) == n2 && sumDivs(n2) == n1) {
        printf("SI");
    }else{
        printf("NO");
    }

    return 0;
}