#include <stdio.h>
#include <math.h>
int main(){
    float base, ind, res;
        printf("Digite o valor do indice e da base: ");
            scanf("%f%f", &ind, &base);
            res = pow(base, 1.0 / ind);
        printf("Valor é %.2f", res);
return 0;
}