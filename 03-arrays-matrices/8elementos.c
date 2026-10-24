#include <stdio.h>
int main(){
    int matrizA[8];
    int matrizB[8];
    for(int i = 0; i < 8; i++){
        printf("Digite o %d valor da matriz A: \n", i);
            scanf("%d", &matrizA[i]);
    }   
    for(int i = 0; i < 8; i++){
        matrizB[i] = matrizA[i] * 3;
        printf("Os valores da posição %d da matriz B são: %d \n", i, matrizB[i]);
    }

return 0;
}