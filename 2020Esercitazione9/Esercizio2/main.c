/*
Date due liste che contengono elementi diversi, scrivere la funzione:
int intersezione (tlista *out, tlista i1, tlista i2);
che date le liste i1 e i2 crei una nuova lista *out che contiene tutti gli elementi che stanno sia in 1 che in i2.
La funzione ritorna 1 se tutte le malloc vanno a buon fine. L'ordine degli elementi in *out deve essere quello dettato da i1.

Per esempio la lista 3, 6, 8, -2 
e la lista -2, 8, 10 
hanno per intersezione 8, -2
mentre -2, 8 che è considerata errore.
Eseguire eventuali inizializzaioni di *out dentro la funzione intersezione.
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

int check_elem_and_remove(tlista *l, int elem) {
    
    if (*l == NULL) {
        return 0;
    }else{
        if((*l)->elem == elem) {
            tlista supp = *l;
            *l = (*l)->next;
            free(supp);
            return 1;
        }else{
            return check_elem_and_remove(&((*l)->next), elem);
        }
    }
}

tlista copy(tlista l, int *ok) {

    tlista head, tail;
    head = NULL;
    tail = NULL;

    while(l != NULL) {
        tlista nuova = (tlista)malloc(sizeof(struct cella));
        if(nuova != NULL) {
            nuova->elem = l->elem;
            nuova->next = NULL;
            if(tail == NULL) {
                head = nuova;
            }else{
                tail->next = nuova;
            }
            tail = nuova;
        }else{
            *ok = 0;
            destroy(head);
            return NULL;
        }
        l = l->next;
    }
    *ok = 1;
    return head;
}
int intersezione(tlista *out, tlista i1, tlista i2) {

    int ok;
    *out = NULL;
    tlista tail = NULL;
    tlista copia = copy(i2, &ok);

    if(ok == 0) {
        return 0;
    }

    while(i1 != NULL) {
        if(check_elem_and_remove(&copia, i1->elem)) {
            tlista nuova = (tlista)malloc(sizeof(struct cella));
            if(nuova != NULL) {
                nuova->elem = i1->elem;
                nuova->next = NULL;
                if(tail == NULL) {
                    *out = nuova;
                }else{
                    tail->next = nuova;
                }
                tail = nuova;
            }else{
                destroy(*out);
                *out = NULL;
                return 0;
            }
        }
        i1 = i1->next;
    }
    return 1; 
}
int main() 
{
	tlista l1;
	tlista l2;
	tlista l3;
	l1=leggi();
	l2=leggi();

	intersezione(&l3, l1, l2);
    stampa(l3);

	destroy(l1);
	destroy(l2);
	destroy(l3);
}