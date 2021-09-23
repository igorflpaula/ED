#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct pilha{
    int tam;
	float dado;
	struct pilha *prox;
}Pilha;

void inicializar(Pilha *pilha);
void push(Pilha *pilha,float dado);
float pop(Pilha *pilha);
int estaVazia(Pilha *pilha);
void imprimeTudo(Pilha pilha);

int main(){
	
	Pilha p1, p2, p3;
	inicializar(&p1);
	float n1, n2, n3;	
	int c = 0;

    while (n1 != -1){
        scanf("%f", &n1);
  		push(&p1, n1);
  		
    }
    
    while (n2 != -1){
        scanf("%f", &n2);
  		push(&p2, n2);
  		
    }
    
    if(p1.tam >= p2.tam){
    	while(estaVazia(&p1) != 1){
    		n1 = pop(&p1);
    		if(c == 1){
    			n1++;
    			c = 0;
			}	
    		n2 = pop(&p2);
    		n3 = n1 + n2;
    		if(n3>9){
    			n3 = n3 - 10;
    			c = 1;
			}
    		
    		push(&p3, n3);
    		
		}
    	
	}
	
	else{
		while(estaVazia(&p2) != 1){
    		n1 = pop(&p1);	
    		n2 = pop(&p2);
    		if(c == 1){
    			n2++;
    			c = 0;
			}
    		n3 = n1 + n2;
    		if(n3>9){
    			n3 = n3 - 10;
    			c = 1;
			}
    		
    		push(&p3, n3);
    		
		}
		
	}
    	
	imprimeTudo(p3);
    
}

void inicializar(Pilha *pilha) {
	pilha->tam = 0;
	pilha->prox = NULL;
}

int estaVazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

void push(Pilha *pilha, float dado){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo == NULL)

	novo->dado = dado;
	novo->prox = pilha->prox;
	pilha->prox = novo;

	pilha->tam++;

}

float pop(Pilha *pilha){
    Pilha *aux = pilha->prox;
    float rem = aux->dado;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

void imprimeTudo(Pilha pilha){
	
	Pilha *aux = pilha.prox;
	
	if(aux == NULL)
	{
		printf("\nPilha esta vazia !");
	   return;
	}
	
	while(aux != NULL){
		printf("%f"  , aux->dado);
		aux = aux->prox;
	}
	printf("\n");
}


