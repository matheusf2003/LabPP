/*
 * Arquivo: somaSeqHailst.c
 * Data criação: 24/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void){
    int n, soma = 0;
    scanf("%d", &n);
    soma += n;
    for(int i = 0; n != 1; i++){
        if(n%2==0){
            n /= 2;
        } else {
            n = 3 * n +1;
        }
        soma += n;
    }
    printf("%d", soma);
    return 0;
}