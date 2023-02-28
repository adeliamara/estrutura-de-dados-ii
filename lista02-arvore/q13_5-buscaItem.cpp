

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





int contaRepeticoesItem(NoArv *raiz, int Item){
   
    if (!arvoreEstaVazia(raiz)){
        if(raiz->info == Item){
            return 1;
        }else{
            return 0 + contaRepeticoesItem(raiz->esq,Item) + contaRepeticoesItem(raiz->dir,Item);
        }
       
    }else{
        return 0;
    }
  
     

}


int main(){
     NoArv *raiz = criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoere(3, criaArvoreVazia(), criaArvoreVazia())),
                            criaArvoere(3, 
                    criaArvoere(5, criaArvoreVazia(), criaArvoreVazia()), criaArvoere(6, criaArvoreVazia(), criaArvoere(6, criaArvoreVazia(), criaArvoreVazia()))));

    if(contaRepeticoesItem(raiz,9)){
        cout << "Item está na arvore" << endl;
    }else{
        cout << "Item não está na arvore" << endl;
    }
    
    return 0;
}