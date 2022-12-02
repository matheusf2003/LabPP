/*
 * Arquivo: maxHappyPrime.c
 * Data criação: 26/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <math.h>


int casaDec(int n);
int happyPrime(int n);
int primo(int n);
int verifica(int n);

int main (void) {
    int n, maxhappyprime;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    maxhappyprime = verifica(n);
    printf("%d", maxhappyprime);
    if(maxhappyprime == 0)
        printf("***");
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
    int total = 0, casde = casaDec(n), n2;
    for(int i = casde; i>0; i--){
        n2 = n/ (int)(pow(10,i-1)+0.5);
        total += (int)(pow(n2, 2)+0.5);
        n -= n2 * (int)(pow(10,i-1)+0.5);
    }
    if((total>1) && (total != 4))
        return happyPrime(total);
    else if(total == 1)
        return 1;
    else
        return 0;
}

int primo(int n){
    if(n==1)
        return 0;
    if(n % 2 == 0 && n != 2)
        return 0;
    for(int i = 2; i < n / 2; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int verifica(int n){
    for(int i=n; i>0; i--)
        if(primo(i) && happyPrime(i))
            return i;
    return 0;
}