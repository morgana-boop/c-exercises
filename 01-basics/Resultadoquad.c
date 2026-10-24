#include <stdio.h>
int main(){
    int a, b, c, res, res2;
        printf("Digite 3 valores A, B e C: \n");
        scanf("%d%d%d", a, b, c);
        res = a + b + c;
        res2 = res * res;
        printf("Valor da soma das 3 variaveis elevado ao quadrado é: %d\n", res2);
        
    return 0;
}