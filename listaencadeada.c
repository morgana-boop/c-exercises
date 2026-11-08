#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No *topo = NULL;

void empilhar(int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return;
    }

    novo->valor = valor;
    novo->prox = topo;
    topo = novo;
}

void desempilhar() {
    if (topo == NULL) {
        return;
    }

    No *temp = topo;
    topo = topo->prox;
    free(temp);
}

void exibir() {
    No *atual = topo;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

int main() {
    empilhar(10);
    empilhar(20);
    empilhar(30);

    exibir();

    desempilhar();

    printf("\n");
    exibir();

    return 0;
}