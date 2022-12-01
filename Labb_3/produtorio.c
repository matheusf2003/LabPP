/*
 * Arquivo: produtorio.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

float produtorio(float * vetor, int tamV);

int main(void){
    int N;
    float produto;
    printf("Número de elementos: ");
    scanf("%d", &N);
    float vetor[N];
    for(int i=0; i<N; i++){
        printf("Elemento[%d]: ", i+1);
        scanf("%f", vetor+i);
    }
    produto = produtorio(vetor, N);
    for(int i=0; i<N; i++){
        printf("%g", vetor[i]);
        if(i==N-1)
            printf(" = ");
        else
            printf(" * ");
    }
    printf("%g\n", produto);
    return 0;
}

float produtorio(float * vetor, int tamV){
    float produto=1;
    for(int i=0; i<tamV; i++)
        produto *= vetor[i];
    return produto;
}