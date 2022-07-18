/*
Un grattacielo viene verniciato in modo tale che ogni piano sia bianco oppure nero. I piani vengono numerati da 0.
L'architetto è molto attento alla moda e sa che non può verniciare due piani neri consecutivi mentre può verniciare quanti
piani bianchi consecutivi vuole. Si scopre che i condomini vorrebbero tutti vivere in un piano verniciato di nero e offrono
all'architetto dei soldi perchè il piano in cui vivono sia scelto per essere verniciato di nero.
Vista l'opportunità ghiotta, l'architetto vuole scoprire il massimo guadagno che può totalizzare scegliendo opportunamente
le verniciature di bianco e nero che rispettano il vincolo di non mettere due piani neri consecutivi.

Input:
n: il numero di piani del palazzo
offerte: vettore di n elementi che contiene l'offerta del piano i, con 0 <= i < n.
Gli elementi del vettore sono non negativi.

Output:
il guadagno massimo dell'architetto.

Utilizzare la ricorsione.

Esempio: supponiamo di avere un piccolo palazzo di 3 piani.
Il piano 0 e il piano 2 offrono 100 euro per essere neri.
Il guadagno totale sarà 200, corrispondente alla verniciatura Nero, Bianco, Nero.
*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

enum colore{Bianco, Nero};

typedef enum colore tcolore;

void leggi_vettore(int v[], int dim) 
{
    int i;
    for (i=0; i<dim; i++)
        scanf("%d", &v[i]);
}
int grattacielo(int v[], tcolore colore, int n) {

    if (n == 0) {
        return 0;
    }else{
        if(colore == Nero) {
            return grattacielo(v, Bianco, n - 1);
        }else{
            int s = grattacielo(v, Bianco, n - 1);
            int s2 = grattacielo(v, Nero, n - 1);
            s2 += v[n - 1];
            if(s > s2) {
                return s;
            }else{
                return s2;
            }
        }
    }
}

int main() {
    int reward[100];
    int n;
    scanf("%d", &n);
    leggi_vettore(reward, n);
    printf("%d", grattacielo(reward, Bianco, n));
    return 0;
}