#include <stdio.h>

/*
 * LABORATORIO 5 - REMOCAO CIRCULAR (aplicando o '%' na posicaoInicio)
 * ======================================================================
 *
 * A mesma formula do Laboratorio 4 vale para 'posicaoInicio':
 *
 *   posicaoInicio = (posicaoInicio + 1) % CAPACIDADE_MAXIMA
 *
 * Neste laboratorio vamos juntar insercao e remocao circulares pela
 * primeira vez, e provar que o espaco liberado por uma remocao
 * (que no Laboratorio 2 ficava "desperdicado" la atras no vetor)
 * agora e reaproveitado corretamente por uma insercao futura.
 */

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];
    int posicaoInicio;
    int posicaoFim;
} FilaParcial;

void inicializar(FilaParcial *fila) {
    fila->posicaoInicio = 0;
    fila->posicaoFim = -1;
}

void inserirCircular(FilaParcial *fila, int valor) {
    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
    printf("Inseri o valor %d na posicao %d.\n", valor, fila->posicaoFim);
}

void removerCircular(FilaParcial *fila) {
    int valorRemovido = fila->valores[fila->posicaoInicio];
    printf("Removi o valor %d, que estava na posicao %d.\n", valorRemovido, fila->posicaoInicio);

    fila->posicaoInicio = (fila->posicaoInicio + 1) % CAPACIDADE_MAXIMA;

    printf("   -> posicaoInicio avancou (com '%%') e agora e %d.\n", fila->posicaoInicio);
}

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 5\n");
    printf(" Remocao circular: aplicando o '%%' na posicaoInicio\n");
    printf("========================================\n\n");

    FilaParcial fila;
    inicializar(&fila);

    printf("Passo 1: inserir 5 valores para encher a fila (posicoes 0 a 4):\n\n");
    inserirCircular(&fila, 10);
    inserirCircular(&fila, 20);
    inserirCircular(&fila, 30);
    inserirCircular(&fila, 40);
    inserirCircular(&fila, 50);

    printf("\nPasso 2: remover 3 valores. Repare 'posicaoInicio' andando\n");
    printf("de 0 para 1, de 1 para 2, e assim por diante:\n\n");
    removerCircular(&fila);
    removerCircular(&fila);
    removerCircular(&fila);

    printf("\nPasso 3: inserir mais 3 valores. Como 'posicaoFim' tambem\n");
    printf("usa o modulo, ele vai reaproveitar as posicoes 0, 1 e 2,\n");
    printf("que ficaram livres depois das remocoes do Passo 2:\n\n");
    inserirCircular(&fila, 60);
    inserirCircular(&fila, 70);
    inserirCircular(&fila, 80);

    printf("\nCONCLUSAO DO LABORATORIO 5:\n");
    printf("Agora tanto a insercao quanto a remocao sabem 'dar a volta'\n");
    printf("no vetor. O espaco liberado no comeco do vetor por uma\n");
    printf("remocao passou a ser reaproveitado por uma insercao futura\n");
    printf("-- exatamente o que faltava desde o Laboratorio 2! Mas ainda\n");
    printf("falta resolver o problema de saber quando a fila esta cheia\n");
    printf("ou vazia de forma confiavel. E o assunto do proximo lab.\n");

    return 0;
}
