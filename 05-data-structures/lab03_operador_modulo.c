#include <stdio.h>

/*
 * LABORATORIO 3 - ENTENDENDO O OPERADOR '%' (RESTO DA DIVISAO)
 * ================================================================
 *
 * Antes de aplicar o modulo dentro da struct da fila, vamos isolar
 * completamente essa ideia -- este laboratorio nem tem fila nenhuma,
 * so o calculo puro. E fundamental entender isso a fundo antes de
 * seguir, porque toda a "magica" da fila circular mora aqui.
 */

#define TAMANHO_DO_CIRCULO 5

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 3\n");
    printf(" O operador '%%' antes de aplica-lo em uma fila\n");
    printf("========================================\n\n");

    printf("Imagine um relogio com apenas %d numeros nele: 0, 1, 2, 3, 4.\n", TAMANHO_DO_CIRCULO);
    printf("Depois do 4, o proximo NAO e o 5 -- e o 0 de novo!\n\n");

    printf("O operador '%%' calcula o RESTO de uma divisao. Por exemplo:\n");
    printf("   7 dividido por 5 da 1, e sobra 2  -> 7 %% 5 = 2\n");
    printf("   10 dividido por 5 da 2, e sobra 0 -> 10 %% 5 = 0\n\n");

    printf("Vamos contar de 0 ate 14 e, para cada numero, calcular\n");
    printf("'numero %% %d' (le-se 'resto da divisao de numero por %d'):\n\n", TAMANHO_DO_CIRCULO, TAMANHO_DO_CIRCULO);

    for (int numero = 0; numero <= 14; numero++) {
        int posicaoNoCirculo = numero % TAMANHO_DO_CIRCULO;
        printf("   %2d %% %d = %d", numero, TAMANHO_DO_CIRCULO, posicaoNoCirculo);
        if (posicaoNoCirculo == 0 && numero != 0) {
            printf("   <-- voltou para o comeco do circulo!");
        }
        printf("\n");
    }

    printf("\nREPARE: nao importa o quanto o numero cresca (5, 10, 14...),\n");
    printf("o resultado de 'numero %% %d' SEMPRE fica entre 0 e %d.\n", TAMANHO_DO_CIRCULO, TAMANHO_DO_CIRCULO - 1);
    printf("Nunca sai desse intervalo. E EXATAMENTE isso que precisamos\n");
    printf("para fazer um indice de vetor 'dar a volta' em vez de sair\n");
    printf("dos limites validos do vetor.\n\n");

    printf("Um segundo detalhe importante: para 'andar para tras' de\n");
    printf("forma circular (por exemplo, ir do indice 0 para o indice 4),\n");
    printf("nao podemos simplesmente calcular '(0 - 1) %% 5', porque em C\n");
    printf("isso da um numero NEGATIVO (-1), e nao 4 como esperariamos:\n\n");

    int resultadoErrado = (0 - 1) % TAMANHO_DO_CIRCULO;
    printf("   (0 - 1) %% %d = %d   <-- negativo, nao serve como indice!\n", TAMANHO_DO_CIRCULO, resultadoErrado);

    int resultadoCerto = (0 - 1 + TAMANHO_DO_CIRCULO) % TAMANHO_DO_CIRCULO;
    printf("   (0 - 1 + %d) %% %d = %d   <-- somando o tamanho antes, da certo\n",
           TAMANHO_DO_CIRCULO, TAMANHO_DO_CIRCULO, resultadoCerto);

    printf("\nCONCLUSAO DO LABORATORIO 3:\n");
    printf("Guarde essas duas formulas, elas sao o coracao de tudo que\n");
    printf("vem a seguir:\n");
    printf("   avancar um indice:  indice = (indice + 1) %% CAPACIDADE\n");
    printf("   recuar um indice:   indice = (indice - 1 + CAPACIDADE) %% CAPACIDADE\n");

    return 0;
}
