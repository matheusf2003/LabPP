/*
 * Arquivo: cadastro.c
 * Data criação: 07/jan/22
 * Autor: Matheus Melo
*/

#include <stdio.h>
#include <stdlib.h>
#define N 256


typedef struct Nome {
    char nome[N], snome[N];
}Nome;

typedef struct Aniv {
    int dia, mes, ano;
}Aniv;

typedef struct Altu{
    int m, cm;
}Altu;

typedef struct Peso{
    int kg, g;
}Peso;


typedef struct Cadastro {
    Nome nome;
    Aniv aniv;
    Altu altu;
    Peso peso;
}Cadastro;

typedef
    struct Node {
        Cadastro pessoa;
        struct Node * next;
    }
Node;

typedef struct Lista {
    Cadastro pessoa;
}Lista;


const char strmes[13][4] = {
    "", "JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
    "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"
};

void getstr(char * str, int nchar);
long long int len(char * str);
int cm(int x);
Cadastro cadastrar(char * str, int nchar);
Cadastro transforma(Cadastro pessoa, char * DATA, char * ALTU, char * PESO);
void Node_print(Lista * lista, int tamlis);


int main(void){
    Cadastro pessoa;
    int n;
    scanf("%d%*c", &n);
    Lista lista[n];
    for(int i = 0; i < n; i++){
        char str[N];
        getstr(str, N);
        lista[i].pessoa = cadastrar(str, len(str));
    }
    Node_print(lista, n);
    //printf("%s %s; %02d%s%04d; %dm%d; %d.%dkg", pessoa.nome.nome, pessoa.nome.snome, pessoa.aniv.dia,
    //strmes[pessoa.aniv.mes], pessoa.aniv.ano, pessoa.altu.m, cm(pessoa.altu.cm), pessoa.peso.kg, pessoa.peso.g);
    return 0;
}

Cadastro cadastrar(char * str, int nchar){
    Cadastro pessoa;
    char data[11], altu[5], peso[10];
    for(int i = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0; i < nchar; i++){
        if(str[i] != ' ' && str[i] != '\0'){
            switch (i2)
            {
            case 0:  //NOME
                pessoa.nome.nome[i] = str[i];
                pessoa.nome.nome[i+1] = '\0';
                break;
            case 1:  //SOBRENOME
                pessoa.nome.snome[i3++] = str[i];
                pessoa.nome.snome[i3] = '\0';
                break;
            case 2:  //DATA
                data[i4++] = str[i];
                data[i4] = '\0';
                break;
            case 3:  //ALTURA
                if(i5 < 4){
                    altu[i5++] = str[i];
                    altu[i5] = '\0';
                } break;
            case 4:  //PESO
                peso[i6++] = str[i];
                peso[i6] = '\0';
                break;
            default:
                break;
            }
        } else
            i2++;
    }
    return transforma(pessoa, data, altu, peso);

}

Cadastro transforma(Cadastro pessoa, char * DATA, char * ALTU, char * PESO){
    pessoa.aniv.dia = 0, pessoa.aniv.mes = 0, pessoa.aniv.ano = 0;
    pessoa.altu.m = 0, pessoa.altu.cm = 0;
    pessoa.peso.kg = 0, pessoa.peso.g = 0;
    for(int i = 0, i2 = 0; i < len(DATA); i++){
        if(DATA[i] != '/'){
            switch (i2)
            {
            case 0:  //DIA
                pessoa.aniv.dia *= 10;
                pessoa.aniv.dia += (DATA[i] - '0');
                break;
            case 1:  //MES
                pessoa.aniv.mes *= 10;
                pessoa.aniv.mes += (DATA[i] - '0');
                break;
            case 2:  //ANO
                pessoa.aniv.ano *= 10;
                pessoa.aniv.ano += (DATA[i] - '0');
                break;
            default:
                break;
            }
        } else
            i2++;
    } for(int i = 0, i2 = 0; i < len(ALTU); i++) {
        if(ALTU[i] != '.'){
            switch (i2)
            {
            case 0:  //METROS
                pessoa.altu.m *= 10;
                pessoa.altu.m += (ALTU[i] - '0');
                break;
            case 1:  //CENTIMETROS
                pessoa.altu.cm *= 10;
                pessoa.altu.cm += (ALTU[i] - '0');
                break;
            default:
                break;
            }
        } else
            i2++;
    } for(int i = 0, i2 = 0; i < len(PESO); i++) {
        if(PESO[i] != '.'){
            switch (i2)
            {
            case 0:  //QUILOS
                pessoa.peso.kg *= 10;
                pessoa.peso.kg += (PESO[i] - '0');
                break;
            case 1:  //GRAMAS
                pessoa.peso.g *= 10;
                pessoa.peso.g += (PESO[i] - '0');
                break;
            default:
                break;
            }
        } else
            i2++;
    }
    return pessoa;    
}

void getstr(char * str, int nchar) {
    char c;  int i;
    for(i = 0; i < nchar; i++) {
        c = getchar();
        if(c != '\n') {
            str[i] = c;
        } else {
            str[i] = '\0';
            break;
        }
    }
    if(i == nchar) {
        str[nchar-1] = '\0';
        // limpar buffer teclado
        while ((c = getchar()) != '\n' && c != EOF);
    } 
}

long long int len(char * str) {
    long long int l = 0;
    while(str[l]) l++;
    return l;
}

int cm(int x) {
    if(x < 10)
        return x*10;
    if(x > 99)
        return cm(x/10);
    return x;
}

void Node_print(Lista * lista, int tamlis) {
    for(int i = 0; i < tamlis; i++){
        printf("%s %s; %02d%s%04d; %dm%d; %d.%dkg", lista[i].pessoa.nome.nome, lista[i].pessoa.nome.snome, lista[i].pessoa.aniv.dia,
        strmes[lista[i].pessoa.aniv.mes], lista[i].pessoa.aniv.ano, lista[i].pessoa.altu.m, cm(lista[i].pessoa.altu.cm), lista[i].pessoa.peso.kg, lista[i].pessoa.peso.g);
        printf("\n");
    }
}
