#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct SFila{
  int info;
  struct SFila * next;
} TFila;

//Sentinela
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


void dequeue(){
  TFila *aux;

  if (fila == NULL){printf("Fila vazia!\n");return;}

  aux = fila;
  fila = fila->next;

  printf("Removido: %d\n", aux->info);

  free(aux);
}


void buscar(int dado){
  TFila *aux;

  for (aux = fila; aux != NULL; aux = aux->next){

    if (aux->info == dado){
      printf("Valor %d encontrado!\n", dado);
      return;
    }
  }

  printf("Valor %d nao encontrado!\n", dado);
}


void deletar(int dado){
  TFila *aux;
  TFila *anterior;

  if (fila == NULL){
    printf("Fila vazia!\n");
    return;
  }

  // Caso o valor esteja no primeiro nó
  if (fila->info == dado){
    aux = fila;
    fila = fila->next;

    free(aux);

    printf("Valor %d deletado!\n", dado);
    return;
  }

  anterior = fila;
  aux = fila->next;

  while (aux != NULL){

    if (aux->info == dado){

      anterior->next = aux->next;
      free(aux);

      printf("Valor %d deletado!\n", dado);
      return;
    }

    anterior = aux;
    aux = aux->next;
  }

  printf("Valor %d nao encontrado!\n", dado);
}


void listar(){
  TFila *ultimo;

  for (ultimo = fila; ultimo != NULL; ultimo = ultimo->next){
    printf("%d ", ultimo->info);
  }

  printf("\n");
}


int main() {

  int leitura;

  while (1){

    printf("Informe o valor: ");
    scanf("%d",&leitura);

    if (leitura == 0)
      break;

    enqueue(leitura);
  }

  listar();

  printf("\n--- BUSCAR ---\n");
  buscar(3);

  printf("\n--- DEQUEUE ---\n");
  dequeue();
  listar();

  printf("\n--- DELETAR ---\n");
  deletar(4);
  listar();

  return (EXIT_SUCCESS);
}