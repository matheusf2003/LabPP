/*
 * Arquivo: somatorio.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

float somatorio(float * vetor, int tamV);

int main(void){
    int N;
    float soma;
    printf("Número de elementos: ");
    scanf("%d", &N);
    float vetor[N];
    for(int i=0; i<N; i++){
        printf("Elemento[%d]: ", i+1);
        scanf("%f", vetor+i);
    }
    soma = somatorio(vetor, N);
    for(int i=0;i<N;i++){
        printf("%g", vetor[i]);
        if(i==N-1)
            printf(" = ");
        else
            printf(" + ");
    }
    printf("%g\n", soma);
    return 0;
}

float somatorio(float * vetor, int tamV){
    float soma=0;
    for(int i=0; i<tamV; i++)
        soma += vetor[i];
    return soma;
}