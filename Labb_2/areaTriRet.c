/*
 * Arquivo: areaTriRet.c
 * Data criação: 24/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main (void) {
    float xa, ya, xb, yb, b, h, a;

    printf("Coordenandas pontos A e B: ");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);
    b = xa - xb;
    h = yb - ya;
    a = b*h/2;
    if(a<0)
        a *= -1;
    printf("%g\n", a);
    return 0;
}