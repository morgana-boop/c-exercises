#include <stdio.h>

/*
 * LABORATORIO 9 - A FILA CIRCULAR COMPLETA (OBJETIVO FINAL)
 * ==============================================================
 *
 * Este e o programa que junta tudo o que construimos nos 8
 * laboratorios anteriores. Recapitulando cada peca e de onde ela
 * veio, antes de olhar o codigo:
 *
 *   Lab 1 -> nos mostrou o problema: reajustar (mover) o vetor
 *            inteiro toda vez que removemos o primeiro elemento
 *            e caro demais.
 *
 *   Lab 2 -> introduziu os indices 'posicaoInicio' e 'posicaoFim',
 *            eliminando a necessidade de mover elementos ao
 *            remover. Mas o 'posicaoFim' so andava para frente e
 *            nao aproveitava espaco liberado no comeco do vetor.
 *
 *   Lab 3 -> nos ensinou a ferramenta que resolve isso: o operador
 *            '%' (modulo), que faz um indice "dar a volta" e
 *            reaproveitar posicoes livres no inicio do vetor.
 *
 *   Lab 4 e 5 -> aplicaram o modulo na insercao e na remocao,
 *            criando de fato o comportamento CIRCULAR.
 *
 *   Lab 6 -> mostrou que so os indices nao bastam: 'posicaoInicio'
 *            igual a 'posicaoFim' pode significar tanto "vazia"
 *            quanto "cheia", e nao da para diferenciar so com eles.
 *
 *   Lab 7 -> resolveu essa ambiguidade com 'quantidadeElementos',
 *            um contador independente dos indices.
 *
 *   Lab 8 -> ensinou como listar os elementos na ordem certa,
 *            traduzindo posicao logica (0=mais antigo) para
 *            posicao real dentro do vetor.
 *
 * O resultado e a estrutura abaixo: uma FILA CIRCULAR ESTATICA
 * (baseada em vetor de tamanho fixo), que usa 'posicaoInicio' e
 * 'posicaoFim' para que REMOVER um elemento NUNCA exija reajustar
 * (mover) o restante da fila -- exatamente o objetivo proposto.
 */

#define CAPACIDADE_MAXIMA 5

typedef struct {
    int valores[CAPACIDADE_MAXIMA];   // onde os dados ficam guardados de fato
    int posicaoInicio;                // indice do elemento mais ANTIGO (proximo a sair)
    int posicaoFim;                   // indice do elemento mais NOVO (ultimo que entrou)
    int quantidadeElementos;          // contador independente, resolve a ambiguidade do Lab 6
} FilaCircular;


// ---------------------------------------------------------------
// INICIALIZACAO
// ---------------------------------------------------------------
void inicializarFila(FilaCircular *fila) {
    fila->posicaoInicio = 0;
    fila->posicaoFim = -1;         // -1 = "ainda nao inserimos nada" (ver Lab 4)
    fila->quantidadeElementos = 0;
}


// ---------------------------------------------------------------
// CONSULTAS DE ESTADO (Lab 7: usam o contador, nunca os indices)
// ---------------------------------------------------------------
int filaEstaCheia(FilaCircular *fila) {
    return fila->quantidadeElementos == CAPACIDADE_MAXIMA;
}

int filaEstaVazia(FilaCircular *fila) {
    return fila->quantidadeElementos == 0;
}


// ---------------------------------------------------------------
// ENFILEIRAR (inserir) - Lab 4 + Lab 7
// ---------------------------------------------------------------
// O novo elemento sempre entra em 'posicaoFim'. Usamos o modulo
// para que, ao chegar no final do vetor, o indice volte para 0 e
// reaproveite espaco liberado por remocoes anteriores.
void enfileirar(FilaCircular *fila, int valor) {

    if (filaEstaCheia(fila)) {
        printf("ERRO: fila cheia! Nao foi possivel inserir o numero %d.\n", valor);
        return;
    }

    fila->posicaoFim = (fila->posicaoFim + 1) % CAPACIDADE_MAXIMA;
    fila->valores[fila->posicaoFim] = valor;
    fila->quantidadeElementos++;

    printf("O numero %d entrou na fila (posicao real %d no vetor).\n", valor, fila->posicaoFim);
}


// ---------------------------------------------------------------
// DESENFILEIRAR (remover) - Lab 5 + Lab 7
// ---------------------------------------------------------------
// O elemento removido e sempre o de 'posicaoInicio' (o mais
// antigo, regra FIFO: First In, First Out). So avancamos o
// indice -- NENHUM outro elemento do vetor precisa se mexer.
// Isso e o objetivo central do exercicio: remover sem reajustar.
void desenfileirar(FilaCircular *fila) {

    if (filaEstaVazia(fila)) {
        printf("ERRO: fila vazia! Nao ha nada para remover.\n");
        return;
    }

    int valorRemovido = fila->valores[fila->posicaoInicio];

    fila->posicaoInicio = (fila->posicaoInicio + 1) % CAPACIDADE_MAXIMA;
    fila->quantidadeElementos--;

    printf("O numero %d saiu da fila. Nenhum outro elemento precisou se mover.\n", valorRemovido);
}


// ---------------------------------------------------------------
// LISTAR - Lab 8
// ---------------------------------------------------------------
// Percorremos exatamente 'quantidadeElementos' posicoes LOGICAS,
// comecando em 'posicaoInicio', e traduzimos cada uma para a
// posicao REAL dentro do vetor usando o modulo.
void listarFila(FilaCircular *fila) {

    if (filaEstaVazia(fila)) {
        printf("A fila esta vazia. Nao ha nada para listar.\n");
        return;
    }

    printf("Fila atual (do mais antigo para o mais novo): ");

    for (int posicaoLogica = 0; posicaoLogica < fila->quantidadeElementos; posicaoLogica++) {
        int posicaoReal = (fila->posicaoInicio + posicaoLogica) % CAPACIDADE_MAXIMA;
        printf("%d ", fila->valores[posicaoReal]);
    }

    printf("\n");
}


// ---------------------------------------------------------------
// BUSCAR (bonus: reaproveita a mesma traducao logica -> real)
// ---------------------------------------------------------------
void buscarNaFila(FilaCircular *fila, int numeroProcurado) {

    if (filaEstaVazia(fila)) {
        printf("A fila esta vazia. Nao ha nada para buscar.\n");
        return;
    }

    for (int posicaoLogica = 0; posicaoLogica < fila->quantidadeElementos; posicaoLogica++) {
        int posicaoReal = (fila->posicaoInicio + posicaoLogica) % CAPACIDADE_MAXIMA;

        if (fila->valores[posicaoReal] == numeroProcurado) {
            printf("O numero %d foi encontrado!\n", numeroProcurado);
            printf("   - E o elemento numero %d contando a partir do inicio (0 = o primeiro).\n", posicaoLogica);
            printf("   - Esta guardado no indice real %d do vetor.\n", posicaoReal);
            return;
        }
    }

    printf("O numero %d nao foi encontrado na fila.\n", numeroProcurado);
}


// ---------------------------------------------------------------
// MENU E PROGRAMA PRINCIPAL
// ---------------------------------------------------------------
void mostrarMenu() {
    printf("\n----------------------------------------\n");
    printf("1 - Enfileirar (inserir um numero)\n");
    printf("2 - Desenfileirar (remover o mais antigo)\n");
    printf("3 - Listar a fila\n");
    printf("4 - Buscar um numero\n");
    printf("5 - Mostrar estado interno (inicio/fim/quantidade)\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

void mostrarEstadoInterno(FilaCircular *fila) {
    printf("posicaoInicio=%d  posicaoFim=%d  quantidadeElementos=%d  (capacidade=%d)\n",
           fila->posicaoInicio, fila->posicaoFim, fila->quantidadeElementos, CAPACIDADE_MAXIMA);
}

int main() {

    printf("========================================\n");
    printf(" LABORATORIO 9 - FILA CIRCULAR COMPLETA\n");
    printf("========================================\n");
    printf("Capacidade maxima do vetor: %d posicoes.\n", CAPACIDADE_MAXIMA);

    FilaCircular fila;
    inicializarFila(&fila);

    int opcaoEscolhida;
    int numeroDigitado;

    do {
        mostrarMenu();
        scanf("%d", &opcaoEscolhida);

        switch (opcaoEscolhida) {

            case 1:
                printf("Digite o numero que deseja inserir: ");
                scanf("%d", &numeroDigitado);
                enfileirar(&fila, numeroDigitado);
                break;

            case 2:
                desenfileirar(&fila);
                break;

            case 3:
                listarFila(&fila);
                break;

            case 4:
                printf("Digite o numero que deseja buscar: ");
                scanf("%d", &numeroDigitado);
                buscarNaFila(&fila, numeroDigitado);
                break;

            case 5:
                mostrarEstadoInterno(&fila);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Escolha um numero entre 0 e 5.\n");
        }

    } while (opcaoEscolhida != 0);

    return 0;
}
