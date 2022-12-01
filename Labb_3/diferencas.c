/*
 * Arquivo: diferencas.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int Max(float * vetor,int tamV);
int Min(float * vetor,int tamV);

int main(void){
    int N, ref, min, max;
    printf("Quantos elementos? ");
    scanf("%d", &N);
    float vetorA[N], vetorB[N-1]; // C99 only!! variable length array
    for(int i = 0; i < N; i++) {
        printf("Informe o %dº elemento: ", i+1);
        scanf("%f", vetorA+i);
    }
    for(int i=0; i < N-1; i++)
        vetorB[i] = vetorA[i+1] - vetorA[i];
    for(int i=0; i < N-1; i++)
        printf("%g ", vetorB[i]);
    min = Min(vetorB, N-1);
    max = Max(vetorB, N-1);
    printf("\nmin = %g\nmax = %g", vetorB[min], vetorB[max]);
    return 0;
    
}

int Max(float * vetor,int tamV){
    int max = 0;
    for(int i=1; i < tamV; i++)
        if(vetor[i]>vetor[max])
            max = i;
    return max;
}

int Min(float * vetor,int tamV){
    int min = 0;
    for(int i=1; i < tamV; i++)
        if(vetor[i]<vetor[min])
            min = i;
    return min;
}