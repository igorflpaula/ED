#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int tam;
	char dado;
	struct stack *prox;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha){
	pilha->tam = 0;
	pilha->prox = NULL;
}

int estaVazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

char push(Pilha *pilha,char dado){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo == NULL)
	   return 0;

	novo->dado = dado;
	novo->prox = pilha->prox;
	pilha->prox = novo;

	pilha->tam++;

    return 1;
}

char pop(Pilha *pilha){  
    Pilha *aux = pilha->prox;
    char rem = aux->dado;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

void destroiPilha(Pilha *p){
    free(p->prox);
    free(p);
}

int analise(char vet[], Pilha *pilha, int tamanho){
    int i, vazio;
    char prefeito, vereador;

    for (i=0; i<tamanho; i++){
        prefeito=vet[i];
        if(prefeito == '{' || prefeito == '[' || prefeito == '('){
            push(pilha, prefeito);
        }else if(prefeito == '}' || prefeito == ']' || prefeito == ')') {
            if(estaVazia(pilha)){
                return 0;
            }

            vereador=pop(pilha);
            if ((prefeito == '}' && vereador != '{') || (prefeito == ']' && vereador != '[') || (prefeito == ')' && vereador != '(')) {
                //destroiPilha(pilha);
                return 0;
            }
        }
    }

    vazio=estaVazia(pilha);
    return vazio;
}

int main(){
    char string[100];
    Pilha p1;
    int tam=0;

    //printf("Digite a equacao:\n");

    scanf("%99s", string);
    //printf("%s", string);
    tam=strlen(string);
    //printf("Tamanho %d", tam);

    inicializar(&p1);
    /*if(estaVazia(&p1)){
		printf("\nPilha vazia! Pode continuar\n");
	}*/

    if(analise(string, &p1, tam)){
        printf("Valido\n");
    }else{
        printf("Invalido\n");
    }

    return 0;
}
