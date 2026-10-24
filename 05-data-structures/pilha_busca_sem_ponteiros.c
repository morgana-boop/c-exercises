#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int fila[TAM];
int pilha[TAM]; // NOVA LINHA: Dominio de armazenamento exclusivo para a Pilha
int topo = -1;  // NOVA LINHA: Rastreador do ultimo elemento inserido (LIFO)

void enqueue(int queue[], int tamanho, int dado){
  int i;
  for (i = 0; i < tamanho; i++){
    if (queue[i] == 0){
      queue[i] = dado;
      return;
    }
  }

  if (i == tamanho)
    printf("Valor não inserido na fila. Fila cheia\n\n");
}

void listar(int queue[], int tamanho){
  for (int i = 0; i < tamanho; i++){
    if (queue[i] != 0)
      printf("%d ", queue[i]);
  }

  printf("\n\n");
}

void dequeue(int queue[], int tamanho){
  int i;
  for (i = 0; i < tamanho - 1; i++){
    queue[i] = queue[i + 1]; 
  }

  queue[tamanho - 1] = 0;
}

int buscar(int queue[], int tamanho, int chave){
  int i;
  for (i = 0; i < tamanho; i++){
    if (chave == queue[i]){
      return i;
    }
  }

  return -1;
}

// NOVA LINHA: Inicio da implementacao da funcao Push (Empilhar)
void push(int stack[], int tamanho, int dado){ // NOVA LINHA: Recebe a pilha e o dado
  if (topo >= tamanho - 1){ // NOVA LINHA: Verifica se o reino (pilha) esta sem espaco
    printf("Valor não inserido na pilha. Pilha cheia, majestade.\n\n"); // NOVA LINHA: Aviso de transbordamento
    return; // NOVA LINHA: Aborta a insercao
  } // NOVA LINHA: Fim da verificacao de capacidade
  topo++; // NOVA LINHA: Avanca o topo para o proximo espaco vazio
  stack[topo] = dado; // NOVA LINHA: Coroa o novo elemento no topo da pilha
} // NOVA LINHA: Fim da funcao push

// NOVA LINHA: Inicio da implementacao da funcao Pop (Desempilhar)
void pop(int stack[]){ // NOVA LINHA: Recebe apenas o array, remove o ultimo que entrou
  if (topo == -1){ // NOVA LINHA: Verifica se a pilha ja esta vazia
    printf("A pilha ja esta vazia, minha Rainha.\n\n"); // NOVA LINHA: Aviso ironico
    return; // NOVA LINHA: Aborta a remocao
  } // NOVA LINHA: Fim da verificacao de subfluxo
  stack[topo] = 0; // NOVA LINHA: Purga o valor do topo (zerando-o por consistencia)
  topo--; // NOVA LINHA: O topo retrocede para o elemento anterior
} // NOVA LINHA: Fim da funcao pop

// NOVA LINHA: Inicio da implementacao da funcao Listar da Pilha
void listar_pilha(int stack[]){ // NOVA LINHA: Lista respeitando a nobreza do LIFO
  for (int i = topo; i >= 0; i--){ // NOVA LINHA: Itera de tras para frente (do topo a base)
    if (stack[i] != 0) // NOVA LINHA: Ignora zeros, como a vossa fila original
      printf("%d ", stack[i]); // NOVA LINHA: Exibe os suditos
  } // NOVA LINHA: Fim do laco
  printf("\n\n"); // NOVA LINHA: Estetica visual
} // NOVA LINHA: Fim da funcao listar_pilha

// NOVA LINHA: Inicio da implementacao da funcao Buscar da Pilha
int buscar_pilha(int stack[], int chave){ // NOVA LINHA: Procura um valor especifico
  for (int i = topo; i >= 0; i--){ // NOVA LINHA: Busca priorizando quem chegou por ultimo
    if (chave == stack[i]){ // NOVA LINHA: Verifica se encontrou a chave
      return i; // NOVA LINHA: Retorna a posicao exata
    } // NOVA LINHA: Fim da condicional
  } // NOVA LINHA: Fim do laco
  return -1; // NOVA LINHA: Retorna -1 se o elemento ousar nao existir
} // NOVA LINHA: Fim da funcao buscar_pilha

int main() {

  int leitura;
  while (1){

    printf("Informe o valor: ");
    scanf("%d",&leitura);
    if (leitura == 0)
      break;

    enqueue(fila, TAM, leitura);
    push(pilha, TAM, leitura); // NOVA LINHA: Alimenta a nova pilha simultaneamente para testes
  }

  listar(fila, TAM);
  listar_pilha(pilha); // NOVA LINHA: Demonstra o conteudo da pilha (LIFO)

  dequeue(fila, TAM);
  pop(pilha); // NOVA LINHA: Remove o ultimo inserido da pilha

  dequeue(fila, TAM);
  pop(pilha); // NOVA LINHA: Remove outro elemento do topo da pilha

  listar(fila, TAM);
  listar_pilha(pilha); // NOVA LINHA: Mostra a disparidade entre a fila e a pilha atualizadas

  printf("Informe o valor que deseja buscar na fila original: ");
  int key;
  scanf("%d",&key);
  int posicao = buscar(fila, TAM, key);
  if (posicao == -1){
    printf("Valor não encontrado\n");
  }else{
    printf("Valor encontrado na fila\n");
  }

  // NOVA LINHA: Adicionando teste de busca para a pilha
  printf("Informe o valor que deseja buscar na PILHA: "); // NOVA LINHA: Solicita valor para a pilha
  scanf("%d",&key); // NOVA LINHA: Le a nova chave
  int posicao_pilha = buscar_pilha(pilha, key); // NOVA LINHA: Executa a vossa nova busca LIFO
  if (posicao_pilha == -1){ // NOVA LINHA: Se nao achar
    printf("Valor nao encontrado na pilha\n"); // NOVA LINHA: Imprime falha
  }else{ // NOVA LINHA: Caso contrario
    printf("Valor encontrado na pilha na posicao %d\n", posicao_pilha); // NOVA LINHA: Exalta o sucesso
  } // NOVA LINHA: Fim da estrutura condicional da busca

  return (EXIT_SUCCESS);
}