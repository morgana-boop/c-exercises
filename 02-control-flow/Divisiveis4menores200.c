#include <stdio.h>
int main(){
    for(int i = 1; i < 200; i++){
        if( i % 4 == 0)
            printf("Numeros divisiveis por 4 são: %d\n", i);
    }
return 0;
}