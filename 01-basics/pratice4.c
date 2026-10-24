#include <stdio.h>
void meme(int num)
{
    for(int i = 1; i <= num; i++)
    {
        printf("%d, ",i);
    }
    return;
}
int main()
{
    int v1;
    printf("Digite a quantidade numeros ser exibida: ");
        scanf("%d", &v1);
    meme(v1);
    return 0;
}