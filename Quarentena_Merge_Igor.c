#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 1000000

//MergeSort 26/03 Igor Francisco

struct pessoa{
	int id;
	char nome[30];
    char cpf[14];
};

void MergeNome(struct pessoa *array, int inicio, int meio, int fim){
	int i=inicio, j=meio+1, k=0;
    struct pessoa *aux;
		
	aux=malloc(sizeof(struct pessoa) * ((fim - inicio) + 1));

	while(i<=meio && j<=fim){
		if(strcmp(array[i].nome,array[j].nome) < 0){
			aux[k] = array[i];
			i++;
		}

		else{
			aux[k]=array[j];
			j++;
		}

		k++;
	}
	
	while(i<=meio){
		aux[k]=array[i];
		i++;
		k++;
	}
	
	while(j<=fim){
		aux[k] = array[j];
		j++;
		k++;
	}
	
	for(k=0, i=inicio; i<=fim; i++, k++){
		array[i]=aux[k];
	}

}

void MergeSortNome(struct pessoa *array, int inicio, int fim){
	int meio=(inicio+fim) / 2;
	
	if(inicio<fim) 
	{
		MergeSortNome(array, inicio, meio);
		MergeSortNome(array, meio+1, fim);
		MergeNome(array, inicio, meio, fim);
	}
}

void MergeCPF(struct pessoa *array, int inicio, int meio, int fim){
	int i=inicio, j=meio+1, k=0;
    struct pessoa *aux;
	
	aux=malloc(sizeof(struct pessoa) * ((fim - inicio) + 1));

	while(i<=meio && j<=fim){
		if(strcmp(array[i].cpf,array[j].cpf) < 0){
			aux[k]=array[i];
			i++;
		}

		else{
			aux[k]=array[j];
			j++;
		}

		k++;
	}
	
	while(i<=meio){
		aux[k]=array[i];
		i++;
		k++;
	}
	
	while(j<=fim){
		aux[k] = array[j];
		j++;
		k++;
	}
	
	for(k=0, i=inicio; i<=fim; i++, k++){
		array[i]=aux[k];
	}

}

void MergeSortCPF(struct pessoa *array, int inicio, int fim){
	int meio=(inicio + fim) / 2;
	
	if(inicio < fim) 
	{
		MergeSortCPF(array, inicio, meio);
		MergeSortCPF(array, meio+1, fim);
		MergeCPF(array, inicio, meio, fim);
	}
}

void gen_random_cpf(char *s, const int len){

    int i;
    static const char alphanum[] = "0123456789";

    for (i=0; i<len; ++i){
        s[i]=alphanum[rand() % (sizeof(alphanum)-1)];
    }

    s[len] = 0;
}

void gen_random_nome(char *s, const int len){

    int i;
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (i=0; i<len; ++i){
        s[i]=alphanum[rand() % (sizeof(alphanum)-1)];
    }

    s[len] = 0;
}

int main(){

    int i;  
    struct pessoa *vetor_p;
    srand(time(NULL));
    vetor_p=malloc(tam*sizeof(struct pessoa));

    printf("###Criando nomes e CPF's aleatorios, aguarde###\n\n");

    for(i=0;i<tam;i++){
        gen_random_nome(vetor_p[i].nome,29);
        gen_random_cpf(vetor_p[i].cpf,13);
        vetor_p[i].id=i;
    }    
    
    printf("#Nomes e CPF ordenados de forma aleatoria#\n");

    printf("*Posicao 1 ao 10*\n");
    for(i=0;i<10;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }

    printf("\n*Posicao 999.990 ao 1.000.000*\n");
    for(i=(tam-10);i<tam;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }

    MergeSortNome(vetor_p,0,tam-1);

    printf("\n\n#Ordenados pelo NOME#\n");

    printf("*Posicao 1 ao 10*\n");
    for(i=0;i<10;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }

    printf("\n*Posicao 999.990 ao 1.000.000*\n");
    for(i=(tam-10);i<tam;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }

    MergeSortCPF(vetor_p,0,tam-1);

    printf("\n\n#Ordenados pelo CPF#\n");

    printf("*Posicao 1 ao 10*\n");
    for(i=0;i<10;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }
    printf("\n*Posicao 999.990 ao 1.000.000*\n");
    for(i=(tam-10);i<tam;i++){
        printf("ID: %d\n    Nome: %s\n    CPF: %s\n", vetor_p[i].id,vetor_p[i].nome,vetor_p[i].cpf);
    }

    printf("\n");

    return 0;
}