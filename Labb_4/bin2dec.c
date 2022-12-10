/*
 * Arquivo: bin2dec.c
 * Data criação: 10/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>
#define N 1024

void getstr(char * str, int nchar);
char * str2int(char * str, int nchar, char * num);
long long int len(char * str);
unsigned long long int bin2dec(char * nstr, int nchar);

int main(void){
    char str[N];
    char strn[N];
    unsigned long long int dec;
    printf("Digite um número bináraio de até 64 bits:\n");
    getstr(str, N);
    str2int(str, len(str), strn);
    dec = bin2dec(strn, len(strn));
    printf("%llu\n", dec);
    return 0;
}

void getstr(char * str, int nchar) {
    char c;  int i;
    for(i = 0; i < nchar; i++) {
        c = getchar();
        if(c != '\n') {
            str[i] = c;
        } else {
            str[i] = '\0';
            break;
        }
    }
    if(i == nchar) {
        str[nchar-1] = '\0';
        // limpar buffer teclado
        while ((c = getchar()) != '\n' && c != EOF);
    } 
}

char * str2int(char * str, int nchar, char * num){
    int n =0;
    for(int i=0; i < nchar; i++)
        if(str[i] >= '0' && str[i]<= '9'){
            num[n] = str[i];
            n += 1;
        }
    num[n] = '\0';
}

long long int len(char * str) {
    long long int l = 0;
    while(str[l]) l++;
    return l;
}

unsigned long long int bin2dec(char * nstr, int nchar){
    unsigned long long int n = 0;
    for(int i=nchar-1, i2=0; i >= 0; i--, i2++)
        n += (nstr[i] - 48) * 1 << i2;
    return n;
}