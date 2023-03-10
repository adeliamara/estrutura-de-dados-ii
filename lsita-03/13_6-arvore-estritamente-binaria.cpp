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


bool verificaArvoreEstritamenteBinaria(NoArv *raiz){
    if(arvoreEstaVazia(raiz)){
         return true;
    }else if(arvoreEstaVazia(raiz->esq)  ^ arvoreEstaVazia(raiz->dir)){
        return false;
    }
    else {
       return verificaArvoreEstritamenteBinaria(raiz->esq) && verificaArvoreEstritamenteBinaria(raiz->dir);

    }
}




int main(){
     NoArv *raizNaoEstritamenteBinaria = criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoere(3, criaArvoreVazia(), criaArvoreVazia())),
                            criaArvoere(3, 
                    criaArvoere(5, criaArvoreVazia(), criaArvoreVazia()), criaArvoere(6, criaArvoreVazia(), criaArvoere(6, criaArvoreVazia(), criaArvoreVazia()))));
                    
     NoArv *raizEstritamenteBinaria = criaArvoere(1,
            criaArvoere(2,   criaArvoreVazia(), criaArvoreVazia()),  criaArvoere(2,   criaArvoreVazia(), criaArvoreVazia()));

 
    
    bool ehEstritamenteBinaria = verificaArvoreEstritamenteBinaria(raizEstritamenteBinaria);
    
    if(ehEstritamenteBinaria){
    	cout << "eh estritamente binaria!";
	}else{
		cout << "N]ao eh estritamente binaria!";

	}
 
    return 0;
}
