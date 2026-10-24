#include <stdio.h>
void vetor(bol){
    int vect[bol];
    printf("Vetor ira possuir %d espaços.", bol);
    for(int i = 0; i < bol; i++){
            printf("Digite um valor: ");
            scanf("%d", &vect[i]);
            printf("Valor %d armazenado na posição %d.", vect[i], i);
    return 0;
    }
}


int main (){
int bol;

        printf("Digite Quantos vetores teremos: ");
        scanf("%d", &bol);
        vetor(bol);                

       
    return 0;
}