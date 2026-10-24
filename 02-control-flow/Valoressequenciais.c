#include <stdio.h>
    int main(){
        int a, b, c, seg;
            printf("Digite os valores de A, B e C: \n");
                scanf("%d%d%d", &a, &b, &c);
    if (a > b) {
        seg = a;
        a = b;
        b = seg;
    }
    
    // Teste 2: O (possivelmente novo) A tenta ser menor que C
    // Neste ponto, A se torna o menor absoluto de todos.
    if (a > c) {
        seg = a;
        a = c;
        c = seg;
    }
    
    // Teste 3: A disputa final pelo segundo e terceiro lugar
    // Como A já é o menor, sobrou apenas ordenar B e C.
    if (b > c) {
        seg = b;
        b = c;
        c = seg;
    }
    printf("Os valores em ordem crescente sao: %d, %d, %d\n", a, b, c);
                
    return 0;
    }