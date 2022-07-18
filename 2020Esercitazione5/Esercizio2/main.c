/*
Negli scacchi la notazione FEN serfve ad indicare la situazione dei pezzi in una scacchiera.
E' descritta per righe secondo le seguenti regole:
viene descritta ogni singola traversa (riga), a partire dalla ottava (quella che sta sopra),
fino alla prima (quella che sta sotto); pper ciascuna traversa, sono descritti i contenuti
di ciascuna casa, a partire dalla colonna "a" (a sinistra) ed a finire con quella "h" (a destra).

I pezzi del Bianco sono indicati usando le iniziali (inglesi) dei pezzi stessi in maiuscolo
(KQRBNP); quello del Nero, con le stesse lettere ma in minuscolo (kqrbnp). Il numero di case
vuote tra un pezzo e l'altro o dai bordi della scacchiera è indicato con le cifre dall'1 all'8.
Se una traversa non contiene pezzi o pedoni, sarà descritta con un 8. Il segno " / " è usato
per separare le traverse una dall'altra.

In questo esercizio trascureremo le altre regole. Qualche esempio di notazione FEN può essere
trovata in https://it.wikipedia.org/wiki/Notazione_Forsth-Edwards

Vogliamo scrivere un programma che letta un'unica stringa che contiene la notazione FEN
di una partita, ne stampi la corrispondente scacchiera secondo le regole:
le case che contengono un pezzo saranno denotate con la lettera di quel pezzo (KQRBNP o kqrbnp),
mentre le case vuote sono indicate da un simbolo di underscore_
Le traverse sono separate da un fine riga.
Non è necessario controllare che l'input FEN sia ben formato.

*/

#include <math.h>
#include <stdio.h>
#include <string.h>

void trasforma_fen(char s1[], char s2[]){
    /*attenzione al carattere di fine stringa!*/

    int i = 0;
    int j = 0;

    while(s1[i] != '\0') {

        if(s1[i] == '/') {
            s2[j] = '\n';
            j++;
        }else if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z')){
            s2[j] = s1[i];
            j++;
        }else{
            int a;
            for(a = s1[i]; a != 48; a--) {
                s2[j] = '_';
                j++;
            }
            
        }

    i++;
    
    }
    s2[j] = '\0';
}

int main() {
    char input[100];
    char output[100];
    
    scanf("%s", input);
    
    trasforma_fen(input, output);
    
    printf("%s", output);
    return 0;
}