/*
 * Arquivo: golomb.c
 * Data criação: 15/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>

typedef
    long long int
llint; 

llint golomb(int n, llint * lista);
double media(llint * v, llint inicio, llint final);

int main(void){
    int a, b;
    llint * lista;
    printf("Digite o primeiro indice: ");
    scanf("%d", &a);
    printf("Digite o segundo indice: ");
    scanf("%d", &b);
    if(b < a) { int aux = a; a = b; b = aux; }
    lista = (llint *) malloc((b+1)*sizeof(llint));
    for(int i = 0; i <= b; i++)
        lista[i] = 0;
    golomb(b, lista);
    printf("primeiro: %lld\túltimo: %lld\tmédia: %lg\n", lista[a], lista[b], media(lista, a, b));
    free(lista);
    return 0;
}

llint golomb(int n, llint * lista){
    if(lista[n] != 0)
        return  lista[n];
    if(n == 0)
        lista[n] = 1;
    else
        lista[n] = 1 + golomb(n - golomb(golomb(n - 1, lista) - 1, lista), lista);
    return lista[n];
}

double media(llint * v, llint inicio, llint final) {
    llint m = 0;
    for(int i = inicio; i <= final; i++)
        m += v[i];
    return ((double) m)/(final - inicio + 1);
}
