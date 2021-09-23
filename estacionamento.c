/*
Estacionamento é Fila
A saida é pilha
E Entrada
S Saida
P Print
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dado{
   char placa[9];
   int quant;
};

struct cel{
    struct dado info;
    struct cel *prox;
};
        
struct fila{
    struct cel *inicio;
    struct cel *fim;
    int tam;
};

// FUNÇÕES DE FILA

void inicia(struct fila *f){
    f->inicio=NULL;
    f->fim=NULL;
    f->tam=0;
}

void insere(struct fila *f, struct dado valor){
	struct cel *novo;
	if ((novo=(struct cel*) malloc(sizeof( struct cel)))==NULL)
		printf ("Impossivel alocar a memoria\n");
	else{
		novo->info=valor;
		novo->prox=NULL;

		if(f->inicio==NULL){
			f->inicio=novo;
			f->fim=novo;
		}
		else{
			(f->fim)->prox=novo;
			f->fim=novo;
		}
        f->tam++;
	}							
}

int retira(struct fila *f, struct dado *car){

    struct dado rem;
    if(f->inicio==NULL){
        return 0;
    }
   
    struct cel *aux=f->inicio;
    rem=aux->info;
    f->inicio=(f->inicio)->prox;
    free(aux);
    f->tam--;
    *car=rem;
    return 1;

}

int main(){
    char tipo;
    struct fila f1, f2;
    struct dado aux, car;

    inicia(&f1);
    inicia(&f2);

    while(scanf("%c %s\n", &tipo,car.placa) != EOF){
        fflush(stdin);
        if(tipo=='E'){
            car.quant=0;
            insere(&f1, car);
        }
        else if(tipo=='S'){
            while(retira(&f1,&aux)){
                if(strcmp(car.placa,aux.placa) != 0){
                    aux.quant++;
                    insere(&f2,aux);
                }
                else{
                    break;
                }
            }
            while(retira(&f1,&aux)){
                insere(&f2,aux);
            }
            while(retira(&f2,&aux)){
                insere(&f1,aux);
            }
        }

        else if(tipo == 'P'){
            while(retira(&f1,&aux)){
                printf("[%s][%d]\n", aux.placa, aux.quant);
                insere(&f2,aux);
            }
            printf("\n");
            while(retira(&f2,&aux)){
                insere(&f1,aux);
            }
        }

    }

    return 0;    
}