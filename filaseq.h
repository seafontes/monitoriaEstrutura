/*
FUNCOES BASE PARA PROGRAMAS DE PILHA SEQUENCIAL
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct tfila{
    int F,R;
    int fila[TAM];
}tfila;

//inicializar fila
void inicializa(tfila *pf){
    pf->F=0;
    pf->R=-1;
}
//verificar fila vazia
int filavazia(tfila *pf){
    if(pf->F>pf->R)
        return 1;
    return 0;
}
//verificar fila cheia
int filacheia(tfila *pf){
    if(pf->R==TAM)
        return 1;
    return 0;
}
//inserir na fila
int inserir_fila(tfila *pf, int valor){
    if(filacheia(pf))
        return 0;
    pf->R++;
    pf->fila[pf->R]=valor;
    return 1;
}
//int remover da fila
int remover_fila(tfila *pf, int *elem){
    if(filavazia(pf))
        return 0;
    *elem = pf->fila[pf->F];
    pf->F++;
    return 1;
}