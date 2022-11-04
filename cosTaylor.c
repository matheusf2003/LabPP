/*
 * Arquivo: cosTaylor.c
 * Data criação: 03/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

#ifdef M_PI

  #undef M_PI

#endif

#define M_PI 3.141592653589793115997963468544185161590576171875


int main() {
  int n;
  double x;
  printf("%f", cos(n, x, M_PI));
}

int fat(int n){
    if (n == 0)
        return 1;
    else
        return n * fat(n-1);
}

int potencia(int a, int b){
  if (b == 0)
    return 1;
  else
    return a * potencia(a, b-1);
}

float cos(int n, double x, double pi) {
  float c = 0.0;
  for(int i; i <= n; i++){
    c = c + potencia(-1, i)*(potencia(x*pi, 2*i)/(fat(2*i)));
  }
  return c;
}