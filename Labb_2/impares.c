/*
 * Arquivo: impares.c
 * Data criação: 24/nov/22
 * Autor: Matheus Melo
*/

#include <stdio.h>

int main(void) {
    int n1, n2, n3;
    scanf("%d %d", &n1, &n2);
    if (n2 % 2 ==0)
        n3 = n2-1;
    else
        n3 = n2;
    for(int i=n1; i <= n3; i++){
        if(i % 2 != 0){
            printf("%d", i);
            if(i != n3)
                printf(", ");
            else
                printf("\n");
        }
    }
    return 0;
}