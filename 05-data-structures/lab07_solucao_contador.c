#include <stdio.h>

/*
 * LABORATORIO 7 - RESOLVENDO A AMBIGUIDADE COM 'quantidadeElementos'
 * ======================================================================
 *
 * A solucao para o problema do Laboratorio 6 e simples: em vez de
 * tentar adivinhar o estado da fila comparando 'posicaoInicio' com
 * 'posicaoFim', vamos guardar numa variavel SEPARADA quantos
 * elementos existem agora. Essa variavel:
 *
 *   - comeca em 0
 *   - sobe 1 a cada insercao bem-sucedida
 *   - desce 1 a cada remocao bem-sucedida
 *
 * Ela nunca depende de calculo com indices, entao nunca gera a
 * ambiguidade que vimos no laboratorio anterior.
 */

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];
    int posicaoInicio;
    int posicaoFim;
    int quantidadeElementos;
} FilaCircular;

void inicializar(FilaCircular *fila) {
    fila->posicaoInicio = 0;
    fila->posicaoFim = -1;
    fila->quantidadeElementos = 0;
}

int filaEstaCheia(FilaCircular *fila) {
    return fila->quantidadeElementos == CAPACIDADE_MAXIMA;
}

int filaEstaVazia(FilaCircular *fila) {
    return fila->quantidadeElementos == 0;
}

void inserirCircular(FilaCircular *fila, int valor) {
    if (filaEstaCheia(fila)) {
        printf("ERRO: fila cheia (quantidadeElementos=%d), nao vou inserir %d.\n",
               fila->quantidadeElementos, valor);
        return;
    }
    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
    fila->quantidadeElementos++;
    printf("Inseri %d na posicao %d. (quantidadeElementos agora = %d)\n",
           valor, fila->posicaoFim, fila->quantidadeElementos);
}

void removerCircular(FilaCircular *fila) {
    if (filaEstaVazia(fila)) {
        printf("ERRO: fila vazia, nao ha nada para remover.\n");
        return;
    }
    int valorRemovido = fila->valores[fila->posicaoInicio];
    fila->posicaoInicio = (fila->posicaoInicio + 1) % CAPACIDADE_MAXIMA;
    fila->quantidadeElementos--;
    printf("Removi %d. (quantidadeElementos agora = %d)\n", valorRemovido, fila->quantidadeElementos);
}

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 7\n");
    printf(" Resolvendo a ambiguidade com 'quantidadeElementos'\n");
    printf("========================================\n\n");

    FilaCircular fila;
    inicializar(&fila);

    printf("Repetindo o CASO A do Laboratorio 6 (inserir 1, remover 1):\n\n");
    inserirCircular(&fila, 999);
    removerCircular(&fila);
    printf("   filaEstaVazia? %s   filaEstaCheia? %s\n\n",
           filaEstaVazia(&fila) ? "SIM" : "nao",
           filaEstaCheia(&fila) ? "SIM" : "nao");

    printf("Repetindo o CASO B do Laboratorio 6 (encher a fila totalmente):\n\n");
    FilaCircular filaCheia;
    inicializar(&filaCheia);
    for (int i = 0; i < CAPACIDADE_MAXIMA; i++) {
        inserirCircular(&filaCheia, (i + 1) * 10);
    }
    printf("   filaEstaVazia? %s   filaEstaCheia? %s\n\n",
           filaEstaVazia(&filaCheia) ? "SIM" : "nao",
           filaEstaCheia(&filaCheia) ? "SIM" : "nao");

    printf("Agora, diferente do Laboratorio 4, tentar inserir numa fila\n");
    printf("cheia gera um erro CONTROLADO, em vez de sobrescrever dados\n");
    printf("por baixo dos panos:\n\n");
    inserirCircular(&filaCheia, 9999);

    printf("\nCONCLUSAO DO LABORATORIO 7:\n");
    printf("Com 'quantidadeElementos', 'filaEstaVazia' e 'filaEstaCheia'\n");
    printf("agora dao a resposta CERTA em todos os casos, sem nenhuma\n");
    printf("ambiguidade -- e ainda ganhamos de brinde uma checagem de\n");
    printf("seguranca antes de inserir ou remover. O 'motor' da fila\n");
    printf("circular ja esta pronto e correto.\n");

    return 0;
}
