/*
 * Arquivo: remNegativos.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int vazio(int * vetor, int tamV);

int main(void){
    int N, ref;
    printf("Quantos elementos? ");
    scanf("%d", &N);
    int vetor[N]; // C99 only!! variable length array
    for(int i = 0; i < N; i++) {
        printf("Informe o %dº elemento: ", i+1);
        scanf("%d", vetor+i);
    }
    if(vazio(vetor, N))
        printf("vazio");
    else
        for(int i=0; i<N; i++)
            if(vetor[i]>=0)
                printf("%d, ", vetor[i]);
    return 0;
}

int vazio(int * vetor, int tamV){
    for(int i=0; i<tamV; i++)
        if(vetor[i]>=0)
            return 0;
    return 1;
}