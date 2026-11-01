#include <stdio.h>   // Biblioteca para entrada/saída (printf e scanf)
#include <string.h>  // Biblioteca para manipulação de strings (strlen, strcmp etc.)
#include <ctype.h>   // Biblioteca para funções como isdigit (checar se é dígito)

// Função principal do programa
int main() {
    // Declaração de variáveis:
    // - cpf_str: string para armazenar o CPF como texto (tamanho 12 para incluir '\0')
    // - cpf_digits: array de inteiros para armazenar cada dígito individualmente (11 posições)
    // - i, soma, resto: auxiliares para loops e cálculos
    // - valido: flag para indicar se CPF é válido (1 = sim, 0 = não)
    char cpf_str[12];  
    int cpf_digits[11];  
    int i, soma, resto;
    int valido = 1;  // Assume válido até prova em contrário

    // Passo 1: Ler o input do usuário
    // Por quê? Precisamos capturar o CPF como string para preservar zeros à esquerda e facilitar validações.
    // Usamos scanf com %11s para limitar a 11 caracteres (evita overflow), mas na prática, adicione espaços para máscaras se quiser expandir.
    printf("Digite o CPF (somente 11 dígitos): ");
    scanf("%11s", cpf_str);  // Lê exatamente 11 caracteres como string

    // Passo 1.1: Verificar se o input tem exatamente 11 caracteres
    // Por quê? CPF deve ter exatamente 11 dígitos; menos ou mais é inválido imediatamente.
    if (strlen(cpf_str) != 11) {
        valido = 0;  // Marca como inválido
        printf("CPF inválido: deve ter exatamente 11 dígitos.\n");
        return 0;  // Sai do programa cedo (boa prática para evitar processar lixo)
    }

    // Passo 1.2: Converter string para array de dígitos inteiros e validar se são números
    // Por quê? Armazenar individualmente permite acessar cada dígito facilmente para cálculos.
    // Também checamos se cada char é dígito (0-9) para evitar inputs como letras.
    for (i = 0; i < 11; i++) {
        if (!isdigit(cpf_str[i])) {  // isdigit verifica se é '0' a '9'
            valido = 0;
            printf("CPF inválido: contém caracteres não-numéricos.\n");
            return 0;
        }
        cpf_digits[i] = cpf_str[i] - '0';  // Converte char '0'-'9' para int 0-9 (truque ASCII: '5' - '0' = 5)
    }

    // Passo 2: Verificar se todos os dígitos são iguais
    // Por quê? Sequências como 00000000000 ou 11111111111 passam no checksum matemático, mas não são CPFs reais emitidos pela Receita Federal.
    // Isso é uma regra de negócio para filtrar CPFs "óbvios" falsos.
    int todos_iguais = 1;  // Assume todos iguais até prova em contrário
    for (i = 1; i < 11; i++) {
        if (cpf_digits[i] != cpf_digits[0]) {
            todos_iguais = 0;  // Encontrou diferença, não são todos iguais
            break;  // Sai do loop cedo para eficiência
        }
    }
    if (todos_iguais) {
        valido = 0;
        printf("CPF inválido: todos os dígitos são iguais.\n");
        return 0;
    }

    // Passo 3: Calcular o primeiro dígito verificador (posição 9, J)
    // Por quê? O algoritmo oficial usa soma ponderada dos primeiros 9 dígitos com pesos 10 a 2, depois módulo 11 para gerar/verificar J.
    // Isso detecta erros de digitação ou alterações.
    soma = 0;  // Inicializa soma em 0
    for (i = 0; i < 9; i++) {
        soma += cpf_digits[i] * (10 - i);  // Multiplica dígito por peso decrescente: pos0*10, pos1*9, ..., pos8*2
    }
    resto = soma % 11;  // Resto da divisão por 11
    int verificador1_calculado;
    if (resto < 2) {
        verificador1_calculado = 0;  // Regra oficial: se resto < 2, verificador = 0
    } else {
        verificador1_calculado = 11 - resto;  // Senão, 11 - resto (garante valor 1-9)
    }
    // Compara com o dígito fornecido
    if (verificador1_calculado != cpf_digits[9]) {
        valido = 0;
        printf("CPF inválido: primeiro dígito verificador não confere.\n");
        return 0;
    }

    // Passo 4: Calcular o segundo dígito verificador (posição 10, K)
    // Por quê? Similar ao anterior, mas inclui o J (posição 9) na soma, com pesos 11 a 2.
    // Isso adiciona uma camada extra de verificação, confirmando inclusive o primeiro verificador.
    soma = 0;  // Reinicializa soma
    for (i = 0; i < 10; i++) {
        soma += cpf_digits[i] * (11 - i);  // Pesos: pos0*11, pos1*10, ..., pos9*2
    }
    resto = soma % 11;
    int verificador2_calculado;
    if (resto < 2) {
        verificador2_calculado = 0;
    } else {
        verificador2_calculado = 11 - resto;
    }
    // Compara com o dígito fornecido
    if (verificador2_calculado != cpf_digits[10]) {
        valido = 0;
        printf("CPF inválido: segundo dígito verificador não confere.\n");
        return 0;
    }

    // Passo 5: Se chegou aqui, passou em todas as checagens
    // Por quê? Todas as validações foram feitas sequencialmente; se não falhou em nenhuma, é válido.
    if (valido) {
        printf("CPF válido!\n");
    }

    return 0;  // Fim do programa com sucesso
}