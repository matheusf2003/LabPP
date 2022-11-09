/*
 * Arquivo: fatorial.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(){
    int n;
    long mult = 1, mult1;
    printf("Digite um número inteiro maior que 1: ");
    scanf("%d", &n);
    for (int i=1; i <= n; i++){
        mult1 = mult;
        mult = mult1 * i;
    }
    printf("%d! = %ld\n", n, mult);
}

int fat(int n){
    if (n == 0)
        return 1;
    else
        return n * fat(n-1);
}