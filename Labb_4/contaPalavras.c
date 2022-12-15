/*
 * Arquivo: contaPalavras.c
 * Data criação: 15/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

void getstr(char * str, long long int nchar);
int contapalavra(char * str, long long int nchar);
void upper(char * str);
long long int len(char * str);

int main(void) {
    int np;
    char msg[N];
    getstr(msg, N);
    upper(msg);
    np = contapalavra(msg, len(msg));
    printf("%d", np);
    return 0;
}

void getstr(char * str, long long int nchar) {
    char c;
    long long int i;
    for(i = 0; i < nchar && (c = getchar()) != '\n'; i++)
        str[i] = c;
    str[(i >= nchar) ? nchar - 1 : i] = '\0';
    if(i >= nchar) // precisa limpar o buffer do teclado
        while ((c = getchar()) != '\n' && c != EOF);
}

int contapalavra(char * str, long long int nchar) {
    int palavra = 0, count = 0;
    str[nchar] = ' ';
    str[nchar+1] = '\0';
    for(int i=0; i <= nchar;i++){
        if(!palavra && ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <='9'))){
            palavra = 1;
        } else if(str[i] == ' '){
            if(palavra){
                count += 1;
                palavra = 0;
            }
        }
    }
    return count;
}

void upper(char * str) {
    long long int l = 0;
    while(str[l]) {
        if(str[l] >= 'a' && str[l] <= 'z')
            str[l] -= 'a' - 'A';
        l++;
    }
}

long long int len(char * str) {
    long long int l = 0;
    while(str[l]) l++;
    return l;
}