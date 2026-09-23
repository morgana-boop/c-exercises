#include <stdio.h>

int main()
{
    int vetor[10];
    int soma = 0;
    int *ponteiro = vetor;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        soma = soma + *ponteiro;
        ponteiro++;
    }

    printf("Soma: %d\n", soma);

    return 0;
}