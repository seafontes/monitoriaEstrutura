/*
FUNCOES BASE PARA PROGRAMAS DE LISTA CIRCULAR COM NÓ BOBO
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/

#include <stdio.h>
#include <stdlib.h>s
#define TAM 100

typedef struct tfila{
    int F,R;
    int fila[TAM];
}tfila;
//inicializa a fila
void inicializa(tfila *pf){
    pf->R=0;
    pf->F=0;
}
//teste vazio
int filavazia(tfila *pf){
    if(pf->F==pf->R)
        return 1;
    return 0;
}
//teste cheia
int filacheia(tfila *pf){
    if((pf->R+1)%TAM == pf->F)
        return(1);
    return 0;
}
//inserir no nó bobo
int inserirfila(tfila *pf, int valor){
    if(filacheia(pf))
        return 0;
    pf->R = (pf->R+1)%TAM;
    pf->fila[pf->R]=valor;
    return 1;
}
//remover no nó bobo
int removefila(tfila *pf, int *elem){
    if(filavazia(pf))
        return 0;
    pf->F = (pf->F+1)%TAM;
    *elem = pf->fila[pf->F];
    return 1;
}