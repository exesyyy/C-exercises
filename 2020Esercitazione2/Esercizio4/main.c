/*Dato un numero intero, vogliamo calcolarne la radice quadrata approssimata all'intero precedente.
Per esempio: la radice quadrata di 50 sarà 7, perchè 7 è il piu grande intero per cui 7*7 <<=50.
La radice quadrata di 100 sarà 10.

Per risolvere l'esercizio non si utilizzino funzione di libreria math.h.
Se viene inserito un numero negativo stampare la stringa "Numero negativo". 
Rispettare le maiuscole e le minuscole della stringa.

Suggerimento: supponiamo di voler calcolare la radice intera per difetto di 50.
Provo lo 0, 0*0 = 0 <= 50. Provo 1, 1*1 = 1<=50. Provo il 2 finche arrivo
al 7. 7*7 = 49 <= 50. Quindi provo anche l'8 e 8*8 = 64 > 50.
Pertanto 7 è il piu grande intero il cui quadrato è <= 50.
*/

#include <stdio.h>

int main() {
    
    int n, radice;
    
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Numero negativo");
    }else{
        int i = 0;
        while(i*i <= n) {
            radice = i;
            i++;
        }  
        printf("%d", radice);
    }


    return 0;
}