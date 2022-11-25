/*
 * Arquivo: dist.c
 * Data criação: 24/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <math.h>

double dis_euclidiana(float Ax,float Ay,float Bx,float By);

int main(void) {
    float Ax = 0, Ay = 0, Bx = 0, By = 0;
    double dist = 0;
    printf("Coordenadas do ponto A: ");
    scanf("%f %f", &Ax, &Ay);
    printf("Coordenadas do ponto B: ");
    scanf("%f %f", &Bx, &By);
    dist = dis_euclidiana(Ax, Ay, Bx, By);
    printf("%g\n", dist);
    return 0;

}

double dis_euclidiana(float Ax,float Ay,float Bx,float By) {
    return sqrt(pow((Ax-Bx), 2) + pow((Ay-By), 2));
}