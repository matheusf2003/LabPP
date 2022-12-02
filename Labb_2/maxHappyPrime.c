/*
 * Arquivo: maxHappyPrime.c
 * Data criação: 26/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>


int casaDec(int n);
int happyPrime(int n);
int power(int n1,int n2);

int main (void) {
    int n, total;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    total = happyPrime(n);
    printf("%d", total);
    return 0;
}

int casaDec(int n){
    int count = 0;
    for(int i=1; 1;i *= 10, count++){
        if(n/i == 0)
            return count;
    }
}

int happyPrime(int n){
    int total = 0, casde = casaDec(n);
    for(int i = casde; i>0;i--){
        total += power(n / (power(10,i)), 2);
    }
    return total;
}

int power(int n1,int n2){
    int pow = 1;
    for(int i =0; i<n2; i++)
        pow *= n1;
    return pow;
}