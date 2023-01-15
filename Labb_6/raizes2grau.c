/*
 * Arquivo: raizes2grau.c
 * Data criação: 14/jan/23
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float * x1, float * x2);
float delta(float a, float b, float c);
float x(float a, float b, float c, float D, int sinal);

int main(void){
    int r;
    float a, b, c;
    float x1[1];
    float x2[1];
    printf("Digite a b c:\n");
    scanf("%f %f %f%*c", &a, &b, &c);
    r = raizes(a, b, c, x1, x2);
    switch (r){
    case 0:
        printf("nº raízes: %d\n", r);
        break;
    case 1:
        printf("nº raízes: %d\nx1: %g\n", r, x1[0]);
        break;
    case 2:
        printf("nº raízes: %d\nx1: %g\t\tx2: %g\n", r, x1[0], x2[0]);
        break;
    default:
        break;
    }
    return 0;
}

int raizes(float a, float b, float c, float * x1, float * x2){
    float D = delta(a, b, c);
    if(D < 0)
        return 0;
    else if(D == 0){
        x1[0] = x(a, b, c, D, 1);
        return 1;
    } else {
        x1[0] = x(a, b, c, D, 1);
        x2[0] = x(a, b, c, D, -1);
        if(x1[0] > x2[0]){
            float aux = x1[0];
            x1[0] = x2[0];
            x2[0] = aux;
        }
        return 2;
    }
}

float delta(float a, float b, float c){
    return b * b - 4 * a * c;
}

float x(float a, float b, float c, float D, int sinal){
    return (b * (-1) + sinal * sqrt(D))/ (2 * a);
}
