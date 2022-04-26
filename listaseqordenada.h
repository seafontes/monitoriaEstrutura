/*
FUNCOES BASE PARA PROGRAMAS DE LISTA SEQUENCIAL ORDENADA
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

//comeca bem padrao, as funcoes de inicializar, testes e percurso sao as mesmas
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
//agora comecam as diferenciadas
int buscaSeq(tlista *pl, int elem, int *pos){
    int i;
    for(i=0;(i<pl->qtnos)&&(elem>pl->lista[i].chave);i++);//itera ate o fim ou ate encontrar um elemento maior
    *pos = i;
    if((i==pl->qtnos)||(elem!=pl->lista[i].chave))//testa se achou
        return 0;
    return 1;
}
//busca binaria foda
int buscaBin(tlista *pl, int elem){
    int ini=0;
    int fim=pl->qtnos-1;
    int meio;
    while(ini<=fim){
        meio=(ini+fim)/2;
        if(elem==pl->lista[meio].chave)
            return(meio);
        if(elem>pl->lista[meio].chave)
            ini = meio+1;
        else
            fim = meio-1;
    }
    return(-1);
}
//inserir tbm muda, e eh ordenada tbm
int insereOrd(tlista *pl, int valor){
    int i, pos;
    if(listaCheia(pl))
        return 0;
    if(buscaSeq(pl, valor, &pos))
        return -1;
    for(i=pl->qtnos;i>pos;i--)
        pl->lista[i].chave=pl->lista[i-1].chave; //chega os negocios pro lado
    pl->lista[pos].chave=valor;// coloca no lugar que sobrou
    pl->qtnos++;
    return 1;
}
//pra remover é
int removeOrd(tlista *pl, int valor){
    int i, pos;
    if(listaVazia(pl))
        return 0;
    if(!buscaSeq(pl, valor, &pos))
        return -1;
    for(i=pos; i<pl->qtnos;i++)
        pl->lista[i].chave = pl->lista[i+1].chave;
    pl->qtnos--;
    return 1;
}
