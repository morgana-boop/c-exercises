#include <stdio.h>
#define TAM 5
int quantidade = 0;
int lista [5];

void criarLista(){
    for(int i = quantidade; i < TAM; i++){
        printf("Digite o %dº valor: ", i + 1);
        scanf("%d", &lista[i]);
        quantidade++;
    }

}

void remover() {
    int key;
    int posicao = -1;

    printf("Digite o valor que sera removido: ");
    scanf("%d", &key);

    for (int i = 0; i < quantidade; i++) {
        if (lista[i] == key) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Valor nao encontrado!\n");
        return;
    }

    for (int i = posicao; i < quantidade - 1; i++) {
        lista[i] = lista[i + 1];
    }
    quantidade--;

    printf("Valor removido!\n");
}

void listar(){
    for(int i = 0; i < TAM; i++){
        printf("Valores: %d\n", lista[i]);
    }
}





int main(){
    int blk = 1;
    int opcao;
    while(blk == 1){
        printf("1)Guardar valor\n2)Remover da Lista\n3)Mostrar valores\n4)Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                criarLista();
            break;

            case 2:
                desListar();
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