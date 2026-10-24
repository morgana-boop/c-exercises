#include <stdio.h>
#include <string.h>

typedef struct { 
char titulo[50]; 
int exemplares;
 double preco; } 
Livro;

Livro Livro_criar(const char* tituloInicial, int exemplaresIniciais, double precoInicial){
    Livro l; strcpy(l.titulo, tituloInicial);
    l.exemplares = exemplaresIniciais; l.preco = precoInicial; return l;
}

int main(void){
    Livro romance = Livro_criar("Dom Casmurro", 8, 12.0);
    Livro poesia = Livro_criar("Antologia poética", 8, 45.0);
    printf("%d\n", romance.exemplares); 
    printf("%s\n", poesia.titulo); 
return 0;
}