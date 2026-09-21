#include <stdio.h>
#include <stdlib.h>
#include "fitxer.h"

void posarZeros(char tauler[N][N]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        tauler[i][j]=0;
}
void imprimirTauler(char tauler[N][N]){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(tauler[i][j]==0){
                printf(" - ");
            }
            if(tauler[i][j]==1){
                printf(" X ");
            }
            if(tauler[i][j]==2){
                printf(" 0 ");
            }
        }
        printf("\n");
        printf("\n");
    }

}
void demanarTirada(char tauler[N][N],int contador,int *lloc,int modeDeJoc,int ordre){
    int aux=0;
    for(int i=0;i<N;i++){
        if(tauler[0][i]==0){
            printf(" %i ",i+1);
        }
        else printf("   ");
    }
    printf("\n");
    imprimirTauler(tauler);
    for(int i=0;i<N;i++){
        if(tauler[0][i]==0){
            printf(" %i ",i+1);
        }
        else printf("   ");
    }
    printf("\n");
    if(modeDeJoc==2){//persona
        if(contador==0){
            printf("Jugador 1 tria una columna entre l'1 i el %i\n",N);
        }
        if(contador==1){
            printf("Jugador 2 tria una columna entre l'1 i el %i\n",N);
        }
    }
    if(modeDeJoc==1 && ordre==1){//ordiandor començant persona
        if(contador==0){
        printf("Jugador tria una columna entre l'1 i el %i\n",N);
        }
    }
    if(modeDeJoc==1 && ordre==2){//ordinador començant ordinador
        if(contador==2){
        printf("Jugador tria una columna entre l'1 i el %i\n",N);
        }
    }
    do{
        aux=0;
        scanf("%i",lloc);
        if(*lloc>0 && *lloc<N+1 && tauler[0][*lloc-1]==0){
            aux=1;
        }
        else{
            printf("no es un valor correcte\n");
        }
    }while(aux==0);
}
void gravetat(char tauler[N][N],int lloc,int torn){
    int aux=0;
    for(int i=0;i<N;i++){
        if(tauler[i][lloc-1]!=0){
            aux++;
        }
    }
    if(torn==0){
        tauler[(N-1)-aux][lloc-1]=1;
    }
    if(torn==1){
        tauler[(N-1)-aux][lloc-1]=2;
    }
}
int horitzontal(char tauler[N][N],int fila,int torn,int punts){
    int cont=0;
    if(torn==0){
        for(int i=0;i<N;i++){
        if(tauler[fila][i]==2){
                cont++;
            if(cont==punts) return 1;
        }
        else cont=0;
        }
    }
    if(torn==1){
        for(int i=0;i<N;i++){
        if(tauler[fila][i]==1){
                cont++;
            if(cont==punts) return 1;
        }
        else cont=0;
        }
    }
    return 0;
}
int vertical(char tauler[N][N],int col,int torn,int punts){
    int cont=0;
    if(torn==0){
        for(int i=0;i<N;i++){
        if(tauler[i][col]==2){
                cont++;
            if(cont==punts) return 1;
        }
        else cont=0;
    }
    }
    if(torn==1){
        for(int i=0;i<N;i++){
        if(tauler[i][col]==1){
                cont++;
            if(cont==punts) return 1;
        }
        else cont=0;
    }
    }
    return 0;
}
int diagonalamunt(char tauler[N][N],int torn,int punts){
    if(punts==2){
        if(torn==0){
            for(int i=1;i<N;i++){
            for(int j=0;j<N-1;j++){
                    if(tauler[i][j]==2 && tauler[i-1][j+1]==2){
                    return 1;
                    }
                }
            }
        }
        if(torn==1){
            for(int i=1;i<N;i++){
            for(int j=0;j<N-1;j++){
                    if(tauler[i][j]==1 && tauler[i-1][j+1]==1){
                    return 1;
                    }
                }
            }
        }
    }
    if(punts==3){
        if(torn==0){
            for(int i=2;i<N;i++){
            for(int j=0;j<N-2;j++){
                    if(tauler[i][j]==2 && tauler[i-1][j+1]==2 && tauler[i-2][j+2]==2){
                    return 1;
                    }
                }
            }
        }
        if(torn==1){
            for(int i=2;i<N;i++){
            for(int j=0;j<N-2;j++){
                    if(tauler[i][j]==1 && tauler[i-1][j+1]==1 && tauler[i-2][j+2]==1){
                    return 1;
                    }
                }
            }
        }
    }
    if(punts==4){
        if(torn==0){
            for(int i=3;i<N;i++){
            for(int j=0;j<N-3;j++){
                    if(tauler[i][j]==2 && tauler[i-1][j+1]==2 && tauler[i-2][j+2]==2 && tauler[i-3][j+3]==2){
                    return 1;
                    }
                }
            }
        }
        if(torn==1){
            for(int i=3;i<N;i++){
            for(int j=0;j<N-3;j++){
                    if(tauler[i][j]==1 && tauler[i-1][j+1]==1 && tauler[i-2][j+2]==1 && tauler[i-3][j+3]==1){
                    return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int diagonalavall(char tauler[N][N],int torn,int punts){
    if(punts==2){
        if(torn==0){
            for(int i=0;i<N-1;i++){
                for(int j=0;j<N-1;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==2 && tauler[i+1][j+1]==2){
                        return 1;
                        }
                    }
                }
            }
        }
        if(torn==1){
            for(int i=0;i<N-1;i++){
                for(int j=0;j<N-1;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==1 && tauler[i+1][j+1]==1){
                        return 1;
                        }
                    }
                }
            }
        }
    }
    if(punts==3){
        if(torn==0){
            for(int i=0;i<N-2;i++){
                for(int j=0;j<N-2;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==2 && tauler[i+1][j+1]==2 && tauler[i+2][j+2]==2){
                        return 1;
                        }
                    }
                }
            }
        }
        if(torn==1){
            for(int i=0;i<N-2;i++){
                for(int j=0;j<N-2;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==1 && tauler[i+1][j+1]==1 && tauler[i+2][j+2]==1){
                        return 1;
                        }
                    }
                }
            }
        }
    }
    if(punts==4){
        if(torn==0){
            for(int i=0;i<N-3;i++){
                for(int j=0;j<N-3;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==2 && tauler[i+1][j+1]==2 && tauler[i+2][j+2]==2 && tauler[i+3][j+3]==2){
                        return 1;
                        }
                    }
                }
            }
        }
        if(torn==1){
            for(int i=0;i<N-3;i++){
                for(int j=0;j<N-3;j++){
                    if(tauler[i][j]!=0){
                        if(tauler[i][j]==1 && tauler[i+1][j+1]==1 && tauler[i+2][j+2]==1 && tauler[i+3][j+3]==1){
                        return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int condGuanyar(char tauler[N][N],int torn){
    for(int i=0;i<N;i++){
        if(horitzontal(tauler,i,torn,4)==1 || vertical(tauler,i,torn,4)==1){
            return 1;
        }
    }
    if(diagonalamunt(tauler,torn,4)==1 || diagonalavall(tauler,torn,4)==1){
        return 1;
    }
    return 0;
}

int main(void){
    char tauler[N][N];
    int contador=0;
    int lloc;
    int dificultat;
    int modeDeJoc;
    int ordre=0;
    printf("Vols jugar contra l'ordinador (1) o contra una altra persona (2)\n");
    scanf("%i",&modeDeJoc);
    if(modeDeJoc==1){
        printf("Qui vols que comenci tu (1) o l'ordinador (2)\n");
        scanf("%i",&ordre);
        printf("Quina dificultat vols: fàcil (1), mitjana (2) o difícil (3)\n");
        scanf("%i",&dificultat);
    }
    posarZeros(tauler);
    if(ordre==2){
        contador++;
    }
    do{
        if(contador%2==0){ //jugador=1
            demanarTirada(tauler,contador,&lloc,modeDeJoc,ordre);
            gravetat(tauler,lloc,0);
            if(modeDeJoc==1){
                imprimirTauler(tauler);
            }
        }
        if(contador%2==1){ //ordinador=2
            if(modeDeJoc==1){
                Node *arrel = malloc(sizeof(Node));
                gravetat(tauler,triarTiradaOrdinador(arrel,tauler,dificultat)+1,1);
                recorreArbreRec(arrel,0,0);
            }
            if(modeDeJoc==2){
                demanarTirada(tauler,contador,&lloc,modeDeJoc,ordre);
                gravetat(tauler,lloc,1);
            }
        }
        contador++;
        if(contador==N*N){
            imprimirTauler(tauler);
            printf("Heu empatat");
            return 0;
        }
    } while(condGuanyar(tauler,contador%2)==0);
    imprimirTauler(tauler);
    if(modeDeJoc==2){
        printf("Ha guanyat el jugador %i",(contador+1)%2+1);
    }
    if(modeDeJoc==1){
        if((contador+1)%2+1==1){
            printf("Ha guanyat el jugador\n");
        }
        else{
            printf("Ha guanyat l'ordinador\n");
        }
    }
    return 0;
}

