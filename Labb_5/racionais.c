/*
 * Arquivo: racionais.c
 * Data criação: 06/jan/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

typedef
    struct Racional
    {
        int numerador, denominador;
    }
Racional;

int mdc(int n1, int n2);
Racional simplifica(Racional n, int Mdc);

int main(void) {
    Racional n1, n2;
    printf("Primeiro número: ");
    scanf("%d %d", &n1.numerador, &n1.denominador);
    printf("Segundo número: ");
    scanf("%d %d", &n2.numerador, &n2.denominador);
    saida(simplifica(n1, mdc(n1.numerador, n1.denominador)), simplifica(n2, mdc(n2.numerador, n2.denominador)));
    //n1 = simplifica(n1, mdc(n1.numerador, n1.denominador));
    //n2 = simplifica(n2, mdc(n2.numerador, n2.denominador));
    //printf("\nnumerador = %d\ndenominador = %d", n1.numerador, n1.denominador);
    printf("%d/%d %d/%d %d/%d %d/%d %d/%d %d/%d", n1.numerador, n1.denominador, n2.numerador, n2.denominador);
    return 0;
}

Racional simplifica(Racional n, int Mdc){
    n.numerador /= Mdc;
    n.denominador /= Mdc;
    if(n.numerador == 0){
        n.denominador = 1;
    }else if(n.denominador < 0){
        n.numerador *= -1;
        n.denominador *= -1;
    }
    return n;
}

int mdc(int n1, int n2) {
    if(n2 == 0)
        return n1;
    return mdc(n2, n1 % n2);
}

Racional adição(Racional n1, Racional n2){
    Racional n;
    n.numerador = n1.numerador * n2.denominador + n2.numerador * n1.denominador;
    n.denominador = n1.denominador * n2.denominador;
    return simplifica(n, mdc(n.numerador, n.denominador));
}

Racional subtração(Racional n1, Racional n2){
    Racional n;
    n.numerador = n1.numerador * n2.denominador - n2.numerador * n1.denominador;
    n.denominador = n1.denominador * n2.denominador;
    return simplifica(n, mdc(n.numerador, n.denominador));
}

Racional multiplicação(Racional n1, Racional n2){
    Racional n;
    n.numerador = n1.numerador * n2.numerador;
    n.denominador = n2.denominador * n2.denominador;
    return simplifica(n, mdc(n.numerador, n.denominador));
}

Racional divisão(Racional n1, Racional n2){
    Racional n;
    n.numerador = n1.numerador * n2.denominador;
    n.denominador = n.denominador * n2.numerador;
    return simplifica(n, mdc(n.numerador, n.denominador));
}
