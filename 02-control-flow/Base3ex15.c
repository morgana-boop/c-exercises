#include <stdio.h>
int main(){
    unsigned long long int res = 1;
    for(int i = 0; i <= 15; i++){
        res = res * 3;
        printf("Resultados são: %llu\n", res);
    }
return 0;
}