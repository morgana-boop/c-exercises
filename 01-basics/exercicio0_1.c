#include <stdio.h>

void valores()
{   int vect;
    printf("Digite quantidade de valores que iremos armazenar: ");
        scanf("%d", &vect);
        int numeros[vect];

    for (int i = 0; i < vect; i++)
    {
        printf("Digite %dº valor: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    for (int j = 0; j < vect; j++)
    {
        printf("Os valores exibidos são: %d\n", numeros[j]);
    }
    return;
}

int main()
{
    valores();
    return 0;
}