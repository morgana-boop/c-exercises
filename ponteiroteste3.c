#include <stdio.h>

int main (){
    int a = 50;
    int *p;

    p = NULL;

    if(p == NULL){
    p = &a;
    *p = 60;
    }

    printf("\n%d\n%d\n", p, *p);


return 0;
}
