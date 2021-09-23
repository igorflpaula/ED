#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int tam;
	char cara; //onde ta c, mudar para dado
    int x;
    int y;
	struct stack *prox;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha){
	pilha->tam=0;
	pilha->prox=NULL;
}

int estaVazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

char pop(Pilha *pilha){  
    Pilha *aux = pilha->prox;
    char rem = aux->cara;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

int push(Pilha *pilha,int x, int y, char cara){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo == NULL)
	   return 0;

	novo->x=x;
	novo->y=y;
	novo->cara=cara;
    novo->prox=pilha->prox;
    pilha->prox=novo;

	pilha->tam++;

    return 1;
}

/*
void imprimeTudo(Pilha pilha){
	
	Pilha *aux=pilha.prox;
	
	if(aux == NULL){
	    printf("\nPilha esta vazia!");
	    return;
	}
	
	printf("\nPilha\n");
	
	while(aux != NULL){
		printf("%d", aux->cara);
		aux=aux->prox;
	}

	printf("\n");
}

int imprimeTopo(Pilha pilha){

    Pilha *aux=pilha.prox;
    
	return aux->cara;
}
*/

int main(){
    int i, j, x, y, auxLinha, auxColuna;
    char aux, normie, **vetor;
    Pilha p1;

    inicializar(&p1);
    scanf("%d %d", &x, &y); //Recebe as dimensões do desenho (LINHAxColuna)
  
    vetor=malloc(x*sizeof(char*));

    for(i=0;i<x;i++){
        vetor[i]=malloc(y*sizeof(char));
    }

    for(i=0;i<x;i++){ // Matriz do Desenho 
        for(j=0;j<y;j++){
          do{
              scanf("%c", &aux);
          }while((aux=='\n') || (aux=='\r'));
          vetor[i][j]=aux;
        }
    }

    while(scanf("%d %d %c", &auxLinha,&auxColuna,&normie) != EOF){

        aux=vetor[auxLinha][auxColuna];
        push(&p1, auxLinha, auxColuna, normie);

        while(p1.prox != NULL){
            auxLinha=p1.prox->x;
            auxColuna=p1.prox->y;
            normie=p1.prox->cara;
            pop(&p1);

            if(vetor[auxLinha][auxColuna]==aux){
                vetor[auxLinha][auxColuna]=normie;
            }

            if(auxLinha-1>=0){
                if(vetor[auxLinha-1][auxColuna]==aux){
                    push(&p1,auxLinha-1,auxColuna,normie);
                }
            }

            if(auxLinha+1<x){
                if(vetor[auxLinha+1][auxColuna]==aux){
                    push(&p1,auxLinha+1,auxColuna,normie);
                }
            }

            if(auxColuna+1<y){
                if(vetor[auxLinha][auxColuna+1]==aux){
                    push(&p1,auxLinha,auxColuna+1,normie);
                }
            }

            if(auxColuna-1>=0){
                if(vetor[auxLinha][auxColuna-1]==aux){
                    push(&p1,auxLinha,auxColuna-1,normie);
                }
            }
        }

        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                printf("%c", vetor[i][j]);
            }
            printf("\n");
        }
    }

    for(i=0;i<x;i++){
        free(vetor[i]);
    }

    free(vetor);

    return 0;
}