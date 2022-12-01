/*
 * Arquivo: minMax.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int Max(int * vetor,int tamV);
int Min(int * vetor,int tamV);

int main(void){
    int N, max, min;
    printf("Quantidade de elementos: ");
    scanf("%d", &N);
    int vetor[N];
    for(int i=0; i < N; i++){
        printf("Elemento[%d]: ", i+1);
        scanf("%d", vetor+i);
    }
    max = Max(vetor, N);
    min = Min(vetor, N);
    for(int i=0; i < N; i++){
        printf("%d", vetor[i]);
        if(vetor[i]==max)
            printf(">");
        if(vetor[i]==min)
            printf("<");
        printf(" ");
    }
    printf("\n");
    return 0;
}

int Max(int * vetor,int tamV){
    int max = vetor[0];
    for(int i=0; i < tamV; i++)
        if(vetor[i]>max)
            max = vetor[i];
    return max;
}

int Min(int * vetor,int tamV){
    int min = vetor[0];
    for(int i=0; i < tamV; i++)
        if(vetor[i]<min)
            min = vetor[i];
    return min;
}