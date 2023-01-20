/*
 * Arquivo: txtFibonacci.c
 * Data criação: 19/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

typedef
    unsigned long long int
ullint;

ullint Fib(int n, FILE * arq);

int main (void) {
    int n;
    FILE * arq = fopen("fibonacci.txt", "w");
    if(arq == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Digite um número N tal que 0 <= N <= 94: ");
    scanf("%d%*c", &n);
    printf("Fib[%d] = %llu\n", n, Fib(n, arq));
    fclose(arq);
    return 0;
}

ullint Fib(int n, FILE * arq){
    ullint fibo[n+2];
    fibo[0] = 0;
    fibo[1] = 1;
    fprintf(arq, "0\n1\n");
    for(int i = 2; i < n; i++){
        fibo[i] = fibo[i-2] + fibo[i-1];
        fprintf(arq, "%llu\n", fibo[i]);
    }
    return fibo[n-1];
}