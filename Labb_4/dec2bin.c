/*
 * Arquivo: dec2bin.c
 * Data criação: 08/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

// unsigned long long int decbin(unsigned long long int n, unsigned long long int bin);
void dec2bin(unsigned long long int n, long int casa);
unsigned long long int binaryslot(unsigned long long int n);
// void decbin(unsigned long long int n, char * bin)

int main (void) {
    unsigned long long int n;
    printf("Digite um número decimal de no máximo 64 bits:\n");
    scanf("%llu", &n);
    dec2bin(n, binaryslot(n)-1);
    printf("\n");
    // printf("%llu\n", decbin(n, 0));
    return 0;
}
/*
unsigned long long int decbin(unsigned long long int n, unsigned long long int bin){
    if(n / 2 > 0)
        bin = bin * 10 + decbin(n/2, bin);
    return bin * 10 + n % 2;
}
*/

void dec2bin(unsigned long long int n, long int casa){
    if(n>>(casa) & 1)
        printf("1");
    else
        printf("0");
    if(casa>0)
        dec2bin(n, casa-1);
}

unsigned long long int binaryslot(unsigned long long int n){
    unsigned long long int count = 0;
    for(int i= 0; n>0;i++){
        count += 1;
        n /= 2;
    }
    return count;
}