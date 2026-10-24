#include <stdio.h>
#include <stdlib.h>

typedef struct Personagem {
    int id;
    int nivel;
    struct Personagem *next;
} TPersonagem;

TPersonagem *fila = NULL;

void inserir(int id, int nivel)
{
    TPersonagem *novo = malloc(sizeof(TPersonagem));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novo->id = id;
    novo->nivel = nivel;
    novo->next = NULL;

    if (fila == NULL)
    {
        fila = novo;
        return;
    }
    TPersonagem *atual = fila;
    while (atual->next != NULL)
    {
        atual = atual->next;
    }
    atual->next = novo;
}

void buscar(int id)
{
    TPersonagem *atual = fila;
    while (atual != NULL)
    {

        if (atual->id == id)
        {
            printf("Personagem encontrado!\n");
            printf("ID: %d\n", atual->id);
            printf("Nivel: %d\n", atual->nivel);

            return;
        }

        atual = atual->next;
    }
    printf("Personagem nao encontrado.\n");
}

void deletar()
{
    if (fila == NULL)
    {
        printf("A fila esta vazia.\n");
        return;
    }

    TPersonagem *removido = fila;
    fila = fila->next;
    printf("Personagem %d removido da fila.\n",
           removido->id);
    free(removido);
}

void listar()
{
    TPersonagem *atual = fila;
    printf("\nFila:\n");
    while (atual != NULL)
    {
        printf("[ID: %d | Nivel: %d] -> ",
               atual->id,
               atual->nivel);

        atual = atual->next;
    }
    printf("NULL\n");
}

int main()
{
    inserir(101, 10);
    inserir(102, 20);
    inserir(103, 30);

    listar();

    buscar(102);

    deletar();
    listar();
    return EXIT_SUCCESS;
}