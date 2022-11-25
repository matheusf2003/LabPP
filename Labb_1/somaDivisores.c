/*
 * Arquivo: somaDivisores.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void) {
    int n, div=0;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        if (n % i == 0){
            div = div + i;
        }
    }
    printf("%d\n", div);
}