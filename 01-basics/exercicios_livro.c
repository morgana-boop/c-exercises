// ==========================================================================
// Discente: [Marcos Jose Chagas Carneiro]
// 
// Aqui neste arquivo sera exposto os exercicios do livro Algoritmos
// (JOSE AUGUSTO NAVARRO GARCIA MANZANO) 
// Nota para quem ler este codigo: :                                                                                
// Existe um easter egg, tente encontrar a resposta para a pergunta:             
// Qual é a resposta para a pergunta fundamental sobre a vida, o universo e tudo mais? 
// Dica: 42                                                                                                                   
// ==========================================================================

#include <stdio.h> 
#include <math.h> 
#include <unistd.h> 

void exercicio1(){  
        int a, b;

            printf("digite o valor numérico de A:\n");
                scanf("%d", &a);
            printf("digite o valor numérico de B:\n");
                scanf("%d", &b);

            printf("\nValor de A e B é :\nA:%d\nB:%d\n\n", a, b);
            printf("\nPressione ENTER para voltar pro inicio...");
            getchar();
            getchar();


    }

void exercicio2(){
        int a, b, x;

            printf("Digite o valor de A:\n");
                scanf("%d",&a);
            printf("Digite o valor de B:\n");
                scanf("%d",&b);
                    x = a + b;
            printf("O valor da soma de A(%d) e B (%d) é igual: %d\n\n", a, b, x);
        printf("\nPressione ENTER para voltar pro inicio...");
        getchar();
        getchar();
    }

void exercicio3 (){

        int a, b, x;

            printf("Digite o valor de A:\n");
                scanf("%d",&a);
            printf("Digite o valor de B:\n");
                scanf("%d",&b);
                x = a + b;
                    if (x > 10){
                        printf("Valor da soma realizada é maior que 10\n\n");
                    }
                    else if (x < 10){
                        printf("Valor da soma realizado é menor que 10\n\n");
                    }
                    else {
                        printf("Valor da soma é igual a 10\n\n");
                    }
            printf("\nPressione ENTER para voltar pro inicio...");  
            getchar();
            getchar();               
    }

void exercicio4(){

        int a, b, x, r;

            printf("Digite o valor de A:\n");
                scanf("%d",&a);
            printf("Digite o valor de B:\n");
                scanf("%d",&b);
                x = a + b;
                    if (x > 10){
                        r = x + 5;
                        printf("Valor inserido é maior que 10, então + 5: %d\n\n", r);
                    }
                    else if (x < 10){
                        r = x + 7;
                        printf("Valor inserido é menor que 10, então + 7: %d\n\n", r);
                    }
                    else {
                        printf("Valor da soma é igual a 10 não a nada ser feito.\n\n");
                    }
            printf("\nPressione ENTER para voltar pro inicio...");
            getchar();
            getchar();
    }

void exercicio5 (){
        int n;

        printf("Digite um valor numerico: \n");
        scanf("%d", &n);
            if (n < 3){
                printf("Valor de N é menor que 3.\n\n");
            }
            else if (n > 3){
                printf("Valor de N é maior que 3.\n\n");
            }
            else {
                printf("valor de N é igual a 3\n\n");
            }
            printf("\nPressione ENTER para voltar pro inicio...");
            getchar();
            getchar();

         }

void exercicio6 (){
    float c, f;
    printf("Digite o valor em Celsius: \n");
        scanf("%f",&c);
        f = c * 9 / 5 + 32;
            printf("O valor em Fahrenheit é: %.2f\n\n", f);
            printf("\nPressione ENTER para voltar pro inicio...");
            getchar();
            getchar();
            

}

void exercicio7 (){
        float c, f;
    printf("Digite o valor em Fahrenheit: \n");
        scanf("%f",&f);
       c = ((f - 32) * 5) / 9;
            printf("O valor em Celsius é: %.2f\n\n", c);
            printf("\nPressione ENTER para voltar pro inicio...");
            getchar();
            getchar();


}

void exercicio8 (){
    float vol, alt, r;
        printf("Digite o valor do raio: \n");
            scanf("%f",&r);
        printf("Digite valor da altura: \n");
            scanf("%f",&alt);
        vol = 3.14159 * r * r * alt;
        printf("Volume é:%.2f unidades cubicas\n\n", vol);
        printf("\nPressione ENTER para voltar pro inicio...");
        getchar();
        getchar();

}

void exercicio9 (){
    float temp, vel, dist, ltu;
        printf("Informe o tempo gasto de viagem: \n");
            scanf("%f", &temp);
        printf("Informe a velocidade média da viagem: \n");
            scanf("%f", &vel);
        dist = temp * vel;
        ltu = dist / 12;
                printf("Velocidade média: %.2f\n", vel);
                printf("Tempo gasto na viagem: %.2f\n", temp);
                printf("Logo a quantidade de combustivel em litros usado foi de: %.2f\n\n", ltu);
                printf("\nPressione ENTER para voltar pro inicio...");
                getchar();
                getchar();

}

void exercicio10 (){
    float prest, val, tx, temp;
        printf("Informe o valor: \n");
            scanf("%f", &val);
        printf("Informe a taxa: \n");
            scanf("%f", &tx);
        printf("Infome o tempo: \n");
            scanf("%f", &temp);
                prest = val + (val * (tx / 100) * temp);
                printf("O valor da prestação é: %.2f\n\n", prest);
                printf("\nPressione ENTER para voltar pro inicio...");
                getchar();
                getchar();

}

void exercicio11 (){
    int a, b;
        printf("Insira o valor de A: \n");
            scanf("%d", &a);
        printf("Insira o valor de B: \n");
            scanf("%d", &b);

        printf("O valor de A é: %d", b);
        printf("O valor de B é: %d", a);
        printf("\nPressione ENTER para voltar pro inicio...");
        getchar();
        getchar();
}

void exercicio12 (){
    int a, b, c, d;
    int so1, so2, so3, so4, so5, so6;
    int m1, m2, m3, m4, m5, m6;

        printf("Digite os valores de A, B, C e D: \n");
        scanf("%d %d %d %d", &a, &b, &c, &d);
             so1 = a + b;
             so2 = a + c;
             so3 = a + d;
             so4 = b + c;
             so5 = b + d;
             so6 = c + d;

             m1 = a * b;
             m2 = a * c;
             m3 = a * d;
             m4 = b * c;
             m5 = b * d;
             m6 = c * d;

                printf("Somas:%d %d %d %d %d %d\n", so1, so2, so3, so4, so5, so6);

                printf("Multiplicações:%d %d %d %d %d %d\n", m1, m2, m3, m4, m5, m6);

                printf("\nPressione ENTER para voltar pro inicio...");
                getchar();
                getchar();

}

void exercicio13 (){
    float vol, comp, alt, larg;
        printf("Informe o valor do comprimento: \n");
            scanf("%f", &comp);
        printf("Informe o valor da altura: \n");
            scanf("%f", &alt);
        printf("Informe o valor da largura: \n");
            scanf("%f", &larg);
            vol = comp * alt * larg;
                printf("O volume total é: %.2f unidades cubicas\n\n\n", vol);
                    printf("\nPressione ENTER para voltar pro inicio...");  
                getchar();
                getchar();
}

void exercicio14 (){
    int val, res;
        printf("Digite o valor: \n");
            scanf("%d", &val);
            res = val * val;
            printf("O valor ao quadrado é: %d\n", res);
                printf("\nPressione ENTER para voltar pro inicio...");
                    getchar(); 
                    getchar();  

}

void exercicio15 (){
    int a, b, res;
        printf("Digite o valor de A: \n");
            scanf("%d", &a);
        printf("Digite o valor de B: \n");
            scanf("%d", &b);
            res = (a - b) * (a - b);
            printf("O resultado do quadrado da diferença entre eles é: %d\n ", res);
                    printf("\nPressione ENTER para voltar pro inicio...");  
                getchar();
                getchar();
}

void exercicio16 (){
    float real, cotdol, res, ttdol;
        printf("Informe a cotação atual do dolar em reais: ");
            scanf("%f", &cotdol);
        printf("Informe o montante que voce possui em dolares: ");
            scanf("%f", &ttdol);
                real = cotdol * ttdol;
                    printf("Diante do seu montante de %.2f, a cotação de %.2f R$, o valor em Reais (R$) é de: %f\n\n", ttdol, cotdol, real);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar();
                getchar();
}

void exercicio17 (){
        float real, cotdol, res, ttdol;
        printf("Informe a cotação atual do real em dolar: ");
            scanf("%f", &cotdol);
        printf("Informe o montante que voce possui em reais: ");
            scanf("%f", &ttdol);
                real = cotdol * ttdol;
                    printf("Diante do seu montante de %.2f, a cotação de %.2f $, o valor em Dolares ($) é de: %f\n\n", ttdol, cotdol, real);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();  
}

void exercicio18 (){
    int a, b, c, res;
        printf("Digite o valor de A, B e C: \n");
            scanf("%d %d %d", &a, &b, &c);
            res = (a * a) + (b * b) + (c * c);
                printf("O valor da soma de A, B e C e de seus quadrados é: %d\n\n", res);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar();  
                getchar();
}

void exercicio19 (){
    int a, b, c, res;
        printf("Digite o valor de A, B e C: \n");
            scanf("%d %d %d", &a, &b, &c);
            res = (a + b+ c) * (a + b + c);
                printf("O valor do quadrado da soma de A, B e C é: %d\n\n", res);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();  
}

void exercicio20 (){
    int a, b, c, d, p, s;
        printf("Insira o valor de A, B, C e D: \n");
            scanf("%d %d %d %d", &a, &b, &c, &d);
            p = a + c;
            s = b + d;
            printf("O valor de P é %d e o valor de S é %d\n\n", p, s);

                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();  
}

void exercicio21 (){
    float sm, pr, ns;
    char inpt;
        printf("Digite o valor do salario mensal: ");
            scanf("%f", &sm);
        printf("Digite o valor do porcentual de reajuste: ");
            scanf("%f", &pr);
        printf("Reajuste é para descontar ? [s] [n]\n");
            scanf(" %c", &inpt);
                if (inpt == 's')
                {
                    ns = sm - (sm * pr / 100);
                }
                else 
                {
                    ns = sm + (sm * pr / 100);
                }
            
        printf("Total do salario com reajuste é de: %.2f\n\n", ns);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();  

}

void exercicio22 (){
    float r, a;

        printf("Digite o valor do raio: ");
            scanf("%f", &r);
            a = 3.14159265 * r * r;

    printf("Area da circunferencia: %.2f\n", a);
    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();  

}

void exercicio23 (){
        int a;
        int b;
        int c;
        int n;//nulo
        int br; //branco
        int vv; //votos validos
        int t; //total votos
        float pw; //porcentagem total
        float pa; // porcentagem A
        float pb; // porcentagem B
        float pc; // porcentagem C
        float pn; // porcentagem neutro
        float pbr; // porcentagem branco

            printf("Digite numero de votos candidato A: ");
                scanf("%d", &a);
            printf("Digite numero de votos candidato B: ");
                scanf("%d", &b);
            printf("Digite numero de votos candidato C: ");
                scanf("%d", &c);
            printf("Digite numero de votos nulo: ");
                scanf("%d", &n);
            printf("Digite numero de votos brancos: ");
                scanf("%d", &br);

                    vv = a + b + c;
                    t = vv + n + br;
                    pw = vv * 100 /t;
                    pa = a * 100 /t;
                    pb = b * 100 /t;
                    pc = c * 100 /t;
                    pn = n * 100 /t;
                    pbr = br * 100 /t;


                printf("Total de votos:  %d\n", t);
                printf("Total de votos validos:  %d\n", vv);
                printf("Porcentagem de votos validos:  %.2f\n ", pw);
                printf("Porcentagem de votos candidato A:  %.2f\n", pa);
                printf("Porcentagem de votos candidato B:  %.2f\n", pb);
                printf("Porcentagem de votos candidato C:  %.2f\n", pc);
                printf("Porcentagem de votos nulos:  %.2f\n", pn);
                printf("Porcentagem de votos em branco:  %.2f\n ", pbr);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();
}

void exercicio24 (){
            float a, b;

            printf("Digite A: ");
                scanf("%f", &a);

            printf("Digite B: ");
                scanf("%f", &b);

                printf("Soma: %.2f\n", a + b);
                printf("Subtracao: %.2f\n", a - b);
                printf("Multiplicacao: %.2f\n", a * b);

                    if (b != 0)
                        printf("Divisao: %.2f\n", a / b);
                            else
                        printf("Divisao: impossivel (divisao por zero)\n");
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();

}

void exercicio25 (){
            float dist, temp, vel;

                printf("Digite a distancia (km): ");
                    scanf("%f", &dist);

                printf("Digite o tempo (min): ");
                    scanf("%f", &temp);
                    if (temp != 0) {
                            vel = (dist * 1000) / (temp * 60);
                        printf("Velocidade: %.2f m/s\n", vel);
                    } else {
                        printf("Erro: tempo nao pode ser zero\n");
                    }
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();

}

void exercicio26 (){
        float vol, raio;
            printf("Digite o valor do raio: ");
                scanf("%f", &raio);
                vol = (4.0 / 3.0) * 3.14159 * raio * raio * raio;
                    printf("Volume da esfera: %.2f unidades cubicas\n", vol);

                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();
}

void exercicio27 (){
        int base, exp, res = 1;

            printf("Digite a base: ");
                scanf("%d", &base);
            printf("Digite o expoente: ");
                scanf("%d", &exp);

                    for (int i = 0; i < exp; i++) {
                        res = res * base;
                    }

                        printf("Resultado: %d\n\n", res);
                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();


}

void exercicio28 (){
        float pe, metro;

            printf("Digite o valor em pes: ");
                scanf("%f", &pe);
                metro = pe * 0.3048;
                    printf("Valor em metros: %.2f\n\n", metro);

                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();

}

void exercicio29 (){

        double base, indice, res;

            printf("Digite a base: ");
                scanf("%lf", &base);
            printf("Digite o indice: ");
                scanf("%lf", &indice);

                    if (indice != 0) 
                    {
                        res = pow(base, 1.0 / indice);
                            printf("Resultado: %.2lf\n", res);
                    }
                    else
                    {
                    printf("Erro: indice nao pode ser zero\n");
                    }

                    printf("\nPressione ENTER para voltar pro inicio...");
                getchar(); 
                getchar();


}

void exercicio30 (){
        int n, suc, ant;

            printf("Digite um numero inteiro: ");
                scanf("%d", &n);
                    suc = n + 1;
                    ant = n - 1;
                        printf("O numero digitado foi: %d\n", n);
                        printf("O sucessor do numero digitado é: %d\n", suc);
                        printf("O antecessor do numero digitado é: %d\n\n", ant);
                
                        printf("\nPressione ENTER para voltar pro inicio...");
                    getchar(); 
                    getchar();
                        
}

void exercicio31 (){
        float a, b, res;
        printf("Digite o valor de A: \n");
            scanf("%f", &a);
        printf("Digite o valor de B: \n");
            scanf("%f", &b);
            if (b != 0) {
                res = (a /b) * (a / b);
                printf("Resultado é: %.2f\n\n", res);
            } 
            else 
            {
                printf("Erro: divisão por zero não é permitida.\n\n");
                    
                    
            }
                                printf("\nPressione ENTER para voltar pro inicio...");
                            getchar(); 
                            getchar();  
}

void (*exercicios[]) () = {
 exercicio1,
 exercicio2,
 exercicio3,
 exercicio4,
 exercicio5,
 exercicio6,
 exercicio7,
 exercicio8,
 exercicio9,
 exercicio10,
 exercicio11,
 exercicio12,
 exercicio13,
 exercicio14,
 exercicio15,
 exercicio16,
 exercicio17,
 exercicio18,
 exercicio19,
 exercicio20,
 exercicio21,
 exercicio22,
 exercicio23,
 exercicio24,
 exercicio25,
 exercicio26,
 exercicio27,
 exercicio28,
 exercicio29,
 exercicio30,
 exercicio31
};


int main (){
    int opcao;

    while(1) {

    printf("\033[1;97m"); // branco forte

    printf("============================================================\n");
    printf("                   ESCOLHA O EXERCICIO           \n");
    printf("============================================================\n");

    printf("\033[0m"); // reset da cor

    printf("\033[1;97m");
    printf(" [01] Ler 2 valores              [02] Adicao\n");
    printf(" [03] Condicional simples        [04] Condicional composta\n");
    printf(" [05] Decisao sequencial         [06] Celsius -> Fahrenheit\n");
    printf(" [07] Fahrenheit -> Celsius      [08] Volume cilindro\n");
    printf(" [09] Consumo combustivel        [10] Prestacao\n");
    printf(" [11] Troca valores              [12] Soma/multiplicacao\n");
    printf(" [13] Volume caixa               [14] Quadrado numero\n");
    printf(" [15] Quadrado diferenca         [16] Dolar -> Real\n");
    printf(" [17] Real -> Dolar              [18] Soma quadrados\n");
    printf(" [19] Quadrado soma              [20] Soma pares\n");
    printf(" [21] Reajuste salarial          [22] Area circunferencia\n");
    printf(" [23] Apuracao votos             [24] Operacoes\n");
    printf(" [25] Velocidade                 [26] Volume esfera\n");
    printf(" [27] Potencia loop              [28] Pes -> metros\n");
    printf(" [29] Potencia pow               [30] Sucessor\n");
    printf(" [31] Quadrado divisao\n");

    printf("\033[1;97m"); // branco forte
    printf("\n [00] Encerrar\n");
    printf("\033[0m");

    printf("\n\033[1;97mEscolha: \033[0m");

    scanf("%d", &opcao);

    int total = sizeof(exercicios) / sizeof(exercicios[0]);
        if (opcao >= 1 && opcao <= total){
            exercicios[opcao - 1]();
        }
        else if (opcao == 0 && opcao == 00){
            printf("Encerrando... \n");
            return 0;
        }

        else if (opcao == 42){
            printf("\033[1;93m Acessando \033[0m");
            sleep(2);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;93m .\033[0m ");
            sleep(1);
            printf("\n\033[1;91m [DEBUG] Easter egg detectado...\033[0m \n");
            sleep(3);
            printf("\033[1;93m Sinal do vazio do espaço-tempo detectado.\033[0m \n");
            sleep(2);
            printf("\033[1;93m Resposta para tudo encontrada.\033[0m \n");
            sleep(2);
            printf("\033[1;92m A resposta para a pergunta fundamental sobre a vida, o universo e tudo mais é: 42\033[0m \n");
            sleep(2);
            printf("\033[1;92m Parabens você encontrou o easter egg!\033[0m \n");
            sleep(4);
                printf("\nPressione ENTER para voltar pro inicio...");  
                getchar();  
                getchar();
        }
        else {
            printf("Valor inserido invalido.\n\n\n\n\n\n\n");
        }
    }
}
