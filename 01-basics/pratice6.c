#include <stdio.h>
#define VETOR 10
int box[VETOR];

void valores()
{
  for(int i = 0; i < 10; i++)
  {
    printf("Digite 10 valores");
    scanf("%d", &box[i]);
    return;
  }
}

void valf()
{
    int maior;
    int menor;

    maior = box[0];
    menor = box[0];
    for(int i = 0; i < VETOR; i++)
    {
        if(box[i] > maior)
        {
            maior = box[i];
        }
        if(box[i] < menor)
        {
            menor = box[i];
        }
    }
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    return;
}


int main()
{
    for(int i = 0; i < VETOR; i++)
    {
        printf("Digite 10 valores:");
        scanf("%d", &box[i]);
    }

    valores();
    valf();
    return 0;
}