#include <stdio.h>
#include <stdlib.h>

struct cel{
    int info;
    struct cel *prox;
};
        
struct fila{
    struct cel *inicio;
    struct cel *fim;
};

void inicia(struct fila *f){
    f->inicio=NULL;
    f->fim=NULL;
}

void insere(struct fila *f, int valor){
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
	}							
}

int retira(struct fila *f){
   
    struct cel *aux=f->inicio;
    int rem=aux->info;
    f->inicio=(f->inicio)->prox;
    free(aux);
    return rem; 
}

void apresentaFila(struct fila *f){
     struct cel *aux;
     int i=1;
     aux=f->inicio;
 
    while(aux != NULL){
        printf("Elemento %d: %d\n", i, (aux->info));
       	aux=aux->prox;
        i++;
	 }

}

int main(){

    int TAM, i, valor, saida;
    struct fila f;

    //printf("Digite tamanho da fila: ");
    scanf("%d", &TAM);
    int vetor[TAM];

    inicia(&f);

    //printf("Digite a fila: ");
    for(i=0;i<TAM;i++){
        scanf("%d", &valor);
        insere(&f, valor);
    }

    for(i=0;i<TAM;i++){
        saida=retira(&f);
        vetor[i]=saida;
        //printf("Retirado: %d\n", saida);
    }

    for(i=TAM-1;i>=0;i--){
        //printf("Inverso: %d\n", vetor[i]);
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}