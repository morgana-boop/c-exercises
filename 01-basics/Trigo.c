#include <stdio.h>

int main() {
    unsigned long long int graos = 1;
    unsigned long long int soma = 0;

    for (int i = 1; i <= 64; i++) {
        soma = soma + graos;
        graos = graos * 2;
    }

    printf("%llu\n", soma);

    return 0;
}