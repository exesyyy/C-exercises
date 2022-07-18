/*
Scrivere la funzione:
int ordinato(int *vet, int dim);
che ritorna 1 se l'array in input è ordinato in senso lato, 0 altrimenti. 
La funzione deve essere ricorsiva.

Ad esempio: l'array 1, 3, 3, 5, 7 è ordinato.
L'array vuoto è ordinato.
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
int ordinato(int *vet, int dim) {

    if(dim == 0 || dim == 1) {
        return 1;
    }else{
        if(vet[dim-1] >= vet[dim-2]) {
            return ordinato(vet, dim-1);
        }else{
            return 0;
        }
    }
} /*funzione ricorsiva!*/
int main() {
    int vet[100];
    int dim;
    dim = leggiarray(vet);
    
    if (ordinato(vet, dim))
        printf("ORDINATO\n");
    else
        printf("NON ORDINATO");
    return 0;
}