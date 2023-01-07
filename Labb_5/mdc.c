/*
 * Arquivo: mdc.c
 * Data criação: 05/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>

int mdc(int n1, int n2);

int main (void) {
    int a, b;
    printf("Digite dois números: ");
    scanf("%d %d", &a, &b);
    printf("mdc = %d\n", mdc(a, b));
    return 0;
}

int mdc(int n1, int n2){
    if(n2 == 0)
        return n1;
    return mdc(n2, n1 % n2);
}