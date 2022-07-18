/*
Scrivere la funzione:
void elimina_copie(tlista *pl);
che dato un puntatore ad una lista, rimuove dalla lista tutte le repliche di un elemento in modo tale che al termine dell'esecuzione tutti gli elementi
siano diversi. Se un elemento si ripete n volte andranno eliminate le prime n-1 occorrenze e si dovrà mantenere l'ennesima.
Usare la free per gestire correttamente lo spazio in memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct cella
{
	int elem;
	struct cella *next;
};

typedef struct cella *tlista;

int prepend(tlista *pl, int e)
{
	tlista nuova;
	nuova = (tlista) malloc(sizeof(struct cella));
	if (nuova)
	{
		nuova->elem = e;
		nuova->next = *pl;
		*pl = nuova;
		return 1;
	}
	else
		return 0;
}

int append(tlista *pl, int e)
{
	if (*pl)
		return append(&((*pl)->next), e);
	else
		return prepend(pl, e);

}

void destroy(tlista l) {
	if (l)
	{
		destroy(l->next);
		free(l);
	}
}


tlista leggi() 
{
	int n, e;
	tlista l=NULL;
	scanf("%d", &n);
	while (n>0)
	{
		scanf("%d", &e);
		assert(append(&l, e)!=0);
		n--;
	}
	return l;
}	

void stampa(tlista l)
{
	if (l) {
		printf("%d\n", l->elem);
		stampa(l->next);
	}
}
 
int contains(tlista l, int elem) {
    if(l == NULL) {
        return 0;
    }else{
        return (l->elem == elem) || contains(l->next, elem);
    }
}

void removeElem(tlista *pl) {
    tlista supp = *pl;
    *pl = supp->next;
    free(supp);
}

void elimina_copie(tlista *pl) {

    if(*pl != NULL) {
        if(contains((*pl)->next,(*pl)->elem)) {
            removeElem(pl);
            return elimina_copie(pl);
        }else{
            return elimina_copie(&((*pl)->next));
        }
    }  
}
int main() 
{
	tlista l1;

	l1=leggi();


	elimina_copie(&l1);
	stampa(l1);

	destroy(l1);

}