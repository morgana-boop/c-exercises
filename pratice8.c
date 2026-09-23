#include <stdio.h>
int v1, v2;
void soma()
{
    printf("Digite 2 valores: ");
    scanf("%d%d", &v1, &v2);
    printf("Valores armazenados v1: %d\n v2: %d\n", v1, v2);
    return;
}
void troca()
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
    printf("novos valores v1: %d\n v2: %d\n", v1, v2);
    return;
}
int main()
{
    soma();
    troca();
    return 0;
}