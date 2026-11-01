#include <stdio.h>
    int main(){
        int a, b, c, res;
            printf("digite o valor de A, B e C: \n");
                scanf("%d%d%d", &a, &b, &c);
            res = a + b + c;
                if (res >= 100)
                {
                    printf("A soma das 3 variaveis é maior que 100: %d", res);
                }
                else {
                    printf("A soma das tres variaveis é menor que 100: %d", res);
                }
    return 0;
    }