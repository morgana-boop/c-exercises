#include <stdio.h>

#define CAP 5

typedef struct {
    int dados[CAP];
    int inicio;
    int fim;
    int total;
} Fila;

void fila_init(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int fila_cheia(Fila *f) {
    return f->total == CAP;
}

int fila_vazia(Fila *f) {
    return f->total == 0;
}

int fila_push(Fila *f, int valor) {
    if (fila_cheia(f)) return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % CAP;
    f->total++;
    return 1;
}

int fila_pop(Fila *f, int *valor) {
    if (fila_vazia(f)) return 0;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->total--;
    return 1;
}

int main() {
    Fila f;
    fila_init(&f);

    for (int i = 1; i <= CAP; i++)
        fila_push(&f, i * 10);

    int v;
    while (fila_pop(&f, &v))
        printf("%d\n", v);

    return 0;
}