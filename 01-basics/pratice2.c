#include <stdio.h>

int seque(int numero1, int numero2, int numero3)
{
    if(numero1 >= numero2 && numero1 >= numero3)
    {
        printf("Este numero é o maior 1(metodo): %d\n", numero1);
        return numero1;
    }
        if(numero2 >= numero1 && numero2 >= numero3)
    {
        printf("Este numero é o maior 2(metodo): %d\n", numero2);
        return numero2;
    }
        if(numero3 >= numero2 && numero3 >= numero1)
    {
        printf("Este numero é o maior 3(metodo): %d\n", numero3);
        return numero3;
    }
    return 0;
}
int main()
{
    int v1, v2, v3, resf;
    printf("Digite 3 valoers: \n");
    scanf("%d%d%d", &v1, &v2, &v3);
    resf = seque(v1, v2, v3);
    printf("Resultado: %d\n", resf);
    return 0;
}