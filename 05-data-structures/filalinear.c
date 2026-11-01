#include <stdio.h>
#define TAM 5
int quantidade = 0;
int fila[TAM];

void gdValores(){
    for(int i = quantidade; i < TAM; i++){
        printf("Digite o %dº valor\n",i +1);
        scanf("%d", &fila[i]);
        quantidade ++;
    }
    return;
}

void delValores(){
    printf("Valor removido %d\n", fila[0]);
    for(int i = 0; i < quantidade - 1; i++){
        fila[i] = fila [i + 1];
    }
    quantidade --;
    return;
}

void bcValores(){
    int key;
    printf("Digite o valor da buscar: \n");
    scanf("%d", &key);
    for(int i = 0; i < quantidade; i++){
        if(key == fila[i]){
            printf("Valor encontrado na posição = %d\n", i);
            return;
        }
    }
    
}

void lsValores(){
    for(int i = 0; i < quantidade; i++){
        printf("Valor %d na posição %d\n", fila[i], i);
    }

}

int main(){
    int loop = 5;
    int response;
    while (loop = 5){
    printf("1) Inserir valor\n2) Deletar valor\n3) Buscar valor\n4) Listar valores\n0) Sair\n");
    scanf("%d", &response);
    if(response == 1){
        gdValores();
    }else if(response == 2){
        delValores();
    }else if(response == 3){
        bcValores();
    }else if(response == 4){
        lsValores();
    }else if(response == 0){
        loop = 0;
        return 0;
    }
    
    }
    return 0;
}