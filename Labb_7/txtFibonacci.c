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

ullint Fib(int n, FILE * arq); // Função usando laço
ullint Fib_rec(int n, FILE * arq, ullint * fibolist); // Função recursiva

int main (void) {
    int n;
    ullint * fibolist;
    FILE * arq = fopen("fibonacci.txt", "w");
    if(arq == NULL){
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Digite um número N tal que 1 <= N <= 94: ");
    scanf("%d%*c", &n);
    if(n < 1 || n > 94){
        printf("Digite um número maior que 0 e menor que 95.");
        return 0;
    }
    fibolist = (ullint *) malloc((n + 1) * sizeof(ullint));
    for(int i = 0; i <= n; i++)
        fibolist[i] = 0;
    fprintf(arq, "0\n");
    if(n > 1){
        fibolist[1] = 1;
        fprintf(arq, "1\n");
    }
    printf("Fib[%d] = %llu\n", n, Fib_rec(n - 1, arq, fibolist));
    fclose(arq);
    free(fibolist);
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

ullint Fib_rec(int n, FILE * arq, ullint * fibolist){
    if(fibolist[n] != 0)
        return fibolist[n];
    if(n <= 1)
        return n;
    fibolist[n] = Fib_rec(n-1, arq, fibolist) + Fib_rec(n-2, arq, fibolist);
    fprintf(arq, "%llu\n", fibolist[n]);
    return fibolist[n];
}
