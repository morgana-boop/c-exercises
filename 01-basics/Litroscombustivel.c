#include <stdio.h>
    int main(){
        float temp, vel, dist, lt;
            printf("Digite o tempo: ");
                scanf("%f", &temp);
            printf("Digite a velocidade media: ");
                scanf("%f", &vel);
                    dist = temp * vel;
                    lt = dist / 12;
                printf("\n\nvelocidade media foi: %2.f\n", vel);
                printf("Tempo gasto foi: %.2f\n", temp);
                printf("A distancia percorrida foi: %.2f\n", dist);
                printf("Qauntidade de litros usados foi: %.2f\n", lt);
                
    return 0;
    }