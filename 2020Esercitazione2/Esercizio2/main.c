#include <stdio.h>


/*
Scrivere un programma che, acquisito in input un numero n > 0,
stampi l'ennesimo n numero primo.
*/


int prime(int n) {

    int flag = 1;
    int div = 2;

    while(div < n && flag) {
        if(n % div == 0) {
            flag = 0;
        }
    div++;
    }

    return flag;
}


int main() {
    
    int n, numero, finale;

    do {
        scanf("%d", &n);
    }while (n<=0);

    numero = 2;

    while(n != 0) {
        if(prime(numero)) {
            n--;
            finale = numero;
        }
    numero++;
    }

    printf("%d", finale);

    return 0;
}