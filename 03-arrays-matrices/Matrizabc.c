#include <stdio.h>
int main(){
    int matrizA[5];
    int matrizB[5];
    int matrizC[5];
        for(int i = 0; i < 5; i++){
            printf("Digite o valor da matriz A e matriz B: \n ");
                scanf("%d%d", &matrizA[i], &matrizB[i]);
                matrizC[i] = matrizA[i] - matrizB[i];
                }
        for(int i = 0; i < 5; i++){
            printf("Os valores são: %d \n", matrizC[i]);
        }
return 0;
}