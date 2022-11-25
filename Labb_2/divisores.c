/*
 * Arquivo: divisores.c
 * Data criação: 24/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void) {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        if (n % i == 0)
            printf("%d, ", i);
    return 0;
}