/*
FUNCOES BASE PARA PROGRAMAS DE LISTA SEQUENCIAL
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

//comeca bem padrao
typedef struct tno{
    int chave;
}tno;

typedef struct tlista{
    int qtnos;
    int tno lista[TAM];
}tlista;

void inicializa(tlista *pl){
    pl->qtnos=0;
}

int listaVazia(tlista *pl){
    if(pl->qtnos==0)
        return 1;
    return 0;
}

int listaCheia(tlista *pl){
    if(pl->qtnos==TAM)
        return 1;
    return 0;
}

//impressao da lista
void imprime(tlista *pl){
    int i;
    for(i=0;i<pl->qtnos;i++)
        printf("%d\t", pl->lista[i].chave);
}
//aqui comeca a diferenciar das anteriores
//busca sequencial
int buscaSeq(tlista *pl, int valor){
    int i;
    for(i=0; i<pl->qtnos;i++)
        if(valor==pl->lista[i].chave)
            return i; //retorna a posicao da chave pesquisada
    return(-1); //nao achou, retorna -1
}
//inserir com repeticao
int inserirRep(tlista *pl, int valor){
    if(listaCheia(pl))
        return(0);
    pl->lista[pl->qtnos++].chave=valor;
    return 1;
}
//inserir sem repeticao
int inserirSemRep(tlista *pl, int valor){
    int i;
    if(listaCheia(pl))
        return -1; //se nao tiver espaco, nao insere
    i = buscaSeq(pl, valor);
    if(i>=0)
        return 0;//se ja houver um igual na lista, tbm nao insere
    pl->lista[pl->qtnos++].chave=valor;
    return 1;
}
//remocao
int remove(tlista *pl, int valor){
    int i;
    if(listaVazia(pl))
        return 0;
    i = buscaSeq(pl, valor);
    if(i<0)
        return -1;
    pl->lista[i].chave = pl->lista[--pl->qtnos].chave;
    return 1;
}
