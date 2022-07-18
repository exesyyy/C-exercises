#include <stdio.h>

int main() {
    
    int prev, curr, flag;

    flag = 1;

    scanf("%d", &prev);
    if(prev % 2 == 1 || prev % 2 == -1) {
        flag = 0;
    }

    scanf("%d", &curr);
    if(curr % 2 == 1 || curr % 2 == -1) {
        flag = 0;
    }

    while(prev != 0 || curr != 0) {
        prev = curr;
        scanf("%d", &curr);
        if(curr % 2 == 1 || curr % 2 == -1) {
        flag = 0;
        }
    }
    
    if(flag == 0) {
        printf("NO");
    }else{
        printf("SI");
    }

    return 0;
}