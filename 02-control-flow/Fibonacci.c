#include <stdio.h>
int main(){
    unsigned long long int anterior = 0;
    unsigned long long int atual = 1;
    unsigned long long int proximo;
    for (int i = 1; i <= 150; i++){
        proximo = atual + anterior;
        anterior = atual;
        atual = proximo;
        printf("%llu\n", proximo);
    }   
    return 0;
}