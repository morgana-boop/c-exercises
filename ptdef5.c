#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *anterior;
    struct No *proximo;
} No;

No *criarNo(){
    No *novo = malloc(sizeof(*novo));
    if(novo == NULL){
    printf("Erro");
    }else
        printf("\nAlocado");
        return novo;

}

int main (){
    criarNo();

return 0;
}
