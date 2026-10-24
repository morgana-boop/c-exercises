#include <stdio.h>

/*
 * ============================================================
 *  ESTRUTURA DE DADOS BASEADA EM VETOR (COM COMPORTAMENTO
 *  CIRCULAR), QUE FUNCIONA TANTO COMO PILHA QUANTO COMO FILA
 * ============================================================
 *
 * A ideia geral e simples: temos um vetor de tamanho fixo (5
 * posicoes) e tres "informacoes de controle" que dizem:
 *
 *   - onde comeca o que tem dado valido      (posicaoInicio)
 *   - onde termina o que tem dado valido     (posicaoFim)
 *   - quantos elementos existem agora        (quantidadeElementos)
 *
 * Com essas tres informacoes, nunca precisamos "varrer" o vetor
 * inteiro para saber o que e dado real e o que e espaco vazio.
 *
 * O vetor e "circular" porque, quando um indice chega no final
 * (posicao 4, já que o vetor tem 5 posicoes: 0,1,2,3,4), ele
 * "da a volta" e recomeca em 0. Isso e feito com o operador de
 * resto da divisao, o "%". Vamos ver isso com calma nos
 * comentarios de cada funcao.
 */

#define CAPACIDADE_MAXIMA 5  // quantos numeros cabem no vetor ao mesmo tempo


// A struct funciona como uma "ficha" que guarda tudo o que
// precisamos saber sobre o estado atual da nossa estrutura.
typedef struct {
    int valores[CAPACIDADE_MAXIMA];   // o vetor onde os numeros ficam guardados de fato

    int posicaoInicio;       // indice do elemento MAIS ANTIGO
                              // (o primeiro que foi inserido e que ainda nao saiu)

    int posicaoFim;          // indice do elemento MAIS NOVO
                              // (o ultimo numero que foi inserido)

    int quantidadeElementos; // quantos numeros estao guardados AGORA
} EstruturaDados;


// Deixa a estrutura pronta para uso, comecando vazia.
void inicializarEstrutura(EstruturaDados *estrutura) {
    estrutura->posicaoInicio = 0;
    estrutura->posicaoFim = -1;          // -1 = "ainda nao inserimos nada"
    estrutura->quantidadeElementos = 0;
}

// Devolve 1 (verdadeiro) se todas as 5 posicoes ja estao ocupadas.
int estruturaEstaCheia(EstruturaDados *estrutura) {
    return estrutura->quantidadeElementos == CAPACIDADE_MAXIMA;
}

// Devolve 1 (verdadeiro) se nao ha nenhum numero guardado.
int estruturaEstaVazia(EstruturaDados *estrutura) {
    return estrutura->quantidadeElementos == 0;
}


/*
 * INSERIR UM NOVO NUMERO
 * ------------------------
 * Existe SOMENTE UMA funcao de insercao no programa. Ela serve
 * tanto para "empilhar" quanto para "enfileirar", porque nos dois
 * casos o numero novo entra sempre no FIM do vetor. A diferenca
 * entre pilha e fila nao esta em como voce insere, e sim em como
 * voce remove (isso fica bem claro nas duas funcoes de remocao,
 * mais abaixo).
 */
void inserirElemento(EstruturaDados *estrutura, int numero) {

    if (estruturaEstaCheia(estrutura)) {
        printf("ERRO: memoria cheia! Nao foi possivel inserir o numero %d.\n", numero);
        return;
    }

    // Passo 1: avancar o indice do fim em uma posicao.
    //
    // O truque esta no "% CAPACIDADE_MAXIMA" (resto da divisao por 5).
    // Ele faz o indice voltar para 0 assim que ultrapassa o limite do vetor.
    //
    // Exemplo pratico com CAPACIDADE_MAXIMA = 5:
    //   se posicaoFim = 4 (ultima posicao do vetor)
    //   entao (4 + 1) % 5 = 5 % 5 = 0   -> voltou para o comeco do vetor!
    //
    // Isso e o que torna o vetor "circular": ele reaproveita espacos
    // que foram liberados por uma remocao anterior, sem precisar
    // mover nenhum outro elemento de lugar.
    estrutura->posicaoFim = (estrutura->posicaoFim + 1) % CAPACIDADE_MAXIMA;

    // Passo 2: guardar o numero na nova posicaoFim.
    estrutura->valores[estrutura->posicaoFim] = numero;

    // Passo 3: contar mais um elemento guardado.
    estrutura->quantidadeElementos++;

    printf("O numero %d foi inserido com sucesso.\n", numero);
}


/*
 * LISTAR TODOS OS NUMEROS
 * --------------------------
 * Aqui esta o motivo de guardarmos "quantidadeElementos": o loop
 * roda exatamente essa quantidade de vezes, comecando em
 * posicaoInicio. Assim NUNCA lemos posicoes vazias, e NUNCA
 * paramos antes de mostrar tudo que existe.
 */
void listarElementos(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para listar.\n");
        return;
    }

    printf("Numeros guardados (do mais antigo para o mais novo): ");

    for (int i = 0; i < estrutura->quantidadeElementos; i++) {

        // "i" e a posicao LOGICA (0 = mais antigo, 1 = o proximo, etc).
        // Precisamos converter isso para a posicao REAL dentro do vetor,
        // porque o vetor pode ja ter "dado a volta".
        int posicaoReal = (estrutura->posicaoInicio + i) % CAPACIDADE_MAXIMA;

        printf("%d ", estrutura->valores[posicaoReal]);
    }

    printf("\n");
}

/*
 * BUSCAR UM NUMERO
 * -------------------
 * Percorre os numeros validos, um por um, comparando com o valor
 * que o usuario digitou, ate encontrar (ou ate acabarem os elementos).
 */
void buscarElemento(EstruturaDados *estrutura, int numeroProcurado) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para buscar.\n");
        return;
    }

    for (int i = 0; i < estrutura->quantidadeElementos; i++) {
        int posicaoReal = (estrutura->posicaoInicio + i) % CAPACIDADE_MAXIMA;

        if (estrutura->valores[posicaoReal] == numeroProcurado) {
            printf("O numero %d foi encontrado!\n", numeroProcurado);
            printf("  - Ele e o elemento numero %d contando a partir do inicio (0 = o primeiro).\n", i);
            printf("  - Ele esta guardado no indice %d do vetor.\n", posicaoReal);
            return;
        }
    }

    printf("O numero %d nao foi encontrado na estrutura.\n", numeroProcurado);
}


/*
 * DESEMPILHAR  ->  comportamento de PILHA (regra LIFO)
 * --------------------------------------------------------
 * LIFO = "Last In, First Out" = o ULTIMO numero que entrou e o
 * PRIMEIRO a sair.
 *
 * Por isso removemos pegando o numero que esta guardado em
 * posicaoFim (o mais recente), e depois recuamos posicaoFim
 * uma casa para tras.
 */
void desempilhar(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para desempilhar.\n");
        return;
    }

    int numeroRemovido = estrutura->valores[estrutura->posicaoFim];

    // Aqui recuamos o indice em vez de avancar. Somamos
    // CAPACIDADE_MAXIMA antes do "%" so para garantir que o
    // resultado nunca fique negativo.
    //
    // Exemplo: se posicaoFim = 0 (primeira posicao do vetor)
    //   (0 - 1 + 5) % 5 = 4 % 5 = 4   -> foi parar na ultima posicao do vetor
    estrutura->posicaoFim = (estrutura->posicaoFim - 1 + CAPACIDADE_MAXIMA) % CAPACIDADE_MAXIMA;

    estrutura->quantidadeElementos--;

    printf("O numero %d foi removido. (Regra de PILHA: o ultimo que entrou foi o primeiro a sair)\n", numeroRemovido);
}


/*
 * DESENFILEIRAR  ->  comportamento de FILA (regra FIFO)
 * -----------------------------------------------------------
 * FIFO = "First In, First Out" = o PRIMEIRO numero que entrou e
 * o PRIMEIRO a sair.
 *
 * Por isso removemos pegando o numero que esta guardado em
 * posicaoInicio (o mais antigo), e depois avancamos
 * posicaoInicio uma casa para frente.
 */
void desenfileirar(EstruturaDados *estrutura) {

    if (estruturaEstaVazia(estrutura)) {
        printf("A estrutura esta vazia. Nao ha nada para desenfileirar.\n");
        return;
    }

    int numeroRemovido = estrutura->valores[estrutura->posicaoInicio];

    estrutura->posicaoInicio = (estrutura->posicaoInicio + 1) % CAPACIDADE_MAXIMA;
    estrutura->quantidadeElementos--;

    printf("O numero %d foi removido. (Regra de FILA: o primeiro que entrou foi o primeiro a sair)\n", numeroRemovido);
}


// Apenas imprime as opcoes disponiveis para o usuario.
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
                break;

            case 5:
                desenfileirar(&estrutura);
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
