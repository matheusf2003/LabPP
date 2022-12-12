/*
 * Arquivo: bin2dec.c
 * Data criação: 10/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>
#define N 1024

unsigned long long getstr(char * str, int nchar);
long long int len(char * str);
void bin2dec(char * nstr, int nchar);

int main(void){
    char str[N];
    printf("Digite um número bináraio de até 64 bits:\n");
    getstr(str, N);
    bin2dec(str, len(str));
    return 0;
}

unsigned long long getstr(char * str, int nchar) {
    char c;  int i, i2=0;
    unsigned long long int n = 0;
    for(i = 0; i < nchar; i++) {
        c = getchar();
        if(c != '\n') {
            if(c == '1' || c == '0'){
                str[i2] = c;
                i2++;
            }
        } else {
            str[i2] = '\0';
            break;
        }
    }
    if(i == nchar) {
        str[nchar-1] = '\0';
        // limpar buffer teclado
        while ((c = getchar()) != '\n' && c != EOF);
    }
    return n;
}

long long int len(char * str) {
    long long int l = 0;
    while(str[l]) l++;
    return l;
}

void bin2dec(char * nstr, int nchar){
    unsigned long long int n = 0;
    for(int i=nchar-1, i2=0; i >= 0; i--, i2++)
        n += (nstr[i] - 48) * 1 << i2;
    printf("Em decimal: %d\n", n);
}