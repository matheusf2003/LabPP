/*
 * Arquivo: fibonacci.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(){
    int n, t, j=1, i=0;
    printf("Posição maxima: ");
    scanf("%d", &n);
    for(int k=1; k <= n; t = i + j, i = j, j = t, k++){
        printf("%d, ", i);
    }
    printf("...\n");
}
