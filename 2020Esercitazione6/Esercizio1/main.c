/*
Date 2 stringhe str1 e str2 scrivere una funzione che ritorni 1 se la stringa str2 è
contenuta in str1. Il controllo deve essere case-sensitive, cioè le lettere minuscole e maiuscole
devono essere considerate equivalenti. Per esempio la stringa "BABele" contiene,
fra le altre, la stringa ABE ma anche abe o aBeL.
La funzione ritorna 1 se la condizione è soddisfatta, 0 altrimenti.
La stringa vuota è contenuta in ogni altra stringa ma ha come sottostringa solo la stringa vuota
stessa.
Le stringhe vengono lette da standard input e sono racchiuse tra i caratteri < e > che non
possono essere presente se non all'inizio e alla fine rispettivamente. Quindi per inserire 
la stringa BABele ed eseguire la ricerca di ABE l'input sarà:
<BABele>
<ABE>
e la risposta sarà 1, in quanto ABE è contenuta in BABele.

Suggerimento: può essere di aiuto usare un ragionamento top-down che scomponga il problema
in sottoproblemi. Se necessario definire altre funzioni.

Attenzione: non è possibile usare le funzioni della libreria string.h>
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*decide se la stringa s2 e' una sottostringa di s1*/

char convertCase(char letter) {     /*funzione che converte il case di un char*/

    if(letter >= 'A' && letter <= 'Z') {
        letter = letter + 32;
    }else if(letter >= 'a' && letter <= 'z'){
        letter = letter - 32;
    }
    return letter;
}

int contenuta(char s2[], char s1[]) {


    int sub, count, len2;
    len2 = 0;
    
    for(int i = 1; s2[i] != '>'; i++) {
        len2++;
    }
    
    sub = 0;
    
    if(s2[1] == '>') {                              /*se s2 è vuota*/
        sub = 1;
    }else if(s1[1] == '>' && s2[1] != '>' ) {   
        sub = 0;
    }else{
        int a, b;
        b = 1;
        
        for(a = 1; s1[a] != '>' && !sub; a++) {
            if(s1[a] == s2[b] || s1[a] == convertCase(s2[b])) {
                int c = a;
                int d = b;
                
                count = 0;
                while(s2[d] != '>') {
                    if(s1[c] == s2[d] || s1[c] == convertCase(s2[d])) {
                        count++;
                    }
                c++;
                d++;
                }
                
                if(len2 == count) {
                    sub = 1;
                }
            }
        }
    }
    return sub;
}

int main() {
    char str1[100];
    char str2[100];
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    if (contenuta(str2,str1)) 
        printf("CONTENUTA\n");
    else
        printf("NON CONTENUTA\n");
    
    return 0;
}