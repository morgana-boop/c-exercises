#include <stdio.h>

int main() // função principal que retorna um código inteiro indicando 
{
    double c, l, a, volume; //defino minhas variaveis

    printf("Calcular o volume \n\n");

    do { //peço ao usuario os dados
        printf("Comprimento: ");
        scanf("%lf", &c); //armazeno o valor

        printf("Largura: ");
        scanf("%lf", &l); //armazeno o valor

        printf("Altura: ");
        scanf("%lf", &a); //armazeno o valor

        if (c <= 0 || l <= 0 || a <= 0) { // verifica se são positivos
            printf("Todas as medidas devem ser maiores que zero!\n");
            printf("Digite novamente...\n");
        }

    } while (c < 0 || l < 0 || a < 0);
    // só vai executar quando tivermos valores corretos

    volume = c * l * a;

    printf("Volume = %.2f m³ \n", volume);

    return 0;
}