#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <cmath>

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

int contaNos(NoArv *raiz){
    if(arvoreEstaVazia(raiz))
        return 0;
    else
        return 1 + contaNos(raiz->esq) + contaNos(raiz->dir);

}

int calculaAlturaArvore(NoArv *raiz){
    if(raiz == NULL){
        return 0;
    }
    else{
        int esq = calculaAlturaArvore(raiz->esq);
        int dir = calculaAlturaArvore(raiz->dir);
        if(esq > dir)
            return calculaAlturaArvore(raiz->esq) + 1;
        return dir + 1;
    }
}


bool isFullTree(NoArv* root) {
    return contaNos(root) == pow(2,calculaAlturaArvore(root)) -1;
}



int main(){
     NoArv *arvoreCheia = criaArvoere(1,
            criaArvoere(2,  
criaArvoreVazia(), criaArvoreVazia()),
                            criaArvoere(4, criaArvoreVazia(), criaArvoreVazia()));
	NoArv *arvoreNaoCheia = criaArvoere(1,
criaArvoere(2,
criaArvoere(4, criaArvoreVazia(), criaArvoreVazia()),
criaArvoreVazia()),
criaArvoere(3,
criaArvoreVazia(),
criaArvoere(7, criaArvoreVazia(), criaArvoreVazia())));


    if(isFullTree(arvoreCheia)){
    	cout << "eh cheia";
    }else {
    	cout << "nao eh cheia";
    }
    
    if(isFullTree(arvoreNaoCheia)){
    	cout << "eh cheia";
    }else {
    	cout << "nao eh cheia";
    }
    
    
    return 0;
}

