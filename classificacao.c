#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void medalha(int *v, char **c, int tamanho){
    int i, n, aux;
    char aux2[100];

    for(n=1; n<=tamanho; n++){
        for(i=0; i<tamanho-1; i++){
            
			if(v[i]<v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;

                strcpy(aux2, c[i]);
                strcpy(c[i], c[i+1]);
                strcpy(c[i+1], aux2);
            }
        }
    }
    return;
}

void nome(int *v, char **c, int tamanho){
    int i, n;
    char aux[100];

    for(n=1; n<=tamanho-1; n++){
        for(i=0; i<tamanho; i++){
            if(v[i]==v[i+1]){
                if(strcmp(c[i], c[i+1])>0){
                    strcpy(aux, c[i]);
                    strcpy(c[i], c[i+1]);
                    strcpy(c[i+1], aux);
                }
            }
        }
    }

}

int main (){
    int tamanho, i;
    int *v;
    char **c;

    scanf("%d", &tamanho);

    v=(int*)malloc(sizeof(int)*tamanho);
    
    c=(char**)malloc(tamanho*sizeof(char*));
    
    for(i=0; i<tamanho; i++){
        c[i]=(char*)malloc(tamanho*sizeof(char));
    }

    for(i=0; i<tamanho; i++){
        scanf("%s",c[i]);
        scanf("%d",&v[i]);
    }

    medalha(v, c, tamanho);
    nome(v, c, tamanho);

    for(i=0; i<tamanho; i++){
        printf("%s %d\n", c[i], v[i]);
    }
}
