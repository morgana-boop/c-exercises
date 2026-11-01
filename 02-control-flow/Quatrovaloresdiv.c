#include <stdio.h>
    int main(){
        int a, b, c, d, res;
            printf("Digite os valores de A, B C e D: \n");
                scanf("%d%d%d%d", &a, &b, &c, &d);
            if (a %2 == 0 && a %3 == 0)
            {
                printf("Valor A: %d, é divisivel por 2 e 3\n", a);
            }
            if (b %2 == 0 && b %3 == 0)
            {
                printf("Valor B: %d, é divisivel por 2 e 3\n", b);
            }
            if (c %2 == 0 && c %3 == 0)
            {
                printf("Valor C: %d, é divisivel por 2 e 3\n", c);
            }
            if (d %2 == 0 && d %3 == 0)
            {
                printf("Valor D: %d, é divisivel por 2 e 3\n", d);
            }
            
    return 0;
    }