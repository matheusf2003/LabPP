/*
 * Arquivo: palindromo.c
 * Data criação: 12/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

void getstr(char * str, int nchar);
void upper(char * str);
long long int len(char * str);
void clearstr(char * str);
int palindromo(char * str, int nchar);

int main (void) {
    char str[N];
    getstr(str, N);
    upper(str);
    clearstr(str);
    printf("Palindormo: ");
    if(palindromo(str, len(str)))
        printf("Verdadeiro\n");
    else
        printf("Falso\n");

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

void clearstr(char * str){
    long long int i = 0;
    for(long long int l = 0; str[l]; l++){
        if(str[l] >= 'A' && str[l] <= 'Z'){
            str[i] = str[l];
            i++;
        }
    }
    str[i] = '\0';
}

int palindromo(char * str, int nchar){
    for(long long int li = 0, lf = nchar - 1; lf >= 0; li++, lf--)
        if(str[li] != str[lf])
            return 0;
    return 1;
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