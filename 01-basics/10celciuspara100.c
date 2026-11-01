#include <stdio.h>
int main(){
    float celcius = 0;
    float fahe = 0;
        for(int i = 0; i <= 9; i++){
            celcius = celcius + 10;
            fahe = 1.8 * celcius + 32;
            printf("%2.f C e %.2f F\n", celcius, fahe);
        }
return 0;
}