#include <stdio.h>

int main() {

    int n, i, k, num, flag;

    scanf("%d", &n);
    scanf("%d", &k);

    flag = 0;

    for(i = 0; i < n; i++) {
        scanf("%d", &num);
        if(num == k) {
            flag = 1;
        }
    }

    if(flag == 1) {
        printf("SI");
    }else{
        printf("NO");
    }

    return 0;
}