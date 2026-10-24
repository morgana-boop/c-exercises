#include <stdio.h>
    int main(){
        int a, b, c;
            printf("Digite o valor de A e B: ");
                scanf("%d %d", &a, &b);
                c = a;
                a = b;
                b = c;
            printf("O valor invertido de A e B é %d, %d\n", a, b);
    return 0;
    }