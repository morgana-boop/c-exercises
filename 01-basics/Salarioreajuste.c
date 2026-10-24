#include <stdio.h>
    int main(){
        int sm;
        float pr, ns;
            printf("Digite o valor do reajuste (%%):\n");
                scanf("%f", &pr);
            printf("Digite o valor do salario mensal: \n");
                scanf("%d", &sm);
            ns = sm * (pr / 100);
            printf("O reajuste é de: %.2f", ns);

    return 0;
    }