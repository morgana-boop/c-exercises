#include<stdio.h>
#define V 5
int v[V];
void a(){int x,y;for(int i=0;i<V;i++){printf("Digite o valor: ");scanf("%d",&x);printf("Qual posição será armazenado (0 a 4): ");scanf("%d",&y);v[y]=x;}}
void b(){int x;printf("Digite o valor que deseja buscar: ");scanf("%d",&x);for(int i=0;i<V;i++)if(x==v[i])printf("Valor na posição: %d\n",i);}
void c(){int x;printf("Digite informação que deseja remover: ");scanf("%d",&x);for(int i=0;i<V;i++)if(x==v[i])v[i]=0;for(int i=0;i<V;i++)printf("posição %d com valor armazenado: %d\n",i,v[i]);}
int main(){a();for(int i=0;i<V;i++)printf("vetor[%d] = %d\n",i,v[i]);b();c();}