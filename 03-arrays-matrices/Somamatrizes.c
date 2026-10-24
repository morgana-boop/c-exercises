#include <stdio.h>

// ==========================================
// CASO 1: PASSAGEM POR VALOR (O Anexo de E-mail)
// ==========================================
// A função recebe um 'int' normal. Isso cria um CLONE na memória.
void testar_por_valor(int variavel_clone) {
    // Estamos alterando apenas o clone que nasceu dentro desta função.
    variavel_clone = 999;
    printf("[Dentro da Funcao 1] O clone virou: %d\n", variavel_clone);
} 
// Fim da função: O 'variavel_clone' é jogado no lixo pelo sistema.


// ==========================================
// CASO 2: PASSAGEM POR REFERÊNCIA (O Google Docs)
// ==========================================
// A função exige um PONTEIRO (*). Ela não quer o dado, quer o ENDEREÇO.
void testar_por_referencia(int *endereco_da_original) {
    // Usamos o asterisco (*) para VIAJAR até o endereço e alterar o dado original.
    *endereco_da_original = 999;
    printf("[Dentro da Funcao 2] Fui no endereco e alterei para: %d\n", *endereco_da_original);
}


int main() {
    // Nossas variáveis originais, seguras (por enquanto) na main.
    int valor_teste_1 = 10;
    int valor_teste_2 = 10;

    printf("--- TESTE 1: POR VALOR ---\n");
    printf("Antes: %d\n", valor_teste_1);
    
    // Enviamos apenas o número '10'. A variável 'valor_teste_1' fica em casa.
    testar_por_valor(valor_teste_1); 
    
    // Como a função só mexeu no clone, a original está intacta.
    printf("Depois: %d (A original SOBREVIVEU!)\n\n", valor_teste_1);


    printf("--- TESTE 2: POR REFERENCIA ---\n");
    printf("Antes: %d\n", valor_teste_2);
    
    // Enviamos o ENDEREÇO (&). Estamos dando as chaves de casa para a função.
    testar_por_referencia(&valor_teste_2); 
    
    // A função usou nosso endereço e alterou nossa variável original.
    printf("Depois: %d (A original FOI ALTERADA!)\n", valor_teste_2);

    return 0;
}