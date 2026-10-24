#include <stdio.h>

int main() {
    // 1. Alocação de memória
    int a, b, c, d, e;
    int maior, menor;

    // 2. Captura dos dados
    printf("Informe 5 valores inteiros (separados por espaco):\n");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // 3. Estabelecimento do Ponto de Ancoragem
    // Inicialmente, 'a' reina absoluto como o maior e o menor valor
    maior = a;
    menor = a;

    // 4. Tomada de Decisão Sequencial (A Batalha)
    // Desafiante B
    if (b > maior) { maior = b; }
    if (b < menor) { menor = b; }

    // Desafiante C
    if (c > maior) { maior = c; }
    if (c < menor) { menor = c; }

    // Desafiante D
    if (d > maior) { maior = d; }
    if (d < menor) { menor = d; }

    // Desafiante E
    if (e > maior) { maior = e; }
    if (e < menor) { menor = e; }

    // 5. Apresentacao do Resultado
    printf("O maior valor informado foi: %d\n", maior);
    printf("O menor valor informado foi: %d\n", menor);

    return 0;
}