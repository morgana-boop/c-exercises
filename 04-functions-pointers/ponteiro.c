#include <stdio.h>

void cofre(int *recebido){
    *recebido = *recebido * 5;
}

int main (){
    int tesouro = 10;
    int *mapatesouro = &tesouro;
    cofre(mapatesouro);
    printf("Valor real do tesouro é: %d \n", *mapatesouro);
    printf("Valor da variavel na memoria é: %d\n", cofre);
    return 0;
}