#include <stdio.h>
#define TAM 5

int pilha [TAM];
int quantidade = 0;

void criarPilha(){
    for(int i = quantidade; i < TAM; i++){
        printf("Digite %dº valor: \n", i+1);
        scanf("%d", &pilha[i]);
        quantidade++;
    }
}
void desPil(){
    printf("Valor removido: %d\n", pilha[quantidade - 1]);

    quantidade--;
}

void listar(){
    for(int i = 0; i < quantidade; i++){
        printf("Valores: %d\n", pilha[i]);
    }
}



int main(){
    int blk = 1;
    int opcao;
    while(blk == 1){
        printf("1)Guardar valor\n2)Desempilhar valor\n3)Listar valor\n4)Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                criarPilha();
            break;

            case 2:
                desPil();
            break;

            case 3:
                listar();
            break;

            case 4:
            blk = 0;
            break;
        }

    }
    return 0;
}