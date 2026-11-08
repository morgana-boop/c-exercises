#include <stdio.h>
int main(){
    int x = 10;
    printf("Valor: %d\n", x);
    int *p = &x;
    printf("Endereço de X: %p\n", (void*)p);
    printf("O endereço de p: %p\n", (void *)&p);
    printf("O valor apontado por p: %d\n", *p);

    return 0;

}