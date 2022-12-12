/*
 * Arquivo: contaCaracteres.c
 * Data criação: 12/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

void getstr(char * str, int nchar);
long long int len(char * str);

int main (void) {
    int letra = 0, num = 0, outro =0;
    char str[N];
    getstr(str, N);
    for(long long int i = 0; i <= len(str) - 1; i++){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            letra += 1;
        else if(str[i] >= '0' && str[i] <= '9')
            num += 1;
        else
            outro += 1;
    }
    printf("letras: %d dígitos: %d outros: %d\n", letra, num, outro);
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

long long int len(char * str) {
    long long int l = 0;
    while(str[l]) l++;
    return l;
}