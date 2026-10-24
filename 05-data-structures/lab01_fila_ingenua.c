#include <stdio.h>

/*
 * LABORATORIO 1 - O PROBLEMA DA FILA "INGENUA"
 * =============================================
 *
 * Antes de aprender a fila circular, precisamos SENTIR o problema
 * que ela resolve. Aqui vamos implementar uma fila da forma mais
 * simples possivel: um vetor, e um contador de quantos elementos
 * existem. Quando removemos o primeiro elemento, todo o resto do
 * vetor precisa "andar" uma casa para tras.
 *
 * Fique atento ao numero de operacoes que a funcao de remocao
 * precisa fazer -- isso e o que vamos eliminar nos proximos labs.
 */

#define CAPACIDADE_MAXIMA 5

int fila[CAPACIDADE_MAXIMA];
int quantidadeElementos = 0;

// Insere sempre na "proxima posicao livre", contada a partir do 0.
void inserir(int valor) {
    if (quantidadeElementos == CAPACIDADE_MAXIMA) {
        printf("ERRO: fila cheia, nao foi possivel inserir %d.\n", valor);
        return;
    }
    fila[quantidadeElementos] = valor;
    quantidadeElementos++;
    printf("Inseri o valor %d no final da fila.\n", valor);
}

void mostrarFila() {
    printf("   Fila atual: ");
    for (int i = 0; i < quantidadeElementos; i++) {
        printf("%d ", fila[i]);
    }
    printf("\n");
}

// Remove sempre o elemento da posicao 0 (o mais antigo).
// Repare no CUSTO: para que a posicao 0 continue sendo sempre
// o "proximo a sair", TODO o resto do vetor precisa se mover.
void removerIngenuo() {
    if (quantidadeElementos == 0) {
        printf("ERRO: fila vazia, nao ha nada para remover.\n");
        return;
    }

    int valorRemovido = fila[0];

    printf("Removendo o valor %d, que estava na posicao 0.\n", valorRemovido);
    printf("Para a posicao 0 continuar sendo sempre 'o proximo a sair',\n");
    printf("cada elemento restante precisa andar uma casa para tras:\n");

    int movimentos = 0;
    for (int i = 0; i < quantidadeElementos - 1; i++) {
        fila[i] = fila[i + 1];
        movimentos++;
        printf("   -> mexi o valor que estava na posicao %d para a posicao %d\n", i + 1, i);
    }

    quantidadeElementos--;

    printf("   Total de elementos movidos so para tirar 1 elemento: %d\n", movimentos);
}

int main() {
    printf("Passo 1: inserir 4 valores.\n\n");
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(40);
    mostrarFila();

    printf("\nPasso 2: remover 1 elemento e observar o custo.\n\n");
    removerIngenuo();

    printf("\nFila depois da remocao:\n");
    mostrarFila();

    printf("\nCONCLUSAO DO LABORATORIO 1:\n");
    printf("Para remover UM UNICO elemento do inicio, tivemos que mover\n");
    printf("TODOS os outros elementos de lugar. Se a fila tivesse 1 milhao\n");
    printf("de elementos guardados, remover o primeiro custaria 1 milhao\n");
    printf("de movimentos! Isso e chamado de complexidade O(n) (o custo\n");
    printf("cresce junto com o tamanho da fila) e e exatamente o que\n");
    printf("queremos evitar. No proximo laboratorio vamos ver como usar\n");
    printf("'indices' para resolver isso sem mover nada.\n");

    return 0;
}
