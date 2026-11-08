#include <stdio.h>
int main(){
    int idade = 30;
    float altura = 1.80;
    char letra = 'M';
    printf("endereço na memoria:\n%p\n%p\n%p\n",(void *)&idade, (void *)&altura, (void *)&letra);
    return 0;
}