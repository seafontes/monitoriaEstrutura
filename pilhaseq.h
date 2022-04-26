
/*
FUNCOES BASE PARA PROGRAMAS DE PILHA SEQUENCIAL
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct tpilha{
    int topo;
    int pilha[TAM];
}tpilha;

//inicializar
void inicializa(tpilha *p){
p->topo =-1;
}

//checar pilha vazia
int pilhavazia(tpilha *p){
    if(p->topo == -1)
        return 1;
    return 0;
}

//checar pilha cheia
int pilhacheia(tpilha *p){
    if(p->topo == TAM-1)
        return 1;
    return 0;
}

//empilhamento
int empilha(tpilha *p, int valor){
    if(pilhacheia(p))
        //pilha cheia não dá pra encher mais
        return(0);
    p->topo++; //define novo topo
    p->pilha[p->topo] = valor; //adiciona no topo
    return 1;
}

int desempilha(tpilha *p, int *elemento){
    if(pilhavazia(p))
        //pilha vazia náo dá pra tirar nada
        return 0;
    *elemento = p->pilha[p->topo]; // o lugar pra onde o vetor elemento aponta agora tem o valor desempilhado
    p->topo--; //decresce o topo
    return 1;
}
