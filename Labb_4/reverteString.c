/*
 * Arquivo: reverteString.c
 * Data criação: 08/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

void getstr(char * str, int nchar);
void upper(char * str);
long long int len(char * str);
void reverte(char * str, long long int nchar, char * rstr);


int main (void) {
    char s[N], * rev;
    printf("Digite sua mensagem: \n");
    getstr(s, N);
    reverte(s, len(s), rev);
    upper(rev);
    printf("%s\n", rev);
    return 0;
}

void upper(char * str) {
    long long int l = 0;
    while(str[l]) {
        if(str[l] >= 'a' && str[l] <= 'z')
            str[l] -= 'a' - 'A';
        l++;
    }
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

void reverte(char * str, long long int nchar, char * rstr){
    for(int i = nchar-1, i2 = 0; i >= 0;i--, i2++)
        rstr[i2] = str[i];
    rstr[nchar] = '\0';
}