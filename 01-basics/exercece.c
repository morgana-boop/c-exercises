#include <stdio.h>

void lista(int *vect, int val)
{
    for (int j = 0; j < val; j++)
    {
        printf("Valor da %dº posição é: %d\n", j + 1, vect[j]);
        
    }
    getchar();
    getchar();
}

void busca(int *vect, int val)
{
    int busca;
    printf("\n\n\nDigite o valor a ser buscado: ");
    scanf("%d", &busca);
    for(int i = 0; i < val; i++)
    {
        if(busca == vect[i])
        {
            printf("O valor esta na posição %d do vetor\n", i);
        }
    }
    getchar();
    getchar();
}

void dequeue(int *vect, int val)
{
    int fifo;
    printf("Quantos valores deseja remover (FIFO): ");
    scanf("%d", fifo);
    if(fifo < val)
    {
        
    }

}

int main()
{
    int val;
    printf("\n\n\nDigite quantidade de vetores: ");
    scanf("%d", &val);
    int vect[val];
    for (int i = 0; i < val; i++)
    {
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &vect[i]);
    }
        while (1)
        {
        int opcao;
        printf("[1] Listar valores\n");
        printf("[2] Buscar valores\n");
        printf("[3] Desenfileirar valores (FIFO)\n");
        printf("[4] Desempilhar valores\n");
        printf("[5] Enfileirar valores\n");
        printf("[6] Pilhar valores\n");
        printf("[0] Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            lista(vect, val);
            break;
        case 2:
            busca(vect, val);
            break;
        
        case 3:
            
            break;  

        case 4:
            
            break;

        case 5:

            break;

        case 6:

            break;

        case 0:
            return 0;
        }
    
    }
}