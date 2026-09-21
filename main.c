#include <stdio.h>
#include <stdlib.h>
#include "fitxer.h"

int max(int a,int b){
    if(a>=b){
        return a;
    }
    else return b;
}
int min(int a,int b){
    if(a>=b){
        return b;
    }
    else return a;
}
int calculaNumFills(char tauler[N][N]){
    if(condGuanyar(tauler,0)==1 || condGuanyar(tauler,1)==1){
        return 0;
    }
    else{
        int n=N;
        for(int i=0;i<N;i++){
        if(tauler[0][i]!=0){
            n--;
        }
    }
    return n;
    }
}

void copiaTauler(char tauler[N][N], char taulerc[N][N]){
    for(int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            taulerc[i][j]=tauler[i][j];
        }
    }
}
int calculValor(Node *arrel){
    int valor=0;
    if(arrel->n_fills!=0){
        return 0;
    }
    else{
    if (condGuanyar(arrel->tauler, 0)) {
        return 9999-(arrel->nivell+1);
    }
    if (condGuanyar(arrel->tauler, 1)) {
        return -9999+(arrel->nivell+1);
    }
    for(int i=0;i<N;i++){
        valor+=2*horitzontal(arrel->tauler,i,0,2);
        valor-=2*horitzontal(arrel->tauler,i,1,2);
        valor+=2*vertical(arrel->tauler,i,0,2);
        valor-=2*vertical(arrel->tauler,i,1,2);
        valor+=4*horitzontal(arrel->tauler,i,0,3);
        valor-=4*horitzontal(arrel->tauler,i,1,3);
        valor+=4*vertical(arrel->tauler,i,0,3);
        valor-=4*vertical(arrel->tauler,i,1,3);
    }
    valor+=2*diagonalamunt(arrel->tauler,0,2);
    valor-=2*diagonalamunt(arrel->tauler,1,2);
    valor+=4*diagonalamunt(arrel->tauler,0,3);
    valor-=4*diagonalamunt(arrel->tauler,1,3);
    if(N%2==0){
        for(int i=0; i<N/2;i++){
            for(int j=0;j<N;j++){
                if(arrel->tauler[j][i]==1){
                    valor-=i;
                }
                if(arrel->tauler[j][i]==2){
                    valor+=i;
                }
            }
        }
        for(int i=N/2; i<N;i++){
            for(int j=0;j<N;j++){
                if(arrel->tauler[j][i]==1){
                    valor-=N-i;
                }
                if(arrel->tauler[j][i]==2){
                    valor+=N-i;
                }
            }
        }
    }
    if(N%2==1){
        for(int i=0; i<(N-1)/2;i++){
            for(int j=0;j<N;j++){
                if(arrel->tauler[j][i]==1){
                    valor-=i;
                }
                if(arrel->tauler[j][i]==2){
                    valor+=i;
                }
            }
        }
        for(int i=(N+1)/2; i<N;i++){
            for(int j=0;j<N;j++){
                if(arrel->tauler[j][i]==1){
                    valor-=N-i;
                }
                if(arrel->tauler[j][i]==2){
                    valor+=N-i;
                }
            }
        }
        for(int j=0;j<N;j++){
            if(arrel->tauler[j][(N-1)/2+1]==1){
                valor-=(N-1)/2+1;
            }
            if(arrel->tauler[j][(N-1)/2+1]==2){
                valor+=(N-1)/2+1;
            }
        }
    }
    return valor;}
}
Node* creaNode(Node *pare,int numDeFill, int nivell,int dificultat) {
	Node *p=malloc(sizeof(Node));
	copiaTauler(pare->tauler,p->tauler);    //Comentat per poder fer funcionar l'arbre
	gravetat(p->tauler, numDeFill+1, nivell%2);
	//imprimirTauler(p->tauler);
	p->nivell=nivell;
	p->columna=numDeFill;
	p->valor=calculValor(p);//Posat aqui per poder fer funcionar l'arbre
	if (nivell<2*dificultat) {
		p->n_fills=calculaNumFills(p->tauler);
		p->fills=malloc( p->n_fills * sizeof(Node*));
	}
	else {
		p->n_fills=0;
		p->fills=NULL;
	}
	return p;
}
void creaNivell(Node *pare,int nivell,int dificultat) {
    int llista[N];
    int aux=0;
    for(int i=0;i<N;i++){
        if(pare->tauler[0][i]==0){
            llista[aux]=i;
            aux++;
        }
    }
	for(int i=0 ; i<pare->n_fills ; i++) {
            pare->fills[i] = creaNode(pare,llista[i],nivell,dificultat);
	}
}
void crearArbre(Node *arrel, int nivell, int dificultat) {
    int aux=nivell+1;   //Posat aqui per poder fer funcionar l'arbre
	creaNivell(arrel,aux,dificultat);  //crea 1 nivell a partir d'aquest pare
	for(int i=0 ; i<arrel->n_fills ; i++) {
        crearArbre(arrel->fills[i],nivell+1,dificultat);
	}
}
void recorreArbreRec(Node *arrel,int nivell,int comptador) {
    for(int i=0 ; i<arrel->n_fills ; i++) {
        recorreArbreRec(arrel->fills[i],nivell+1,++comptador);
    }
    if(arrel->fills!=NULL){
        free(arrel->fills);
    }
    free(arrel);
}
int minimax(Node *arrel,int nivell){
    if (arrel->n_fills == 0) {
        return arrel->valor;
    }
    int a;
    if(nivell%2==0){
        a=-99999;
        for(int i=0;i<arrel->n_fills;i++){
            int b=minimax(arrel->fills[i],nivell+1);
            a=max(a,b);
        }
    }
    if(nivell%2==1){
        a=99999;
        for(int i=0;i<arrel->n_fills;i++){
            int b=minimax(arrel->fills[i],nivell+1);
            a=min(a,b);
        }
    }
    arrel->valor=a;
    return arrel->valor;
}
int triarTiradaOrdinador(Node *arrel,char tauler[N][N],int dificultat){
    copiaTauler(tauler,arrel->tauler);
	arrel->nivell=0;
	arrel->n_fills=calculaNumFills(arrel->tauler);
	arrel->fills=malloc( arrel->n_fills * sizeof(Node*));
	arrel->valor=0;
	crearArbre(arrel, arrel->nivell,dificultat);
	minimax(arrel,arrel->nivell);
    for(int i=0;i<arrel->n_fills;i++){
        if(arrel->valor==arrel->fills[i]->valor){
            printf("He tirat a la columna %i\n",arrel->fills[i]->columna+1);
            return arrel->fills[i]->columna;
        }
    }
}
