/*
 * Arquivo: muSigma.c
 * Data criação: 01/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <math.h>

float media(float * vetor, int tamV);
float somatorio(float * vetor, int tamV);
float desvio(float * vetor, int tamV, float media);

int main(void){
    int N, ref;
    float Media, Desvio;
    printf("Quantos elementos? ");
    scanf("%d", &N);
    float vetor[N]; // C99 only!! variable length array
    for(int i = 0; i < N; i++) {
        printf("Informe o %dº elemento: ", i+1);
        scanf("%f", vetor+i);
    }
    Media = media(vetor, N);
    Desvio = desvio(vetor, N, Media);
    printf("média %g, desvio %g", Media, Desvio);

    return 0;
}

float media(float * vetor, int tamV){
    return somatorio(vetor, tamV) / tamV;
}

float desvio(float * vetor, int tamV, float media){
    float soma=0;
    for(int i=0; i<tamV; i++)
        soma += pow(vetor[i]-media, 2);
    return sqrt(soma/tamV);
}

float somatorio(float * vetor, int tamV){
    float soma=0;
    for(int i=0;i<tamV;i++)
        soma += vetor[i];
    return soma;
}