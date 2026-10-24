#include <stdio.h>
    int main(){
        int a, b, res;
            printf("Digite valor A e B:\n");
                scanf("%d%d", &a, &b);
                res = (a - b) * (a - b);
            printf("Diferença é: %d\n", res);
            
    return 0;
    }