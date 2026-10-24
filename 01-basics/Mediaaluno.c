#include <stdio.h>
    int main(){
        int n1, n2, n3, n4, md;
            printf("Digite o valor da 1º, 2º, 3º e 4º nota: ");
                scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
                md = 4 / (n1 + n2 + n3 + n4);
                if (md >= 5)
                {   
                    printf("Aluno aprovado");
                }
                else
                    printf("Aluno reprovado, media foi: %d", md);
    return 0;
    }