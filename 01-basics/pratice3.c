#include <stdio.h>

void num(int num1)
{
    if (num1 % 2 == 0)
    {
        printf("Numero par\n");
        return;
    }
    else
    {
        printf("Numero impar\n");
        return;
    }
}
int main ()
{
    printf("Digite valor:");
    int val;
    scanf("%d", &val);
    num(val);
    return 0;
}