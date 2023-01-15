/*
 * Arquivo: aleatorios.c
 * Data criação: 14/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

long double aleatorio(unsigned int n, int * vetor, int * minmax);
void imprime(int * minmax, long double media);

int main(void){
    unsigned int n;
    long double media;
    int minmax[2];  // minmax[0] = minimo   minmax[1] =  maximo
    printf("Número de elementos: ");
    scanf("%u%*c", &n);
    int vetor[n];
    media = aleatorio(n, vetor,  minmax);
    imprime(minmax, media);
    return 0;
}

long double aleatorio(unsigned int n, int * vetor, int * minmax){
    long double media = 0;
    srand(n);
    for(unsigned int i = 0; i < n; i++){
        vetor[i] = rand() % n;
        media += vetor[i];
        if(i == 0){
            minmax[0] = vetor[i];
            minmax[1] = vetor[i];
        } else if(vetor[i] < minmax[0])
            minmax[0] = vetor[i];
        else if(vetor[i] > minmax[1])
            minmax[1] = vetor[i];
    }
    return media / n;
}

void imprime(int * minmax, long double media){
    printf("mínimo: %d\tmáximo: %d\tmédia: %Lg", minmax[0], minmax[1], media);
}
