/*
 * Arquivo: contaVogais.c
 * Data criação: 08/dez/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#define N 1024

void getstr(char * str, int nchar);
int contaVogal(char * str, int nchar);

int main (void) {
    char s[N];
    printf("Digite uma palavra: ");
    getstr(s, N);
    printf("%d\n", contaVogal(s, N));


    return 0;
}

void getstr(char * str, int nchar) {
    char c;  int i;
    for(i = 0; i < nchar; i++) {
        c = getchar();
        if(c != '\n' && c != ' ') {
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

int contaVogal(char * str, int nchar){
    char vogais[10] = "aeiouAEIOU";
    int l = 0, v = 0;
    while(str[l]){
        for(int i=0; i<=10; i++){
            if(str[l] == vogais[i])
                v += 1;
        }
        l++;
    }
    return v;
}