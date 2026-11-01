#include <stdio.h>
#include <string.h>
int main(){
    char bd [10][50];
    char nome [50];
        for(int i = 1; i <= 10; i++){
            printf("Digite o %d nome (espaço com_): \n", i);
                scanf("%s", nome);
                    strcpy(bd[i], nome);
        }
        for(int i = 1; i <= 10; i++){
            printf("Respectivos da posição %d nomes são: %s\n", i, bd[i]);
        }
            
return 0;
}