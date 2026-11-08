#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;
typedef struct Lista {
    No *inicio;
    No *fim;
    int tamanho;
}Lista;

void inicializarLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int inserirFinal(Lista *lista, int valor){
    No *novo = malloc(sizeof(*novo));
    if (novo == NULL){return 0;}
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if(lista->fim == NULL){
       lista->inicio = novo;
    }else{
        lista->fim->proximo = novo;
    }
    lista->fim = novo;
    lista->tamanho++;

    return 1;

}

void imprimirFrente(Lista *lista){
    No *atual = lista->inicio;
    while (atual != NULL){
        printf("%d", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}


void imprimirTras(Lista *lista){
    No *atual = lista->fim;
    while (atual != NULL){
        printf("%d", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

void liberarLista(Lista *lista){
    No *atual = lista->inicio;

        while (atual != NULL){
            No *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        inicializarLista(lista);
}
    
