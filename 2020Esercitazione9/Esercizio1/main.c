/*
Scrivere la funzione ricorsiva:
int uguali(tlista l1, tlista l2);
che ritorna 1 se l1 è uguale ad l2 (cioè se contiene gli stessi elementi nello stesso ordine), 0 altrimenti.
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


int uguali(tlista l1, tlista l2) {

    if(l1 == NULL && l2 == NULL) {
        return 1;
    }else if((l1 != NULL && l2 == NULL) || (l1 == NULL && l2 != NULL)) {
        return 0;
    }else{
        if(l1->elem == l2->elem) {
            return uguali(l1->next, l2->next);
        }else{
            return 0;
        }
    }
}

int main() 
{
	tlista l1;
	tlista l2;
	l1=leggi();
	l2=leggi();
	if (uguali(l1,l2))
		printf("UGUALI\n");
	else
		printf("DIVERSE\n");
	destroy(l1);
	destroy(l2);
}