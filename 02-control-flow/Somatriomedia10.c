#include <stdio.h>
int main(){
    int v1, v2, v3;
    float soma1 = 0;
    float soma2 = 0;
    float soma3 = 0;
    float div1, div2, div3;
        printf("Digite 3 valores: \n");
            scanf("%d%d%d", &v1, &v2, &v3);
                for(int i = 0; i <= v1; i++){
                    soma1 = soma1 + i;
                }
                    div1 = soma1 / v1;
                for(int i = 0; i <= v2; i++){
                    soma2 = soma2 + i;
                }
                    div2 = soma2 / v2;
                for(int i = 0; i <= v3; i++){
                    soma3 = soma3 + i;
                }
                    div3 = soma3 / v3;
                printf("O valor do somatorio de %d, %d e %d, é: %.2f, %.2f, %.2f \n", v1, v2, v3, soma1, soma2, soma3);
                printf("O valor da média do somatorio de %d, %d e %d, é: %.2f, %.2f, %.2f \n", v1, v2, v3, div1, div2, div3);
                
return 0;
}