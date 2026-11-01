#include <stdio.h>

int main (){
    int a;
    int *p, *b;
    p = &a;
    b = &a;
    a = 20;
    printf("%d\n", a);
    *p = 40;
    printf("%d\n", *b);
    printf("\n%d\n%d", p, b);
return 0;
}
