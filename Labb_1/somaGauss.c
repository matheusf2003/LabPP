/*
 * Arquivo: somaGauss.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(){
    int n, soma, soma1;
    printf("Digite um número maior que 1: ");
    scanf("%d", &n);
    for (int i=1; i <= n; i++){
        soma1 = soma;
        soma = soma1 + i;
    }
    printf("%d\n", soma);
}
