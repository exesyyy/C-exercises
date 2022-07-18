/*
Vogliamo scrivere un programma che legge n stringhe da standard input e quindi le ordina secondo l'ordine
alfabetico crescente. Le stringhe vengono allocate in memoria dinamica occupando il minore spazio possibile e i
puntatori al primo carattere sono in un array di puntatori. L'ordinamento si farà utilizzando la funzione di
libreria strcmp e scambiando i puntatori nel vettore anzichè copiando l'intera stringa. Al termine il programma
dovrà stampare le stringhe acquisite in ordine alfabetico.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


int acquisisci(char ***pvetstr)
{
    int n, i;
    char buff[100];
    scanf("%d", &n);
    *pvetstr = (char**)malloc(sizeof(char*)*n);
    for (i=0; i<n; i++)
    {
        scanf("%s", buff);
        (*pvetstr)[i] = (char*)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy((*pvetstr)[i], buff);
    }
    return n;
}

void stampa(char **vetstr, int dim){
    int i;
    for(i = 0; i<dim; i++) {
        printf("%s", vetstr[i]);
        printf("\n");
    }
}

void ordina(char **vetstr, int dim){

    int i, order;

    for(order = 0; order < dim - 1; order++) {
        for(i = dim - 1; i > order; i--) {
            if(strcmp(vetstr[i], vetstr[i-1]) <= 0) {
                char *temp;
                temp = vetstr[i - 1];
                vetstr[i - 1] = vetstr[i];
                vetstr[i] = temp;
            }
        }
    }
}
int main() {
    char **vet;
    int n;
    n = acquisisci(&vet);
    ordina(vet, n);
    stampa(vet, n);
    while (n>0)
        free(vet[--n]); /*operatore prefisso!!!*/
    free(vet);
    return 0;
}