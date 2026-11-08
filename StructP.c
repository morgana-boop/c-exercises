#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int pocao;
    int espada;
    int machado;
} Inventario;

typedef struct {
    char nome[50];
    Inventario *inventario;
} Personagem;

int main(){
    Personagem *personagem;
    personagem = malloc(sizeof(Personagem));
    strcpy(personagem->nome, "Morgana");
    personagem->inventario = malloc(sizeof(Inventario));
    personagem->inventario->pocao = 4;
    personagem->inventario->espada = 2;
    personagem->inventario->machado = 1;
    printf("Dados\nNome: %s\nPoções: %d\nEspada: %d\nMachado: %d\n",personagem->nome, personagem->inventario->pocao, personagem->inventario->machado, personagem->inventario->espada);
    


    return 0;
}
