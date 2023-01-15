/*
 * Arquivo: golomb.c
 * Data criação: 15/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

int golomb(int n, int * lista);
double media(int * v, int inicio, int final);

int main(void){
    int a, b;
    int * lista;
    printf("Digite o primeiro indice: ");
    scanf("%d", &a);
    printf("Digite o segundo indice: ");
    scanf("%d", &b);
    if(b < a) { int aux = a; a = b; b = aux; }
    lista = (int *) malloc(b*sizeof(int));
    for(int i = 0; i <= b; i++)
        lista[i] = 0;
    golomb(b, lista);
    printf("primeiro: %d\túltimo: %d\tmédia: %lg", lista[a], lista[b], media(lista, a, b));
    free(lista);
    return 0;
}

int golomb(int n, int * lista){
    if(lista[n] != 0)
        return  lista[n];
    if(n == 0)
        lista[n] = 1;
    else if(n == 1)
        lista[n] = 2;
    else
        lista[n] = 1 + golomb(n - golomb(golomb(n - 1, lista) - 1, lista), lista);
    return lista[n];
}

double media(int * v, int inicio, int final) {
    int m = 0;
    for(int i = inicio; i <= final; i++)
        m += v[i];
    return ((double) m)/(final - inicio + 1);
}
