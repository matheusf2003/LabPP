/*
 * Arquivo: fibonacci.c
 * Data criação: 05/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>

int fib(int n);

int main (void) {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    printf("%d\n", fib(n));
    return 0;
}

int fib(int n){
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    else
        return (fib(n-1) + fib(n-2));
}