#include <stdio.h>

int main (){
    int bol;
        printf("Digite Quantos vetores teremos: ");
            scanf("%d", &bol);
            int vect[bol];
        for(int i = 0; i < bol; i++){
            printf("Digite um valor: ");
            scanf("%d", &vect[i]);        
        }
        for(int i = 0; i < bol; i++){
            printf("Valor da posição %d é %d\n", i, vect[i]);
        }
        int valor_busca;
        printf("Digite quantos valores deseja buscar: ");
            scanf("%d", &valor_busca);
                if(valor_busca <= bol){
                    int valor[valor_busca];
                    for(int j = 0; j < valor_busca; j++){
                        printf("Digite os valores: ");
                            scanf("%d", &valor[j]);
                            printf("Valores que deseja buscar armazenados na posição %d é %d\n", j, valor[j]);
                            for(int i = 0; i < bol; i++){
                                if(valor[j]==vect[i]){
                                    printf("O valor esta na posição %d do vetor, dado que esta la: (%d)\n", i, vect[i]);
                                }
                                else{
                                    printf("Valor não encontrado.\n");
                                }
                            }
                        }
                    }
    return 0;
}