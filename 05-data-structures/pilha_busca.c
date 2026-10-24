#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int pilha[TAM];
int topo = -1; /* -1 indica pilha vazia */

/* 1. PUSH - empilha um valor no topo da pilha */
void push(int stack[], int tamanho, int *topo, int dado){
  if (*topo == tamanho - 1){
    printf("Valor não inserido na pilha. Pilha cheia\n\n");
    return;
  }

  (*topo)++;
  stack[*topo] = dado;
}

/* 2. POP - remove e retorna o valor do topo da pilha */
int pop(int stack[], int *topo){
  int valor;

  if (*topo == -1){
    printf("Pilha vazia. Nada para remover\n\n");
    return -1;
  }

  valor = stack[*topo];
  (*topo)--;

  return valor;
}

/* 3. LISTAR - percorre a pilha do topo até a base */
void listar(int stack[], int topo){
  if (topo == -1){
    printf("Pilha vazia\n\n");
    return;
  }

  for (int i = topo; i >= 0; i--){
    printf("%d ", stack[i]);
  }

  printf("\n\n");
}

/* 4. BUSCAR - procura uma chave na pilha e retorna sua posição (ou -1) */
int buscar(int stack[], int topo, int chave){
  for (int i = topo; i >= 0; i--){
    if (chave == stack[i]){
      return i;
    }
  }

  return -1;
}


int main() {

  int leitura;
  while (1){

    printf("Informe o valor (0 para encerrar): ");
    scanf("%d", &leitura);
    if (leitura == 0)
      break;

    push(pilha, TAM, &topo, leitura);
  }

  printf("Pilha atual:\n");
  listar(pilha, topo);

  int removido;
  removido = pop(pilha, &topo);
  if (removido != -1)
    printf("Valor removido (pop): %d\n\n", removido);

  removido = pop(pilha, &topo);
  if (removido != -1)
    printf("Valor removido (pop): %d\n\n", removido);

  printf("Pilha após os pops:\n");
  listar(pilha, topo);

  printf("Informe o valor que deseja buscar: ");
  int key;
  scanf("%d", &key);
  int posicao = buscar(pilha, topo, key);
  if (posicao == -1){
    printf("Valor não encontrado\n");
  } else {
    printf("Valor encontrado na pilha, na posição %d\n", posicao);
  }

  return (EXIT_SUCCESS);
}
