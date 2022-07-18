/*
Scivere la funzìione:
int merge(int **result, const int *v1, int dim1, const int *v2, int dim2);
che dati 2 array ordinati in modo crescente v1 e v2 di dimensione dim1, dim2 rispettivamente,
svolge le seguenti operazioni:

alloca in memoria dinamica un array di dimensione dim1 + dim2;
inserisce in questo array tutti gli elementi di v1 e v2 in modo ordinato(crescente);
ritorna il nuovo array usando il paremetro result;
la funzione ritorna la dimensione del nuovo array (dim1 + dim2);

NON MODIFICARE HEADER, FOOTER E FIRMA DELLA FUNZIONE.

Suggerimento: ci sono delle funzioni già implementate, leggetele! Altra cosa, ricordate che
l'operatore [] ha la precedenza sull'operatore di dereferenziazione *. Quindi
*p[10] assume che p sia un vettore di puntatore ad interi, se ne prende la posizione 10,
e quindi si dereferenzia l'oggetto puntato.

Viceversa (*p)[10] assume che p sia un puntatore ad un puntatore al primo elemento di un vettore
di interi, quindi lo si dereferenzia per ottenere il puntatore al primo elemento del vettore
e infine usando l'operatore [] si prende l'elemento in posizione 10.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int leggiarray(int **v)
{
    int dim;
    int i;
    scanf("%d", &dim);
    *v = (int*) malloc(sizeof(int)*dim);
    assert(dim==0 || v!=NULL);
    for (i=0; i<dim; i++)
        scanf("%d",(*v)+i);
    
    return dim;
}

void stampa(const int *v, int dim)
{
    int i=0;
    for (i=0; i<dim; i++, v++)
        printf("%d\n", *v);
}

int merge(int **result, const int *v1, int dim1, const int *v2, int dim2)
{
    int a,b,i, newdim;
    /*scrivi qui il tuo codice*/

    newdim = dim1+dim2;
    *result = (int*)malloc(sizeof(int)*newdim);
    assert(*result != NULL);

    a = 0;
    b = 0;

    for(i = 0; i<newdim; i++) {

        if(a == dim1) {
            (*result)[i] = v2[b];
            if (b < dim2) {
                b++;
            }
        }else if(b == dim2) {
            (*result)[i] = v1[a];
            if(a < dim1) {
                a++;
            }
        }else if(v1[a] <= v2[b]) {
            (*result)[i] = v1[a];
            if(a < dim1) {
                a++;
            }
        }else{
            (*result)[i] = v2[b];
            if(b < dim2) {
                b++;
            }
        }
    }

       
    return newdim;
}
int main() {
    int *r, *i1, *i2;
    int d1, d2, dris;
    
    d1 = leggiarray(&i1);
    d2 = leggiarray(&i2);
    
    dris = merge(&r, i1, d1, i2, d2);
    
    stampa(r,dris);
    
    free(i1);
    free(i2);
    free(r);
    
    return 0;
}