#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct stack{
    int tam;
    double dado;
    struct stack *prox;
}Pilha;

void inicializar(Pilha *pilha) {
	pilha->tam = 0;
	pilha->prox = NULL;
}

int estaVazia(Pilha *pilha){
	return pilha->prox == NULL ? 1 : 0;
}

int push(Pilha *pilha,double dado){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo==NULL)
	   return 0;

	novo->dado=dado;
	novo->prox=pilha->prox;
	pilha->prox=novo;
    //printf("Novo Dado: %.2lf\n", novo->dado);
	pilha->tam++;

	return 1;
}

double pop(Pilha *pilha){
    Pilha *aux = pilha->prox;
    int rem = aux->dado;

    pilha->prox = pilha->prox->prox;
    free(aux);

    pilha->tam--;
    return rem;
}

int main(){
    int i;
    double valor, n1, n2;
    char token[30];
    Pilha p1;
    inicializar(&p1);

    fgets(token,30,stdin);

    token[strcspn(token, "\n")] = '\0';

    char *split = strtok(token, " ");

    while(split != NULL){

        if(split[0]=='+' || split[0]=='-' || split[0]=='/' || split[0]=='*'){
            n2=pop(&p1);
            n1=pop(&p1);
            
            switch(split[0]){
                case '+':
                    push(&p1,n1+n2);
                    //printf("%.2lf + %.2lf = %.2lf\n", n1, n2, n1+n2);
                    break;

                case '-':
                    push(&p1,n1-n2);
                    //printf("%.2lf - %.2lf = %.2lf\n", n1, n2, n1-n2);
                    break;

                case '/':
                    push(&p1,n1/n2);
                    //printf("%.2lf / %.2lf = %.2lf\n", n1, n2, n1/n2);
                    break;

                case '*':
                    push(&p1,n1*n2);
                    //printf("%.2lf * %.2lf = %.2lf\n", n1, n2, n1*n2);
                    break;

                default:
                    break;
            }

        }else{ // Se não funcionar, usar elfe if(split[i]>47 && split[i]<58)
            valor=0;

            for(i=0;i<strlen(split);i++){
                if(split[i]>47 && split[i]<58){
                    valor+=pow(10,strlen(split)-1-i)*(split[i]-'0');
                }
            }
            push(&p1,valor);
        }
        split = strtok(NULL, " ");
    }

    valor=pop(&p1);
    if(estaVazia(&p1)){
        printf("%.2lf",valor);
    }else{
        printf("*ERRO*");
    }

    return 0;
}