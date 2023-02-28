#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct noArv {
    int info;
    struct noArv* esq;
    struct noArv* dir;
}NoArv;




NoArv* criaArvoere(int c, NoArv* e, NoArv* d){
    NoArv* p = (NoArv*)malloc(sizeof(NoArv));
    if(p==NULL) exit(1);
    p->info = c;
    p->esq = e;
    p->dir = d;
    return p;
}

NoArv* criaArvoreVazia(void){
    return NULL;
}


int arvoreEstaVazia(NoArv* a){
    return a == NULL;
}


void percorreArvoreEmNivel(NoArv* a){
    if (!arvoreEstaVazia(a)){
        cout<<"<" <<a->info;
        percorreArvoreEmNivel(a->esq);
        percorreArvoreEmNivel(a->dir);
    cout<<">";

    }
    else {
        cout<<"<>";
    }
}

int calculaAlturaArvore(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = calculaAlturaArvore(raiz->esq);
        int dir = calculaAlturaArvore(raiz->dir);
        if(esq > dir)
            return calculaAlturaArvore(raiz->esq) + 1;
        return dir + 1;
    }
}




int main(){
     NoArv *raiz = criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoere(3, criaArvoreVazia(), criaArvoreVazia())),
                            criaArvoere(3, 
                    criaArvoere(5, criaArvoreVazia(), criaArvoreVazia()), criaArvoere(6, criaArvoreVazia(), criaArvoere(6, criaArvoreVazia(), criaArvoreVazia()))));

   
    
    cout <<"altura: " << calculaAlturaArvore(raiz);
    return 0;
}