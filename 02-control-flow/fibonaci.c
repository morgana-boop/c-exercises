#include <stdio.h>

// Função que reduz um número até ficar com 1 dígito (soma persistente dos dígitos)
int raizDigital(long long n) {
    // Enquanto o número tiver 2 ou mais dígitos
    while (n >= 10) {
        long long soma = 0;
        
        // Soma todos os dígitos
        while (n > 0) {
            soma += n % 10;     // pega o último dígito
            n = n / 10;         // remove o último dígito
        }
        
        n = soma;  // agora n vira a soma dos dígitos
    }
    
    return (int)n;  // quando sair do while, n tem 1 dígito
}

int main() {
    long long a = 1;       // primeiro termo
    long long b = 1;       // segundo termo
    int termo = 1;         // contador de qual termo estamos
    
    printf("Termo | Fibonacci | Raiz digital (soma até 1 dígito)\n");
    printf("----------------------------------------------------\n");
    
    // Mostra os dois primeiros termos manualmente (1 e 1)
    printf("%4d  | %9lld   | %d\n", termo++, a, raizDigital(a));
    printf("%4d  | %9lld   | %d\n", termo++, b, raizDigital(b));
    
    // Gera os próximos termos
    for (int i = 3; i <= 100; i++) {   // vamos até o 30º termo (ajuste se quiser mais)
        long long proximo = a + b;
        
        // Mostra o termo, o valor Fibonacci e a raiz digital
        printf("%4d  | %9lld   | %d\n", termo++, proximo, raizDigital(proximo));
        
        // Avança na sequência
        a = b;
        b = proximo;
    }
    
    return 0;
}