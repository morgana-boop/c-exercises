#include <stdio.h>
#include <string.h>
    int main(){
        char nome[50];
        char sexo;
            printf("Digite seu nome: ");
                scanf("%s", nome);
            printf("Digite seu sexo (m/f): ");
                scanf(" %c", &sexo);
            if (sexo == 'm' || sexo =='M')
            {
                printf("Seja bem vindo Sr. %s\n", nome);
            }
            else if (sexo == 'f' || sexo =='F')
            {
                 printf("Seja bem vinda Sra. %s\n", nome);
            }
            else {
                printf("digite um sexo valido");
            }
    return 0;
    }