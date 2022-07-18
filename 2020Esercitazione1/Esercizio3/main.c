#include <stdio.h>

int minimo, massimo;
float media;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int prev2, prev, curr, count;

    media = 0.0;
    count = 0;

    scanf("%d", &prev2);
    count++;
    media = media + prev2;
    minimo = prev2;
    massimo = prev2;


    scanf("%d", &prev);
    count++;
    media = media + prev;
    if(prev > massimo) {
        massimo = prev;
    }
    if(prev < minimo) {
        minimo = prev;
    }

    scanf("%d", &curr);
    count++;
    media = media + curr;
    if(curr > massimo) {
        massimo = curr;
    }
    if(curr < minimo) {
        minimo = curr;
    }

    while(prev2 != prev || prev != curr) {
        prev2 = prev;
        prev = curr;
        scanf("%d", &curr);
        count++;
        media = media + curr;
        if(curr > massimo) {
            massimo = curr;
        }
        if(curr < minimo) {
            minimo = curr;
        }
    }

    media = media - (curr * 2);
    count = count - 2;
    media = media / count;

    /*output: non cambiare*/
    printf("%d\n", minimo);
    printf("%d\n", massimo);
    printf("%.3f", media); /*specifica che vogliamo 3 decimali dopo la vigola*/
    return 0;
}