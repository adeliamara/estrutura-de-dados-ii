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


bool areTwoTreesEqual(NoArv* a, NoArv* b){
	if (arvoreEstaVazia(a) && arvoreEstaVazia(b)){
		return true;
	} else if(arvoreEstaVazia(a) ^ arvoreEstaVazia(b) ){
		return false;
	}

	if(a->info != b->info){
		return false;
	}
	
	return areTwoTreesEqual(a->esq, b->esq) && areTwoTreesEqual(a->dir, b->dir);
	
}




int main(){
     NoArv *raizA = criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoere(3, criaArvoreVazia(), criaArvoreVazia())),
                            criaArvoere(4, 
                    criaArvoere(6, criaArvoreVazia(), criaArvoreVazia()), criaArvoere(6, criaArvoreVazia(), criaArvoreVazia())));

      NoArv *raizB= criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoere(3, criaArvoreVazia(), criaArvoreVazia())),
                            criaArvoere(4, 
                    criaArvoere(6, criaArvoreVazia(), criaArvoreVazia()), criaArvoere(6, criaArvoreVazia(), criaArvoreVazia())));
    
    if(areTwoTreesEqual(raizA, raizB)){
    	cout << "sao iguais";
    }else {
    	cout << "sao diferentes";
    }
    
    return 0;
}
