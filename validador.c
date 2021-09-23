#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct stack {
	int tamanho;
	char dados;
	struct stack *pr;
};

typedef struct stack Pilha;

void inicializar(Pilha *pilha) {
	pilha->tamanho=0;
	pilha->pr=NULL;
}

int vazia(Pilha *pilha){
	return pilha->pr==NULL ? 1 : 0;
}

int push(Pilha *pilha,char dados){
	Pilha *novo=(Pilha *)malloc(sizeof(Pilha));
	if(novo==NULL)
	   return 0;

	novo->dados=dados;
	novo->pr=pilha->pr;
	pilha->pr=novo;
	pilha->tamanho++;

	return 1;
}

char pop(Pilha *pilha){
    Pilha *aux=pilha->pr;
    int rem=aux->dados;

    pilha->pr=pilha->pr->pr;
    free(aux);

    pilha->tamanho--;
    return rem;
}


int main (void){

    char s[100];
    int i = 0;
    int flag = 0;
    char n1[1];
    Pilha p1;
    int contador = 0;

    inicializar(&p1);
    fgets(s,100,stdin);

    while (i<strlen(s))
    {
   	switch(s[i]){
            case '{':
            push(&p1, s[i]);
            contador++;
            break;

            case '(':
            push(&p1, s[i]);
            contador++;
            break;

            case '[':
            push(&p1, s[i]);
            contador++;
            break;

            case ']':
            n1[0] = pop(&p1);
            if(n1[0]!='['){
                flag = 1;
                break;
            }
            contador--;
            break;

            case ')':
            n1[0] = pop(&p1);
            if(n1[0]!='('){
                flag = 1;
                break;
            }
            contador--;
            break;

            case '}':
            n1[0] = pop(&p1);
            if(n1[0]!='{'){
                flag = 1;
                break;
            }
            contador--;
            break;

            default:
                break;

        }
            i++;
    }

    if(flag==1 || contador !=0){
        printf("Invalido\n");
    }
    else{
        printf("Valido\n");
    }

    return 0;

}
