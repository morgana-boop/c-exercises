#include <stdio.h>
void meme(int num)
{
    int res = 0;
    for(int i = 1; i <= num; i++)
    {
        res = res + i;
        
    }
    printf("soma total: %d",res);
    return;
}
int main()
{
    int v1;
    printf("Digite a quantidade numeros ser somado: ");
        scanf("%d", &v1);
    meme(v1);
    return 0;
}