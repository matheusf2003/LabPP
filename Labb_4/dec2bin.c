/*
 * Arquivo: .c
 * Data criação: 08/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int casaDec(unsigned int n);
unsigned int decbin(unsigned int n, unsigned int bin, int cd);

int main (void) {
    unsigned int n, bin=0;
    printf("Digite um número decimal de no máximo 64 bits:\n");
    scanf("%lld", &n);
    printf("%lld", decbin(n, bin, casaDec(n)));

    return 0;
}

unsigned int decbin(unsigned int n, unsigned int bin, int cd){
    if(n / 2 > 0){
        bin *= 10 << cd;
        bin += (decbin(n/2, bin, cd-1));
    }
    printf("bin = %lld\tcd = %d\n", bin, cd);
    return bin << cd + n%2;
}

int casaDec(unsigned int n){
    int count = 0;
    for(int i=1; 1;i *= 10, count++){
        if(n/i == 0)
            return count;
    }
}