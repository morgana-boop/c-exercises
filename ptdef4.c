#include <stdio.h>
#include <stdlib.h>

int main (){
    int a;
    int *p;
    a = 400;

    printf("\n%d", a);
    p = &a;
    p = malloc(sizeof(int));

    *p = 900;
    printf("\n%d", a);

    if(p != NULL){
    printf("Memoria liberada\n");
    free(p);
    }




return 0;
}
