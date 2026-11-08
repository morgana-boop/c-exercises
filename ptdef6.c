#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
}No;

No *criarNo(){
    No *novo = malloc(sizeof(*novo));
    if(novo == NULL){
    printf("falha");
    }else
        novo->proximo = NULL;
        novo->anterior = NULL;
return novo;
}


int main(){
    No *inicio = criarNo();
    No *inicio2 = criarNo();
    No *inicio3 = criarNo();
    inicio->valor = 10;
    inicio2->valor = 20;
    inicio3->valor = 30;
    inicio->proximo = inicio2;
    inicio2->anterior = inicio;
    inicio2->proximo = inicio3;
    inicio3->anterior = inicio2;
    No *atual = inicio;
    while(atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
    atual->inicio = anterior;
    while(atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->anterior;
    }
return 0;
}
