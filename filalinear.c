#include <stdio.h>
#define TAM 5
int quantidade = 0;
int fila [TAM];
void criarLista(){
    printf("Valores:\n");
    for(int i = 0; i < TAM; i++){
        scanf("%d", &fila[i]);
        quantidade ++;
    }
}
void listarLista(){
    printf("Lista:\n");
    for(int i = 0; i < quantidade; i++){
    printf("%d\n", fila[i]);
    }
}
void removerEl(){
    printf("Removendo: %d\n", fila[0]);
    for(int i = 0; i < quantidade -1; i++){
        fila[i] = fila[i + 1];
    }
    quantidade --;
}
int main (){0
    int dec = 0;
    while(dec == 0){
        criarLista();
        listarLista();
        removerEl();
        listarLista();
        break;
    }
    return 0;
}