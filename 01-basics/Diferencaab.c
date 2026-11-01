#include <stdio.h>
    int main(){
        int a, b, res;
            printf("Digite o valores de A e B: \n");
                scanf("%d%d", &a, &b);
                if (a > b)
                {
                    res = a - b;
                    printf("O resultado da diferença entre A e B é: %d\n", res);
                }
                else 
                    printf("O valor de B é maior que A.\n");

    return 0;
    }