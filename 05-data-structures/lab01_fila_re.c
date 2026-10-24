#include <stdio.h>
#define VETOR 5
int fila[VETOR];
int quantidadeMax = 0;

void valor(int num)
{
    if(quantidadeMax == VETOR)
    {
        printf("Memoria cheia caralho, valor %d nao inserido.\n", num);
        return;
    }
    fila[quantidadeMax] = num;
    quantidadeMax++;
    printf("Adicionado %d\n", num);
}

void listar()
{
    for(int i = 0; i < quantidadeMax; i++)
    {
        printf("Valor %d na posição %d\n", fila[i], i);
    }
}

void removerFila()
{
    int remoVal;
    remoVal = fila[0];
    printf("Valor %d da posição %d sera removido.\n", remoVal, fila[0]);
    for(int i = 0; i < quantidadeMax - 1; i++)
    {
        fila[i] = fila[i + 1];
        printf("valor que estava na posicao %d para a posicao %d (valor %d)\n", i + 1, i, fila[i]);
    }
    quantidadeMax --;

}


int main ()
{
    printf("Adicionando...\n");
    valor(10);
    valor(20);
    valor(30);
    valor(40);
    valor(530);
    valor(4124);

    listar();
    printf("Removendo valor da primeira posição.");
    removerFila();

    return 0;
}