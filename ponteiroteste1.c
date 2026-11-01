#include <stdio.h>

int main(){
    int a, b, c;
    int *p;
    a = 10;
    b = 20;
    c = 30;
    printf("Valor de a %d, b %d e c %d\n", a, b, c);
    p = &a;
    *p = 50;
    p = &b;
    *p = 60;
    p = &c;
    *p = 70;
    printf("\nValor de a %d, b %d e c %d\n", a, b, c);

    return 0;
}
