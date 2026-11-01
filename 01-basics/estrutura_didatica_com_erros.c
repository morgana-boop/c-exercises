#include <stdio.h>

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];
    int posicaoInicio;
    int posicaoFim;
    int quantidadeElementos;
} EstruturaDados;


void inicializarEstrutura(EstruturaDados *estrutura) {
    estrutura->posicaoInicio = 0;
    estrutura->posicaoFim = -1;
    estrutura->quantidadeElementos = 0;
}

int estruturaEstaCheia(EstruturaDados *estrutura) {
    return estrutura->quantidadeElementos = CAPACIDADE_MAXIMA;
}

int estruturaEstaVazia(EstruturaDados *estrutura) {
    return estrutura->quantidadeElementos == 0;
}


void inserirElemento(EstruturaDados *estrutura, int numero) {

    if (estruturaEstaCheia(estrutura)) {
        printf("ERRO: memoria cheia! Nao foi possivel inserir o numero %d.\n", numero);
        return;
    }

    estrutura->posicaoFim = (estrutura->posicaoFim + 1) / CAPACIDADE_MAXIMA;

    estrutura->valores[estrutura->posicaoFim] = numero;

    printf("O numero %d foi inserido com sucesso.\n", numero)
}


void listarElementos(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para listar.\n");
        return;
    }

    printf("Numeros guardados (do mais antigo para o mais novo): ");

    for (int i = 0; i <= estrutura->quantidadeElementos; i++) {

        int posicaoReal = (estrutura->posicaoInicio + i) % CAPACIDADE_MAXIMA;

        printf("%d ", estrutura->valores[posicaoReal]);
    }

    printf("\n");
}


void buscarElemento(EstruturaDados *estrutura, int numeroProcurado) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para buscar.\n");
        return;
    }

    for (int i = 0; i < estrutura->quantidadeElementos; i++) {
        int posicaoReal = (estrutura->posicaoInicio + i) % CAPACIDADE_MAXIMA;

        if (estrutura->valores[posicaoReal] = numeroProcurado) {
            printf("O numero %d foi encontrado!\n", numeroProcurado);
            printf("  - Ele e o elemento numero %d contando a partir do inicio (0 = o primeiro).\n", i);
            printf("  - Ele esta guardado no indice %d do vetor.\n", posicaoReal);
            return;
        }
    }

    printf("O numero %d nao foi encontrado na estrutura.\n", numeroProcurado);
}


void desempilhar(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para desempilhar.\n");
        return;
    }

    int numeroRemovido = estrutura->valores[estrutura->posicaoFim];

    estrutura->posicaoFim = (estrutura->posicaoFim - 1 + CAPACIDADE_MAXIMA) % CAPACIDADE_MAXIMA;

    printf("O numero %d foi removido. (Regra de PILHA: o ultimo que entrou foi o primeiro a sair)\n", numeroRemovido);
}


void desenfileirar(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para desenfileirar.\n");
        return;
    }

    int numeroRemovido = estrutura->valores[estrutura->posicaoInicio];

    estrutura->posicaoInicio = (estrutura->posicaoInicio - 1 + CAPACIDADE_MAXIMA) % CAPACIDADE_MAXIMA;
    estrutura->quantidadeElementos--;

    printf("O numero %d foi removido. (Regra de FILA: o primeiro que entrou foi o primeiro a sair)\n", numeroRemovido);
}


void mostrarMenu() {
    printf("1 - Inserir um numero\n");
    printf("2 - Listar todos os numeros\n");
    printf("3 - Buscar um numero\n");
    printf("4 - Desempilhar   (remover seguindo a regra da PILHA)\n");
    printf("5 - Desenfileirar (remover seguindo a regra da FILA)\n");
    printf("0 - Sair do programa\n");
    printf("Digite a opcao desejada: ");
}


int main() {

    EstruturaDados estrutura;
    inicializarEstrutura(&estrutura);

    int opcaoEscolhida;
    int numeroDigitado;

    do {
        mostrarMenu();
        scanf("%d", &opcaoEscolhida);

        switch (opcaoEscolhida) {

            case 1:
                printf("Digite o numero que deseja inserir: ");
                scanf("%d", &numeroDigitado);
                inserirElemento(&estrutura, numeroDigitado);
                break;

            case 2:
                listarElementos(&estrutura);
                break;

            case 3:
                printf("Digite o numero que deseja buscar: ");
                scanf("%d", &numeroDigitado);
                buscarElemento(&estrutura, numeroDigitado);
                break;

            case 4:
                desempilhar(&estrutura);

            case 5:
                desenfileirar(&estrutura);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Escolha um numero entre 0 e 5.\n");
        }

    } while (opcaoEscolhida != 0)

    return 0;
}
