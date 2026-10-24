#include <stdio.h>

int soma(int numero1, int numero2)
{
    int res;
    res = numero1 + numero2;
    return res;
}
int main()
{
    int v1, v2;
    int resf;
    printf("Digite os 2 valores: ");
        scanf("%d%d", &v1, &v2);
        soma(v1, v2);
        resf = soma(v1, v2);
        printf("Resultado %d\n", resf);
    return 0;
}