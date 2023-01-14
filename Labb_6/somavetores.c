/*
 * Arquivo: somavetores.c
 * Data criação: 12/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool soma(int * v1, int N1, int * v2, int N2, int * resultado);
void impares(int n, int * vetor);
void mult4(int n, int * vetor);
void imprime(int n, int * v1, int * v2);

int main (void) {
    int * vetor1;
    int * vetor2;
    int * resultado;
    int N1, N2;
    printf("Tamanho vetor 1: ");
    scanf("%d%*c", &N1);
    printf("Tamanho vetor 2: ");
    scanf("%d%*c", &N2);
    vetor1 = (int *) malloc(N1*(sizeof(int)));
    vetor2 = (int *) malloc(N2*(sizeof(int)));
    resultado = (int *) malloc(N1*(sizeof(int)));
    if(soma(vetor1, N1, vetor2, N2, resultado))
        imprime(N1, vetor1, vetor2);
    else
        printf("mensagem que não pode somar vetores");
    printf("\n");
    free(vetor1);
    free(vetor2);
    free(resultado);
    return 0;
}

bool soma(int * v1, int N1, int * v2, int N2, int * resultado){
    if(N1 != N2)
        return false;
    impares(N1, v1);
    mult4(N2, v2);
    return true;
}

void impares(int n, int * vetor){
    int s = 1;
    for(int i = 0; i < n; i++, s += 2)
        vetor[i] = s;
}

void mult4(int n, int * vetor){
    int m = 0;
    for(int i = 0; i < n; i++, m += 4)
        vetor[i] = m;
}

void imprime(int n, int * v1, int * v2){
    for(int i = 0; i < n; i++){
        printf("%d", v1[i] + v2[i]);
        if(i != n-1)
            printf(", ");
    }
}