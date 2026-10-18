#include <stdio.h>
#define TAM 5

int fila [5];
int quantidade = 0;

void criarFila(){
    for(int i = quantidade; i < TAM; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &fila[i]);
        quantidade++;
    }
}

void removerValor(){
    printf("Valor removido: %d\n", fila[0]);
    for(int i = 0; i < quantidade - 1; i++){
        fila[i] = fila[i + 1];
    }
    quantidade --;
}

void listarValor(){
    for(int i = 0; i < quantidade; i++){
        printf("%d\n", fila[i]);
    }
}

int main(){
    int bkl = 1;
    int opcao;

    while (bkl == 1){    
    printf("\n1) Adicionar valor\n2) Remover valor\n3) Listar valor\n4) sair\n");
    scanf("%d", &opcao);

        switch (opcao){
        case 1:
            criarFila();
            break;

        case 2:
            removerValor();
            break;

        case 3:
            listarValor();
            break;

        case 4:
            bkl = 0;
            break;

        }
    }
    return 0;

}
