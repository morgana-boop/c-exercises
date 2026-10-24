#include <stdio.h>
    int main(){
        float c, fa;
            printf("Digite o valor em Celsius:" );
                scanf("%f", &c);
                fa = c * 9/5 + 32;
                    printf("O valor em Fahrenheit é: %.2f\n", fa);
    return 0;
    }