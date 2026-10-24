#include <stdio.h>

int main() {
    int v1, v2, v3;

    printf("Digite 3 valores: ");
    scanf("%d%d%d", &v1, &v2, &v3);

    unsigned long long int fat1 = 1;
    unsigned long long int fat2 = 1;
    unsigned long long int fat3 = 1;

    for (int i = 1; i <= v1; i++) {
        fat1 = fat1 * i;
    }

    for (int i = 1; i <= v2; i++) {
        fat2 = fat2 * i;
    }

    for (int i = 1; i <= v3; i++) {
        fat3 = fat3 * i;
    }

    printf("%d! = %llu\n", v1, fat1);
    printf("%d! = %llu\n", v2, fat2);
    printf("%d! = %llu\n", v3, fat3);

    return 0;
}