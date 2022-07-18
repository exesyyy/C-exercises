/*
Si vuole scrivere un programma che stampi la scomposizione in fattori
primi di un numero naturale > 1. Per esempio dato il numero 12,
deve stampare:

2^2 * 3^1

cioè 2 alla seconda per 3 alla 1. 
I fattori primi vanno ordinati in senso crescente e devono comparire una sola volta.
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

int nextprime(int n) { 
    /*implement this function that returns the first prime greater than n*/
    
    int next;
    
    do {
        
        n++;
        next = n;
        
    }while(isprime(n) != 1);
    
    return next;
}

int main() {

    int n, d;
    scanf("%d", &n);
    
    /*add your code here*/

    d = 2;

    while(n != 1) {

        int count = 0;

        if(n % d == 0) {
            printf("%d^", d);

            while(n % d == 0) {
                count++;
                n = n / d;
            }

            printf("%d", count);
            d = nextprime(d);

            if(n != 1) {
                printf("*");
        }

        }else{
            d = nextprime(d);
        }


    }


    return 0;
}