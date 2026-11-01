#include <stdio.h>
int main(){
    int a = 0;
        for (int i = 1; i <= 500; i++){
            if (i % 2 == 0)
            {
                a = a + i;
                printf("Soma é: %d\n", a);
            }
            
        }
return 0;
}