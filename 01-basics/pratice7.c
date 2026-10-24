#include <stdio.h>
#define VETOR 10
int box[VETOR];

void valores()
{
  for(int i = 0; i < VETOR; i++)
  {
    printf("Digite valor que vai ficar na posição %d do vetor: ", i);
    scanf("%d", &box[i]);
  }
   return;
}

void invert()
{
    int temp; 
    for (int i = 0; i < VETOR / 2; i++) 
    {
        temp = box[i]; 
        box[i] = box[VETOR - 1 - i]; 
        box[VETOR - 1 - i] = temp; 
        
    }
    for(int i = 0; i < VETOR; i++)
    {
        printf("posição do vetor %d e valor %d \n",i, box[i]);
    }
    return;
}
int main()
{
    valores();
    invert();
    return 0;
}