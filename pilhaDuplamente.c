#include <stdio.h>
#include <stdlib.h>

typedef struct SPilha {
    int info;
    struct SPilha *prox;
    struct SPilha *ant;
} TPilha;

TPilha *topo = NULL;

void push(int dado) {
    TPilha *novo = malloc(sizeof(TPilha));

    if (novo == NULL)
        return;

    novo->info = dado;
    novo->prox = NULL;
    novo->ant = topo;

    if (topo != NULL)
        topo->prox = novo;

    topo = novo;
}

void listar() {
    TPilha *atual = topo;

    printf("\nListando:\n");

    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->ant;
    }
}

TPilha *buscar(int chave) {
    TPilha *atual = topo;

    while (atual != NULL) {
        if (atual->info == chave)
            return atual;

        atual = atual->ant;
    }

    return NULL;
}

int main() {
    int leitura, chave;
    TPilha *posicao;

    while (1) {
        printf("Informe o valor: ");

        if (scanf("%d", &leitura) != 1 || leitura == 0)
            break;

        push(leitura);
    }

    listar();

    printf("\n\nInforme o valor da busca: ");

    if (scanf("%d", &chave) != 1)
        return 0;

    posicao = buscar(chave);

    if (posicao == NULL)
        printf("Valor nao encontrado\n");
    else
        printf("Valor encontrado no endereco %p\n", (void *)posicao);

    return 0;
}