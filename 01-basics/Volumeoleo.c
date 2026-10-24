#include <stdio.h>
    int main(){
        float vol, alt, ra;
            printf("Digite o valor do raio: ");
                scanf("%f", &ra);
            printf("Digite o valor da altura: ");
                scanf("%f", &alt);
            vol = 3.14159 * (ra * ra) * alt;
                printf("Valor do volume é: %.2f\n", vol);
    return 0;
    }