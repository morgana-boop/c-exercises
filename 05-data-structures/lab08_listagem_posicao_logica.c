#include <stdio.h>

/*
 * LABORATORIO 8 - LISTANDO A FILA: POSICAO LOGICA x POSICAO REAL
 * ====================================================================
 *
 * Ja sabemos inserir, remover e checar cheia/vazia corretamente.
 * Falta um detalhe: como IMPRIMIR todos os elementos validos, na
 * ordem certa (do mais antigo para o mais novo)?
 *
 * O problema e que, depois de varias insercoes e remocoes, os
 * dados validos podem ficar "quebrados" em dois pedacos dentro do
 * vetor: um pedaco no final do vetor e outro no comeco (por causa
 * da volta que 'posicaoFim' deu). Se a gente simplesmente imprimir
 * o vetor na ordem 0,1,2,3,4, a ordem sai errada.
 *
 * A solucao e distinguir dois conceitos:
 *
 *   - posicao LOGICA: a ordem "de negocio" (0 = mais antigo,
 *     1 = o proximo, e assim por diante) -- nao existe no vetor,
 *     e so um jeito de contar.
 *
 *   - posicao REAL: o indice de verdade dentro do vetor, onde o
 *     dado esta fisicamente guardado.
 *
 * A formula que traduz uma para a outra e:
 *
 *   posicaoReal = (posicaoInicio + posicaoLogica) % CAPACIDADE_MAXIMA
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

int filaEstaCheia(FilaCircular *fila) { return fila->quantidadeElementos == CAPACIDADE_MAXIMA; }
int filaEstaVazia(FilaCircular *fila) { return fila->quantidadeElementos == 0; }

void inserirCircular(FilaCircular *fila, int valor) {
    if (filaEstaCheia(fila)) return;
    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
    fila->quantidadeElementos++;
}

void removerCircular(FilaCircular *fila) {
    if (filaEstaVazia(fila)) return;
    fila->posicaoInicio = (fila->posicaoInicio + 1) % CAPACIDADE_MAXIMA;
    fila->quantidadeElementos--;
}

void mostrarVetorBruto(FilaCircular *fila) {
    printf("   Vetor por dentro (todas as %d posicoes): [ ", CAPACIDADE_MAXIMA);
    for (int i = 0; i < CAPACIDADE_MAXIMA; i++) {
        printf("%d ", fila->valores[i]);
    }
    printf("]\n");
    printf("   posicaoInicio=%d  posicaoFim=%d  quantidadeElementos=%d\n",
           fila->posicaoInicio, fila->posicaoFim, fila->quantidadeElementos);
}

// A funcao que este laboratorio existe para explicar.
void listarCircular(FilaCircular *fila) {
    if (filaEstaVazia(fila)) {
        printf("   Fila vazia, nada para listar.\n");
        return;
    }

    printf("   Elementos validos, do mais antigo para o mais novo: ");
    for (int posicaoLogica = 0; posicaoLogica < fila->quantidadeElementos; posicaoLogica++) {
        int posicaoReal = (fila->posicaoInicio + posicaoLogica) % CAPACIDADE_MAXIMA;
        printf("%d ", fila->valores[posicaoReal]);
    }
    printf("\n");
}

int main() {
    printf("========================================\n");
    printf(" LABORATORIO 8\n");
    printf(" Listando a fila: posicao LOGICA x posicao REAL\n");
    printf("========================================\n\n");

    FilaCircular fila;
    inicializar(&fila);

    printf("Passo 1: encher a fila com 10,20,30,40,50 e depois remover 3:\n\n");
    inserirCircular(&fila, 10);
    inserirCircular(&fila, 20);
    inserirCircular(&fila, 30);
    inserirCircular(&fila, 40);
    inserirCircular(&fila, 50);
    removerCircular(&fila);
    removerCircular(&fila);
    removerCircular(&fila);

    printf("Passo 2: inserir mais 3 valores (60,70,80). Isso faz\n");
    printf("'posicaoFim' dar a volta e passar a ser MENOR que\n");
    printf("'posicaoInicio':\n\n");
    inserirCircular(&fila, 60);
    inserirCircular(&fila, 70);
    inserirCircular(&fila, 80);

    mostrarVetorBruto(&fila);

    printf("\nRepare: posicaoInicio=%d e posicaoFim=%d. Dentro do VETOR,\n",
           fila.posicaoInicio, fila.posicaoFim);
    printf("os dados validos estao 'quebrados' em dois pedacos: um do\n");
    printf("indice %d ate o fim do vetor, e outro do comeco do vetor\n", fila.posicaoInicio);
    printf("ate o indice %d.\n\n", fila.posicaoFim);

    printf("Se imprimissemos 'valores[0]' ate 'valores[%d]' na ordem\n", CAPACIDADE_MAXIMA - 1);
    printf("crua do vetor, a ordem sairia ERRADA, e ainda apareceria\n");
    printf("'lixo' de posicoes ja removidas. Por isso a funcao\n");
    printf("'listarCircular' NAO percorre o vetor na ordem 0,1,2,3,4.\n");
    printf("Ela percorre 'quantidadeElementos' vezes, comecando em\n");
    printf("'posicaoInicio', e traduz cada posicao logica para a\n");
    printf("posicao real correspondente:\n\n");

    listarCircular(&fila);

    printf("\nCONCLUSAO DO LABORATORIO 8:\n");
    printf("Com essa 'traducao' de posicao logica para posicao real,\n");
    printf("conseguimos listar a fila na ordem certa mesmo quando os\n");
    printf("dados estao circularmente divididos em dois pedacos dentro\n");
    printf("do vetor. Com isso, temos TODAS as pecas que faltavam.\n");
    printf("No proximo laboratorio, juntamos tudo na fila circular final.\n");

    return 0;
}
