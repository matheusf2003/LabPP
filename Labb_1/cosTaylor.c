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


int fat(int n){
  if (n == 0)
    return 1;
  else
    return n * fat(n-1);
}

double potencia(double a, int b){
  if (b == 0)
    return 1;
  else
    return a * potencia(a, b-1);
}

double cosseno(int n, double x) {
  double c = 0.0;
  for(int i = 0; i <= n; i++){
    c = c + potencia(-1, i)*(potencia(x, 2*i)/(fat(2*i)));
  }
  return c;
}

int main(void) {
  int n;
  double x;
  printf("Digite n: ");
  scanf("%d", &n);
  printf("Digite x: ");
  scanf("%lf", &x);
  printf("%.5lf\n", cosseno(n, x * M_PI));
}
