/*
 * Arquivo: fatorial.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(){
    int n;
    long multiplicação = 1, multiplicação1;
    printf("Digite um número inteiro maior que 1: ");
    scanf("%d", &n);
    for (int i=1; i <= n; i++){
        multiplicação1 = multiplicação;
        multiplicação = multiplicação1 * i;
    }
    printf("%ld\n", multiplicação);
}