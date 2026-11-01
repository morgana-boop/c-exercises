#include <stdio.h>
    int main(){
        float ce, fa;
            printf("Digite o valor em fahrenheit: ");
                scanf("%f", &fa);
                    ce = ((fa - 32) * 5)/9;
                        printf("Valor em Celsius é: %.2f\n", ce);                        
    return 0;
    }