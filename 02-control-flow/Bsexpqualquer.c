#include <stdio.h>
int main(){
    unsigned long long int base;
    unsigned long long int exp;
    unsigned long long int resultado = 1;
        printf("Digite o valor da base: ");
            scanf("%llu", &base);
        printf("Digite o valor do expoente: ");
            scanf("%llu", &exp);
        for(int i = 1; i <= exp; i++){
            resultado = resultado * base;
        }
        printf("O valor da conta é: %llu\n", resultado);
            
return 0;
}