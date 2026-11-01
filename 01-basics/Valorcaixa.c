#include <stdio.h>
    int main(){
        float comp, larg, alt, vol;
            printf("digite o valor da Altura, Largura e Comprimento: \n");
                scanf("%f%f%f", &alt, &larg, &comp);
                vol = alt * larg * comp;
            printf("o volume total é de: %.2f\n", vol);
    return 0;
    }