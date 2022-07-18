/*
Dato un array di interi e la sua dimensione, scrivere la funzione:
int senza_dup(int *v, int dim);
che ritorna il numero di elementi diversi contenuti nell'array. Per esempio nell'array:
5, 3, 2, 3, -5, 3, 3, 2, 2
il risultato è 4 perchè ci sono solo 4 elementi distinti.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int leggiarray(int *vet)
{
    int n;
    int i;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", vet+i);
    return n;
}
void sortArr(int *v, int dim) {

    int i, order;

    for(order = 0; order < dim - 1; order++) {
        for(i = dim - 1; i > order; i--) {
            if(v[i] > v[i - 1]) {
                int temp;
                temp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = temp;
            }
        }
    }
}

int senza_dup(int *v, int dim) {

    int i = 1;
    int count = 1;

    if(dim == 0) {
            return 0;
        }
    
    sortArr(v, dim);

    while(i < dim) {
        int temp;

        if(v[i] != v[i - 1]) {
            count++;
        }

        temp = v[i];
        while(v[i] == temp) {
            i++;
        }
    }
    return count;
}
int main() {
    int vet[100];
    int dim;
    dim = leggiarray(vet);
    
    printf("%d\n", senza_dup(vet, dim));
    
    return 0;
}