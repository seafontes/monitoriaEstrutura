/*
FUNCOES BASE PARA PROGRAMAS DE LISTA CIRCULAR COM NÓ BOBO
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct tfilac{
    int ini;
    int fim;
    int cont;
    int fila[TAM];
}tfilac;

void inicializa(tfilac *pf){
    pf->ini=0;
    pf->fim=-1;
    pf->cont=0;
}

int filavazia(tfilac *pf){
    if(pf->cont==0)
        return 1;
    return 0;
}

int filacheia(tfilac *pf){
    if(pf->cont==TAM)
        return 1;
    return 0;
}

int inserir(tfilac *pf, int valor){
    if(filacheia(pf))
        return 0;
    pf->cont++;
    pf->fim = (pf->fim==TAM-1)?:pf->fim+1;
    pf->fila[pf->fim]=valor;
    return(1);
}

int remove(tfilac *pf, int *elem){
    if(filavazia(pf))
        return 0;
    pf->cont--;
    *elem = pf->fila[pf->ini];
    pf->ini = (pf->ini==TAM-1)?0:pf->ini+1;
    return 0;
}