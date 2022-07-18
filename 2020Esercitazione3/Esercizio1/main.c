/*
La congettura di Goldbach stabilisce che ogni numero naturale > 1
è la media di due numeri primi. Per esempio 2 è la media tra 2 e 2.
14 è la media di 11 e 17. 
20 è la media di 17 e 23.
13 è la media di 7 e 19.

Scrivi una funzione che dato un numero n restituisca il più piccolo numero
primo p1 tale che esiste un altro p2 che soddisfi (pi+p2)/2.

Attenzione: talvolta la coppia di prima non è unica. Ad esempio,
se prendiamo il 13 abbiamo che:

13=(3+23)/2
13=(7+19)/2
13=(13+13)/2

In questo caso il programma ritorna 3.
*/


#include <stdio.h>

int isprime(int n) {
    int prime = 1;
    if (n>1) {
        int d = 2;
        while (d<n && prime){
            if (n%d == 0)
                prime = 0;
            d++;
        }
    }
    else
        prime = 0;
    return prime;
}


int goldbach(int n) {
    int p1, p2, i, finale;

    p1 = n;
    p2 = n;

    for(i = n; i > 1; i--) {
        if((isprime(p1)==1) && (isprime(p2)==1)) {
            if((p1+p2)/2==n) {
                finale = p1;
            }
        }
        p1--;
        p2++;
    }

    return finale;
}

int main() {
    int n;
    int p;
    scanf("%d", &n);
    
    p = goldbach(n);
    
    printf("%d\n", p);
    
    return 0;
}