#include <stdio.h>
    int main(){
    int a, b, c, d;
    int abs, acs, ads, bcs, bds, cds;
    int abm, acm, adm, bcm, bdm, cdm;
        printf("Digite o valor das 4 variaveis: \n");
            scanf("%d%d%d%d", &a, &b, &c, &d);
        abs = a + b;
        acs = a + c;
        ads = a + d;
        bcs = b + c;
        bds = b + d;
        cds = c + d;

        abm = a * b;
        acm = a * c;
        adm = a * d;
        bcm = b * c;
        bdm = b * d;
        cdm = c * d;

        printf("O valor das 6 possiveis somas das 4 variaveis são: %d, %d, %d, %d, %d, %d\n", abs, acs, ads, bcs, bds, cds);
        printf("O valor das 6 possiveis multiplicações das 4 variaveis são: %d, %d, %d, %d, %d, %d\n", abm, acm, adm, bcm, bdm, cdm);
        
return 0;
}