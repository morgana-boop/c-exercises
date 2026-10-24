#include <stdio.h>
#include <math.h>
    int main(){
        float base, ex, res;
            printf("Digite o valor da base e expoente: \n");
                scanf("%f%f", &base, &ex);
                res = pow(base, ex);
                printf("Resultado é: %.2f\n", res);

    return 0;
    }