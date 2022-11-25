/*
 * Arquivo: imc.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void){
    float peso, altura, imc;
    printf("Peso: ");
    scanf("%f", &peso);
    printf("Altura: ");
    scanf("%f", &altura);
    imc = peso / (altura*altura);
    printf("%.2f ", imc);
    if(imc<=16){
        printf("(Perigo de vida)\n");
    } else if(imc<=17) {
        printf("(Muito abaixo do peso\n)");
    } else if(imc<=18.5) {
        printf("(Abaixo do peso)\n");
    } else if(imc<=25) {
        printf("(Peso Normal)\n");
    } else if(imc<=30) {
        printf("(Acima do peso)\n");
    } else if(imc<=35) {
        printf("(Obesidade grau I)\n");
    } else if(imc<=40) {
        printf("(Obesidade grau II)\n");
    } else {
        printf("(Obesidade grau III)\n");
    }
}
