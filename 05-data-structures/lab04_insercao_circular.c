#include <stdio.h>

/*
 * LABORATORIO 4 - INSERCAO CIRCULAR (aplicando o '%' na posicaoFim)
 * ====================================================================
 *
 * Agora que entendemos a matematica do modulo isoladamente (Lab 3),
 * vamos aplica-la de verdade na insercao da fila. A formula e:
 *
 *   posicaoFim = (posicaoFim + 1) % CAPACIDADE_MAXIMA
 *
 * Vamos inserir MAIS elementos do que a capacidade do vetor de
 * proposito, so para observar o indice "dando a volta" na pratica.
 * De propósito, esta versao AINDA NAO verifica se a fila esta
 * cheia -- isso e assunto do Laboratorio 7. Aqui o foco e 100% na
 * formula da posicao.
 */

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];
    int posicaoFim;
} FilaParcial;

void inicializar(FilaParcial *fila) {
    fila->posicaoFim = -1;
}

void inserirCircular(FilaParcial *fila, int valor) {
    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
    printf("Inseri o valor %d na posicao %d do vetor.\n", valor, fila->posicaoFim);
}

void mostrarVetorBruto(FilaParcial *fila) {
    printf("   Vetor por dentro: [ ");
    for (int i = 0; i < CAPACIDADE_MAXIMA; i++) {
        printf("%d ", fila->valores[i]);
    }
    printf("]\n");
}

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 4\n");
    printf(" Insercao circular: aplicando o '%%' na posicaoFim\n");
    printf("========================================\n\n");

    FilaParcial fila;
    inicializar(&fila);

    printf("Formula usada para avancar 'posicaoFim':\n");
    printf("   posicaoFim = (posicaoFim + 1) %% CAPACIDADE_MAXIMA\n\n");
    printf("Vamos inserir 7 valores seguidos (mais do que a capacidade\n");
    printf("de %d) so para observar o indice dando a volta:\n\n", CAPACIDADE_MAXIMA);

    int valoresParaInserir[] = {100, 200, 300, 400, 500, 600, 700};

    for (int i = 0; i < 7; i++) {
        inserirCircular(&fila, valoresParaInserir[i]);
        mostrarVetorBruto(&fila);
    }

    printf("\nCONCLUSAO DO LABORATORIO 4:\n");
    printf("Repare que quando 'posicaoFim' chegou em 4 (o ultimo indice\n");
    printf("valido do vetor) e inserimos de novo, ele voltou para 0\n");
    printf("sozinho -- e sobrescreveu o valor 100 com o valor 600!\n\n");
    printf("Isso e ESPERADO na formula da posicao, mas expoe um problema\n");
    printf("NOVO: esta versao ainda nao verifica se a fila estava cheia\n");
    printf("antes de inserir, entao ela aceita inserir por cima de dados\n");
    printf("validos sem avisar ninguem. Vamos resolver isso mais a\n");
    printf("frente com um contador de elementos. Por enquanto, o\n");
    printf("objetivo era so dominar a formula da posicao circular.\n");

    return 0;
}
