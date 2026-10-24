#include <stdio.h> //declação da biblioteca usada

    int main (){ // função principal que retorna um código inteiro indicando 
        double n1, n2, r1; //Variaveis definidas
        printf("Insira o primeiro valor: ");
        scanf("%lf", &n1); //guarda o resultado

        printf("Insira o segundo valor: ");
        scanf("%lf", &n2); //guarda o resultado

        r1 = n1 * n2; //leitura dos valor e efetuação do calculo
        
        printf("O resultado da multiplicação é: %.2lf \n", r1); //exibir o resultado

        return 0; //encerramento do programa
    }