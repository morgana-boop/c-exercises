#include <stdio.h>

int somar(int numero1, int numero2){
    int soma;
    soma = numero1 + numero2;
    return soma;
}
int main(){
    int valor1, valor2;
    printf("digite 2 merda: ");
    scanf("%d%d", &valor1, &valor2);
    int res =  somar(valor1, valor2);
    printf("valor é %d\n", res);
    return 0;
}