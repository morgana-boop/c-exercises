#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct Sfila{
    int info;
    struct SFila *next;
}TFila;

//sentinela
TFila *fila = NULL;

void enqueue(int dado){
    TFila *novo = malloc(sizeof(TFila));
    TFila *ultimo;
    novo->info = dado;
    novo->next = NULL;

    if (fila == NULL){
        fila = novo;
        return;
    }
    ultimo = fila;
    while (ultimo->next != NULL){
        ultimo = ultimo->next;
    }
    ultimo->next = novo;
}

int main(){

    return 0;
}

void dequeue(){
    TFila *aux;
    if (fila == NULL){
        printf("Fila vazia\n");
        return;
    }
    aux = fila;
    fila = fila->next;
    printf("Removido %d\n", aux->info);
    free(aux);
}

void buscar(int dado){
    TFila *aux;
    for (aux = fila; aux != NULL; aux = aux->next){
        if (aux->info == dado){
            printf("Valor encontrado %d\n", dado);
            return;
        }
    }
    printf("Valor não encontrado.");
}

int main(){

    return 0;
}