#include <stdio.h>

/*
 * LABORATORIO 6 - A AMBIGUIDADE REAL: QUANDO 'INICIO' E 'FIM' NAO BASTAM
 * ==========================================================================
 *
 * Com insercao e remocao circulares funcionando (Labs 4 e 5), surge uma
 * pergunta pratica: como saber se a fila esta CHEIA ou VAZIA usando so
 * os indices 'posicaoInicio' e 'posicaoFim'?
 *
 * A primeira ideia que costuma vir a cabeca e comparar os dois indices
 * diretamente: "se posicaoInicio == posicaoFim, a fila esta vazia (ou
 * cheia)". Este laboratorio existe para TESTAR essa ideia na pratica e
 * descobrir qual e a relacao REAL entre os dois indices.
 */

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];
    int posicaoInicio;
    int posicaoFim;
} FilaComBug;

void inicializar(FilaComBug *fila) {
    fila->posicaoInicio = 0;
    fila->posicaoFim = -1;
}

void inserirCircular(FilaComBug *fila, int valor) {
    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
}

void removerCircular(FilaComBug *fila) {
    fila->posicaoInicio = (fila->posicaoInicio + 1) % CAPACIDADE_MAXIMA;
}

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 6\n");
    printf(" A ambiguidade real: quando inicio/fim nao bastam\n");
    printf("========================================\n\n");

    printf("TESTE 1: sera que 'posicaoInicio == posicaoFim' significa\n");
    printf("'fila vazia ou cheia'? Vamos inserir so 1 elemento e conferir:\n\n");

    FilaComBug filaComUm;
    inicializar(&filaComUm);
    inserirCircular(&filaComUm, 777);

    printf("   Depois de inserir 1 elemento: posicaoInicio=%d, posicaoFim=%d\n",
           filaComUm.posicaoInicio, filaComUm.posicaoFim);
    printf("   Eles SAO iguais -- mas a fila tem 1 elemento, nao esta nem\n");
    printf("   vazia nem cheia! Ou seja: 'inicio == fim' NAO serve como\n");
    printf("   teste de vazio/cheio. Ele so acontece quando a fila tem\n");
    printf("   EXATAMENTE 1 elemento (o mesmo indice e o mais antigo e o\n");
    printf("   mais novo ao mesmo tempo).\n\n");

    printf("TESTE 2: entao qual e a relacao REAL entre 'inicio' e 'fim'\n");
    printf("quando a fila esta vazia, e quando esta cheia? Vamos comparar:\n\n");

    FilaComBug filaVazia;
    inicializar(&filaVazia);
    inserirCircular(&filaVazia, 999);
    removerCircular(&filaVazia);

    printf("   CASO VAZIA (inserir 1, depois remover 1):\n");
    printf("      posicaoInicio=%d, posicaoFim=%d\n", filaVazia.posicaoInicio, filaVazia.posicaoFim);

    FilaComBug filaCheia;
    inicializar(&filaCheia);
    for (int i = 0; i < CAPACIDADE_MAXIMA; i++) {
        inserirCircular(&filaCheia, i * 10);
    }

    printf("   CASO CHEIA (inserir %d vezes, a capacidade toda):\n", CAPACIDADE_MAXIMA);
    printf("      posicaoInicio=%d, posicaoFim=%d\n\n", filaCheia.posicaoInicio, filaCheia.posicaoFim);

    printf("Repare que, nos dois casos, 'posicaoInicio' e igual a\n");
    printf("'(posicaoFim + 1) %% CAPACIDADE_MAXIMA'. Vamos confirmar isso\n");
    printf("com codigo, em vez de so olhar os numeros:\n\n");

    int testeVazia = (filaVazia.posicaoInicio == (filaVazia.posicaoFim + 1) % CAPACIDADE_MAXIMA);
    int testeCheia = (filaCheia.posicaoInicio == (filaCheia.posicaoFim + 1) % CAPACIDADE_MAXIMA);

    printf("   CASO VAZIA -> posicaoInicio == (posicaoFim+1) %% CAPACIDADE?  %s\n",
           testeVazia ? "SIM" : "nao");
    printf("   CASO CHEIA -> posicaoInicio == (posicaoFim+1) %% CAPACIDADE?  %s\n",
           testeCheia ? "SIM" : "nao");

    printf("\nCONCLUSAO DO LABORATORIO 6:\n");
    printf("A relacao 'posicaoInicio == (posicaoFim + 1) %% CAPACIDADE_MAXIMA'\n");
    printf("da VERDADEIRO nos dois casos -- vazia E cheia. Ou seja, usando\n");
    printf("apenas os indices, ate da para perceber que a fila esta em UM\n");
    printf("DOS DOIS extremos, mas NAO da para saber QUAL DOS DOIS. Falta\n");
    printf("uma informacao extra, guardada a parte, para desempatar essa\n");
    printf("duvida. No proximo laboratorio resolvemos isso com um contador\n");
    printf("de elementos.\n");

    return 0;
}
