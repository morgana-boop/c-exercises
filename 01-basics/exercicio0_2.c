#include <stdio.h>

void armazenar(int *memoria, int val)
{
    for (int i = 0; i < val; i++)
    {
        printf("Digite %dº valor: ", i + 1);
        scanf("%d", &memoria[i]);
    }
    for (int j = 0; j < val; j++)
    {
        printf("Posição %d, dado %d.\n", j + 1, memoria[j]);
    }
    return;
}

void crescente(int *memoria, int val)
{
    int temp;
    for (int i = 0; i < val; i++)
    {
        for (int j = 1 + i; j < val; j++)
        {
            if(memoria[i] > memoria[j])
            {
                temp = memoria[i];
                memoria[i] = memoria[j];
                memoria[j]= temp;
            }
        }
    }
    return;
}

void decrescente(int *memoria, int val)
{
    int temp;
    for (int i = 0; i < val; i++)
    {
        for (int j = 1 + i; j < val; j++)
        {
            if(memoria[i] < memoria[j])
            {
                temp = memoria[i];
                memoria[i] = memoria[j];
                memoria[j]= temp;
            }
        }
    }
    return;
}

int soma (int *memoria, int val)
{
    int temp = 0;
    for(int i = 0; i < val; i++){
        temp = memoria[i] + temp;
    }
    return temp;
}

float media(int *memoria, int val)
{
    float media;
    int temp = 0;
    for(int i = 0; i < val; i++)
    {
        temp = memoria[i] + temp;
    }
    media = temp / val;
    return media;
}

int main()
{
    int val;
    int dec;

    printf("Digite o valor da quantidade algarismo: ");
    scanf("%d", &val);
    int memoria[val];
    armazenar(memoria, val);

    while (1)
    {
        printf("O que deseja?\n");
        printf("[1] Ordem crescente\n");
        printf("[2] Ordem decrescente\n");
        printf("[3] Soma\n");
        printf("[4] Media\n");
        printf("[0]Sair\n");
        scanf("%d", &dec);
        if (dec == 1)
        {
            crescente(memoria, val);
            for(int i = 0; i < val; i++)
            {
            printf("%dº Valor é: %d\n", i + 1, memoria[i]);
            }
        }
        if (dec == 2)
        {
            decrescente(memoria, val);
            for(int i = 0; i < val; i++)
            {
            printf("%dº Valor é: %d\n", i + 1, memoria[i]);
            }
        }
        if (dec == 3)
        {
            int resultado;
            resultado = soma(memoria, val);
            printf("Valor da soma é %d \n", resultado);
        }
        if (dec == 4)
        {
            float resultado;
            resultado = media(memoria, val);
            printf("Media dos valores é: %2.f\n", resultado);
        }
        if (dec > 4);
        {
            printf("Valor incorreto.");
        }

        if (dec == 0)
        {
            printf("Saindo");
            break;
        }
    }

    return 0;
}