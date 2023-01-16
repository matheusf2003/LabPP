/*
 * Arquivo: golomb.c
 * Data criação: 15/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

typedef
    long int
lint;

int golomb(lint n, int * lista);
double media(int * v, lint inicio, lint final);

int main(void){
    lint a, b;
    int * lista;
    printf("Digite o primeiro indice: ");
    scanf("%ld", &a);
    printf("Digite o segundo indice: ");
    scanf("%ld", &b);
    if(b < a) { lint aux = a; a = b; b = aux; }
    lista = (int *) malloc((b+1)*sizeof(int));
    for(lint i = 0; i <= b; i++)
        lista[i] = 0;
    golomb(b, lista);
    printf("primeiro: %d\túltimo: %d\tmédia: %lg\n", lista[a], lista[b], media(lista, a, b));
    free(lista);
    return 0;
}

int golomb(lint n, int * lista){
    if(lista[n] != 0)
        return  lista[n];
    if(n == 0)
        lista[n] = 1;
    else
        lista[n] = 1 + golomb(n - golomb(golomb(n - 1, lista) - 1, lista), lista);
    return lista[n];
}

double media(int * v, lint inicio, lint final) {
    lint m = 0;
    for(lint i = inicio; i <= final; i++)
        m += v[i];
    return ((double) m)/(final - inicio + 1);
}
