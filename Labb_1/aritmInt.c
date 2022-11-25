/*
 * Arquivo: aritInt.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void){
    int n1;
    int n2;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &n1, &n2);
    printf("%d+%d = %d, ", n1, n2, n1+n2);
    printf("%d-%d = %d, ", n1, n2, n1-n2);
    printf("%d*%d = %d, ", n1, n2, n1*n2);
    printf("%d/%d = %d, ", n1, n2, n1/n2);
    printf("%d%%%d = %d\n", n1, n2, n1%n2);
}