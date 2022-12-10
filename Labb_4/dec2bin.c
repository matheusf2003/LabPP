/*
 * Arquivo: .c
 * Data criação: 08/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

unsigned long long int decbin(unsigned long long int n, unsigned long long int bin);

int main (void) {
    unsigned long long int n;
    printf("Digite um número decimal de no máximo 64 bits:\n");
    scanf("%llu", &n);
    printf("%llu\n", decbin(n, 0));

    return 0;
}

unsigned long long int decbin(unsigned long long int n, unsigned long long int bin){
    if(n / 2 > 0){
        bin = bin * 10 + decbin(n/2, bin);
    }
    return bin * 10 + n % 2;
}
