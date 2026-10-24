#include <stdio.h>
    int main (){
        float real, cot, bank, res;
        printf("Digite valor da cotação do dolar: \n");
            scanf("%f", &cot);
        printf("Digite valor total disponivel em dolar: \n");
            scanf("%f", &bank);
            real = cot * bank;
        printf("Total em reais seria de: %.2f\n", real);
        
    return 0;
    }