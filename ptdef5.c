#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *anterior;
    struct No *proximo;
}No;

No *criarNo(){
    No *novo = malloc(sizeof(*novo));
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}


int main(){
    No *inicio = criarNo();
    inicio->valor = 90;
    printf("%d\n", inicio->valor);
    printf("%d\n", inicio->anterior);
    printf("%d\n", inicio->proximo);
    free(inicio);
return 0;
}
