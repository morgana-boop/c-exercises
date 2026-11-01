#include <stdio.h>
int main(){
    int a, b, c, res;
        printf("Digite 3 valores A, B e C: \n");
        scanf("%d%d%d", a, b, c);
        res = a*a+b*b+c*c;
        printf("Valor da soma dos quadrados é: %d\n", res);
        
    return 0;
}