#include <stdio.h>
#define VETOR 5
int vetor[VETOR];
void valores()
{
    int valor;
    int posicao;

    for(int i = 0; i < 5; i++)
    {
        printf("Digite o valor: ");
        scanf("%d", &valor);

        printf("Qual posição será armazenado (0 a 4): ");
        scanf("%d", &posicao);

        vetor[posicao] = valor;
    }
}
void buscar()
{   
    int busca;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &busca);
        for(int i = 0; i < 5; i++)
        {
            if(busca == vetor[i])
            {
                printf("Valor na posição: %d\n", i);
            }
        }

}
void deletar()
{
    int infodel;
    printf("Digite informação que deseja remover: ");
    scanf("%d", &infodel);
    for(int i = 0; i < VETOR; i++)
    {
        if(infodel == vetor[i])
        {
            vetor[i] = 0;
        }
    }
        for(int i = 0; i < 5; i++)
        {
            printf("posição %d com valor armazenado: %d\n", i, vetor[i]);
        }
}
int main()
{
    valores();
    for(int i = 0; i < VETOR; i++)
    {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }
    buscar();
    deletar();

    return 0;
}