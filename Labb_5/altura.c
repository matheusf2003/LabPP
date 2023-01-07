/*
 * Arquivo: altura.c
 * Data criação: 05/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>

typedef
    struct Comprimento
    {
        int metros, cemtimetros;
    }
Comprimento;

int cm(int x);

int main (void) {
    Comprimento altura;
    printf("Altura: ");
    scanf("%d.%d", &altura.metros, &altura.cemtimetros);
    printf("Altura %dm%d\n", altura.metros, cm(altura.cemtimetros));

    return 0;
}

int cm(int x) {
    if(x < 10)
        return x*10;
    if(x > 99)
        return cm(x/10);
    return x;
}