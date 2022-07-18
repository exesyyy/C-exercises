/*
Desert Island

Per il vostro viaggio in un'isola deserta potete portarvi una quantità di oggetti che pesa al massimo 20kg. Di ogni
oggetto conoscete la quantità( >= 0), il peso ( >0 ), e poi gli attribuite un punteggio utilità che è >= 0.
L'utilità complessiva dei vostri viaggi sarà la somma delle loro utilità individuali. Il tuo scopo è quello di scrivere
un programma che, data la quantità di oggetti disponibili, la loro utilità e il loro peso, calcoli qual è l'utilità
complessiva massima che puoi raggiungere.

Input:
avrai 3 vettori:
disponibilita
peso
utilita
ciascuno di dimensione dim. 
disponibilita[i] è il numero di oggetti disponibili della tipologia i.
peso[i] è il peso di ciascuno degli oggetti di tipologia i.
utilita[i] è il punteggio di utilità di ciascuno degli oggetti di tipologia i.

Implementa la funzione:
int isoladeserta(int disponibilita[], int peso[], int utilita[], int dim, int avanzo);
che ritorna l'utilità complessiva massima raggiungibile.

Al termine dell'esecuzione la funzione deve lasciare inalterati i contenuti dei vettori(il che
non vole dire che non possano essere modificati, ma solo che se lo fate, poi dovete ripristinare
il valore originale).

Suggerimento: impostate una ricorsione sulla dime sione dim degli array. Il parametro
avanzo indica quanto peso potete ancora portare con voi e ogni oggetto o lo portate o lo lasciate,
Quindi di un oggetto di tipologia i ne potete prendere 0, oppure 1 oppure 2...fino a 
disponibilita[i] ammesso che abbiate sufficiente spazio avanzato.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int isoladeserta(int disponibilita[], int peso[], int utilita[], int dim, int avanzo) {

    if(dim == 0) {
        return 0;
    }else{
        int s1, s2;
        
        if(disponibilita[dim -1] > 0 && avanzo > peso[dim - 1]) {
            disponibilita[dim - 1]--;
            s1 = isoladeserta(disponibilita, peso, utilita, dim, avanzo - peso[dim]) + utilita[dim - 1];
            disponibilita[dim - 1]++;
        }else{
            s1 = 0;
        }
        
        s2 = isoladeserta(disponibilita, peso, utilita, dim - 1, avanzo - peso[dim]);
        
        if(s1 > s2) {
            return s1;
        }else{
            return s2;
        }
    }
}

int main() 
{
    
    int dim; int i;
    int vp[100], vu[100], vd[100];
    
    scanf("%d", &dim);
    
    for (i=0; i<dim; i++)
    {
        scanf("%d", vd+i);
        scanf("%d", vp+i);
        scanf("%d", vu+i);
    }
    
    printf("%d\n", isoladeserta(vd,vp,vu,dim,20));
    
    return 0;
}