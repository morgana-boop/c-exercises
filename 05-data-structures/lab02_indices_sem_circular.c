#include <stdio.h>

/*
 * LABORATORIO 2 - INDICES 'INICIO' E 'FIM' (AINDA SEM CIRCULARIDADE)
 * ====================================================================
 *
 * No Laboratorio 1, o problema era que remover custava caro (tinhamos
 * que mover tudo). A ideia deste laboratorio e: em vez de sempre
 * trabalhar com a posicao 0 como "o proximo a sair", vamos guardar
 * DOIS indices:
 *
 *   - inicio: aponta para o elemento mais antigo (o proximo a sair)
 *   - fim:    aponta para o elemento mais novo (o ultimo que entrou)
 *
 * Inserir passa a ser "andar o fim para frente e escrever ali".
 * Remover passa a ser "andar o inicio para frente" -- SEM MOVER
 * NADA no vetor. Isso ja resolve o problema do Laboratorio 1!
 *
 * Mas, como voce vai ver no final deste laboratorio, essa versao
 * ainda tem uma limitacao importante.
 */

#define CAPACIDADE_MAXIMA 5

int fila[CAPACIDADE_MAXIMA];
int inicio = 0;
int fim = -1;              // -1 = "ainda nao inserimos nada"
int quantidadeElementos = 0;

void inserir(int valor) {
    // Aqui 'fim' so sabe andar para frente. Se ele ja chegou no
    // ultimo indice do vetor, nao ha para onde ele avancar.
    if (fim == CAPACIDADE_MAXIMA - 1) {
        printf("ERRO: 'fim' esta no indice %d, o ULTIMO do vetor.\n", fim);
        printf("      Nao ha como avancar mais uma casa, entao nao da\n");
        printf("      para inserir o valor %d -- mesmo que 'inicio' ja\n", valor);
        printf("      tenha avancado e sobrado espaco lá atras!\n");
        return;
    }

    fim = fim + 1;
    fila[fim] = valor;
    quantidadeElementos++;

    printf("Inseri o valor %d na posicao %d do vetor. (fim agora = %d)\n", valor, fim, fim);
}

void remover() {
    if (quantidadeElementos == 0) {
        printf("ERRO: a fila esta vazia, nao ha nada para remover.\n");
        return;
    }

    int valorRemovido = fila[inicio];

    printf("Removi o valor %d, que estava guardado na posicao %d.\n", valorRemovido, inicio);
    printf("   -> Repare bem: NAO precisamos mover nenhum outro elemento!\n");
    printf("      Bastou avancar o indice 'inicio' uma casa para frente.\n");

    inicio = inicio + 1;
    quantidadeElementos--;
}

void mostrarEstado() {
    printf("   [estado] inicio=%d  fim=%d  quantidadeElementos=%d\n", inicio, fim, quantidadeElementos);
}

int main() {
    printf("Passo 1: encher completamente o vetor (capacidade %d):\n\n", CAPACIDADE_MAXIMA);
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(40);
    inserir(50);

    mostrarEstado();

    printf("\nPasso 2: remover 2 valores (os mais antigos, pelo 'inicio'):\n\n");
    remover();
    remover();
    printf("\n");
    mostrarEstado();

    printf("\nRepare no estado acima: quantidadeElementos = %d, ou seja,\n", quantidadeElementos);
    printf("SOBROU espaco no vetor (as posicoes 0 e 1 ficaram livres\n");
    printf("depois que 'inicio' avancou). Mesmo assim, vamos tentar\n");
    printf("inserir mais um valor e ver o que acontece:\n\n");

    inserir(60);

    printf("\nCONCLUSAO DO LABORATORIO 2:\n");
    printf("Usar 'inicio' e 'fim' resolveu o problema de TER que mover\n");
    printf("elementos ao remover -- otimo, esse ganho e definitivo!\n");
    printf("Mas essa versao criou um problema novo: o indice 'fim' so\n");
    printf("sabe andar para frente, e nunca 'aproveita' o espaco livre\n");
    printf("que ficou para tras, no comeco do vetor. A fila fica presa\n");
    printf("mesmo tendo espaco de sobra. No proximo laboratorio vamos\n");
    printf("conhecer a ferramenta matematica que resolve exatamente\n");
    printf("isso: o operador '%%' (modulo, resto da divisao).\n");

    return 0;
}
