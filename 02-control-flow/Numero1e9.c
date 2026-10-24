#include <stdio.h>
    int main(){
        int a;
            printf("Digite um valor inteiro qualquer: ");
                scanf("%d", &a);
            if (a > 1 && a < 9) {
                printf("O valor esta dentro do permitido ( 1 e 9)");
            } else {
                printf("O valor nao esta dentro do permitido");
            }
    return 0;
    }