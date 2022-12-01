/*
 * Arquivo: somaPrimos.c
 * Data criação: 26/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int primo(int n);

int main (void) {
    int n1, n2, soma =0;
    printf("Digite dois números (a b) sendo a < b: ");
    scanf("%d %d", &n1, &n2);
    for(int i = n1; i <= n2; i++)
        if(primo(i))
            soma += i;
    printf("%d\n", soma);
    return 0;
}

int primo(int n){
    if(n==1)
        return 0;
    if(n % 2 == 0 & n != 2)
        return 0;
    for(int i = 2; i < n / 2; i++)
        if(n % i == 0)
            return 0;
    return 1;
}