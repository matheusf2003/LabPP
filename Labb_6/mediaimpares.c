/*
 * Arquivo: mediaimpares.c
 * Data criação: 12/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

typedef
    unsigned long long int
ullint;

void impares(int n, ullint s, ullint * vetor);
void imprime(int n, ullint * vetor);
double media(int n, ullint * vetor);

int main (void) {
    ullint * vetor;
    int n;
    ullint s;
    printf("Número de elementos: ");
    scanf("%d%*c", &n);
    printf("Número inicial: ");
    scanf("%llu%*c", &s);
    if(s%2 == 0)
        s++;
    vetor = (ullint *) malloc(n*sizeof(ullint));
    impares(n, s, vetor);
    imprime(n, vetor);
    free(vetor);
    return 0;
}

void impares(int n, ullint s, ullint * vetor){
    for(int i = n, count = 0; i > 0; i--, count++, s += 2)
        vetor[count] = s;
}

void imprime(int n, ullint * vetor){
    printf("%llu\t%lg\n", vetor[n-2], media(n, vetor));
}

double media(int n, ullint * vetor){
    double media = 0;
    for(int i = 0; i < n; i++)
        media += vetor[i];
    return media / n;
}
