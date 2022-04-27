/*
FUNCOES BASE PARA PROGRAMAS DE LISTA SIMPLESMENTE ENCADEADA
MONITORIA DE ESTRUTURA DE DADOS 22.1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}lista;
//criar a lista
lista *criaLista(int n){
    lista *ini, *ult, *p;
    int i, valor;
    ini = ult = NULL;
    for(i=0; i<n;i++){
        scanf("%d", &valor);
        p=(lista *)malloc(sizeof(lista));
        p->info = valor;
        p->prox=NULL;
        if(ult)
            ult->prox=p;
        else
            ini=p;
        ult = p;
    }
    return(ini);
}
//remover o 1o no
lista *removePrimeiro(lista *p){
    lista *q;
    if(!p)
        return(NULL);
    if(!p->prox){
        free(p);
        return(NULL);
    }
    q = p->prox;
    free(p);
    return(q);
}
//imprimir
void imprimirLista(lista *p){
    while (p){
        printf("%d\t",p->info);
        p=p->prox;
    }
}
//contar os nos
int contaNo(lista *p){
    int i=0;
    while(p){
        i++;
        p=p->prox;
    }
    return(i);
}
//remover o ultimo
lista *removeUltimo(lista *p){
    lista *q, *t;
    if(!p)
        return(NULL);
    if(!p->prox){
        free(p);
        return(NULL;
    }
    else{
        q=p;
        while(q->prox){
            t=q;
            q=q->prox;
        }
        t->prox=NULL; //essa ultima parte tá meio estranha na minha cabeca, talvez de errado, mas a logica é essa msm
        free(q);
        return(p);
    }
}
//inserir apos 1o no
lista *insereApos(lista *p, int valor){
    lista *q, *t;
    q = (lista *)malloc(sizeof(lista));
    q->info = valor;
    if(!p->prox){
        q->prox = p->prox;
        p->prox=q;
        return(p);
    }
    else{
        q->prox=p->prox;
        p->prox=q;
    }
    return(p);
}
//juntar duas listas, coloca uma no final da outra
lista *concatena(lsita *x, lista *y){
    lista *l;
    if(!x)
        return(y);
    l=x;
    while(l->prox)
        l=l->prox;
    l->prox=y;
    return(x);
}
//remover o k-esimo
lista *removeK(lista *p. int k){
    lista *q, *t;
    int cont;
    if(k==1){
        if(!p->prox){
            free(p);
            return(NULL)
        }
        else{
            q=p->prox;
            free(p);
            return(q);
        }
    }
    else{
        cont=1;
        q=p;
        while(cont!=k){
            t=q;
            q=q->prox;
            cont++;
        }
        t->prox = q->prox;
        free(q);
        return(p);
    }
}
//inserir no final
lista *inserirFim(lista *p, int valor){
    lista *q, *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->info=valor;
    novo->prox=NULL;
    if(!p)
        return(novo);
    q=p;
    while(q->prox){
        q=q->prox;
    }
    q->prox=novo;
    return(p);
}