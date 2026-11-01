#include <stdio.h>
    int main(){
        int prest, valor, taxa, temp;
        printf("digite o valor atrasado: ");
            scanf("%d", &valor);
        printf("Digite o valor da taxa: ");
            scanf("%d", &taxa);
        printf("Digite o tempo atrasado: ");
            scanf("%d", &temp);
        prest = valor + (valor * (taxa/100)*temp);
        printf("O valor da prestação total é de: %d\n", prest);

return 0;
}