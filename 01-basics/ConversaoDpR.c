#include <stdio.h>
    int main (){
        float real, cot, bank, res;
        printf("Digite valor da cotação do Real: \n");
            scanf("%f", &cot);
        printf("Digite valor total disponivel em Real: \n");
            scanf("%f", &bank);
            real = cot * bank;
        printf("Total em dolar seria de: %.2f\n", real);
        
    return 0;
    }