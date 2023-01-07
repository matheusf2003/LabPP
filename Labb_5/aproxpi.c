/*
 * Arquivo: aproxpi.c
 * Data criação: 05/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <math.h>

long double aproxima(int n);

int main (void) {
    int n;
    long double pi;
    printf("Digite um número: ");
    scanf("%d", &n);
    pi = aproxima(n);
    printf("%Lf", pi);
    return 0;
}

long double aproxima(int n){
    if (n == 0)
        return 4.0;
    else{
        int i2;
        if(n % 2 == 0)
            i2 = 1;
        else
            i2 = -1;
        return (aproxima(n-1) + (4 * ((long double)i2 / (long double)(2 * n + 1))));
    }
}