#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int fila[TAM];

void enqueue(int queue[], int tamanho, int dado)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    if (queue[i] == 0)
    {
      queue[i] = dado;
      return;
    }
  }

  if (i == tamanho)
    printf("Valor não inserido na fila. Fila cheia\n\n");
}

void listar(int queue[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    if (queue[i] != 0)
      printf("%d ", queue[i]);
  }

  printf("\n\n");
}

void dequeue(int queue[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho - 1; i++)
  {
    queue[i] = queue[i + 1];
  }

  queue[tamanho - 1] = 0;
}

int buscar(int queue[], int tamanho, int chave)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    if (chave == queue[i])
    {
      return i;
    }
  }

  return -1;
}

int main()
{

  int leitura;
  while (1)
  {

    printf("Informe o valor: ");
    scanf("%d", &leitura);
    if (leitura == 0)
      break;

    enqueue(fila, TAM, leitura);
  }

  listar(fila, TAM);
  dequeue(fila, TAM);
  dequeue(fila, TAM);
  listar(fila, TAM);

  printf("Informe o valor que deseja buscar: ");
  int key;
  scanf("%d", &key);
  int posicao = buscar(fila, TAM, key);
  if (posicao == -1)
  {
    printf("Valor não encontrado");
  }
  else
  {
    printf("Valor encontrado na fila");
  }

  return (EXIT_SUCCESS);
}
