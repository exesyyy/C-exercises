#include <stdio.h>

int main() {
    
    int prev, curr, sum;

    sum = 0;

    scanf("%d", &prev);
    if(prev % 2 == 1 || prev % 2 == -1) {
        sum = sum + prev;
    }

    scanf("%d", &curr);
    if(curr % 2 == 1 || curr % 2 == -1) {
        sum = sum + curr;
    }

    while(curr != prev + 1) {
        prev = curr;
        scanf("%d", &curr);
        if(curr % 2 == 1 || curr % 2 == -1) { 
            sum = sum + curr;
        }
    }
    
    printf("%d", sum);

    return 0;
}