#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct pessoa{
	int id;
	char nome[102];
    char curso[15];
};

int count;

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

void MergeSortNome(struct pessoa *array, int inicio, int fim, int ope){
	int meio=(inicio+fim-1) / 2;

	if(inicio<fim){
		MergeSortNome(array, inicio, meio, ope);
		MergeSortNome(array, meio+1, fim, ope);
        if(count<ope){
            MergeNome(array, inicio, meio, fim);
            count++;
        }
	}
}

void MergeID(struct pessoa *array, int inicio, int meio, int fim){
	int i=inicio, j=meio+1, k=0;
    struct pessoa *aux;
	
	aux=malloc(sizeof(struct pessoa)*((fim - inicio) + 1));

	while(i<=meio && j<=fim){
		if(array[i].id<array[j].id){ //
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
		aux[k]=array[j];
		j++;
		k++;
	}
	
	for(k=0, i=inicio; i<=fim; i++, k++){
		array[i]=aux[k];
	}

}

void MergeSortID(struct pessoa *array, int inicio, int fim, int ope){
	int meio=(inicio+fim-1) / 2;

	if(inicio<fim){
		MergeSortID(array, inicio, meio, ope);
		MergeSortID(array, meio+1, fim, ope);
        if(count<ope){
            MergeID(array, inicio, meio, fim);
            count++;
        }
	}
}

int main(){
	
    char aux1[15], aux2[15];
    char busca[5];
    struct pessoa *eng, *linc, *auxiliar;
    int i, j=0, numEng, numLinc, soma, ope;

    //printf("Digite o nome do Curso 1: ");
    scanf("%s", aux1);

    //printf("Digite o numero de alunos: ");
    scanf("%d", &numEng); //Le numero de alunos no curso
    eng=malloc(numEng*sizeof(struct pessoa)); 
    for(i=0;i<numEng;i++){
        strcpy(eng[i].curso, aux1);
        //printf("Digite o ID do aluno %d: ", i+1);            
        scanf("%d", &eng[i].id);
        fflush(stdin);
        //printf("Digite o Nome do aluno %d: ", i+1);
        fgets(eng[i].nome, 102, stdin);
    }

    // CURSO 2
    
    //printf("Digite o nome do Curso 2: ");
    scanf("%s", aux2);

    //printf("Digite o numero de alunos: ");
    scanf("%d", &numLinc); //Le numero de alunos no curso
    linc=malloc(numLinc*sizeof(struct pessoa));
    for(i=0;i<numLinc;i++){
        strcpy(linc[i].curso, aux2);
        //printf("Digite o ID do aluno %d: ", i+1);
        scanf("%d", &linc[i].id);
        fflush(stdin);
        //printf("Digite o Nome do aluno %d: ", i+1);
        fgets(linc[i].nome, 102, stdin);
    }

    // VETOR AUXILIAR QUE RECEBE A SOMA DOS DOIS CURSO

    soma=numEng+numLinc;
    auxiliar=malloc(soma*sizeof(struct pessoa));

    for(i=0;i<numEng;i++){
        auxiliar[i].id=eng[i].id;
        strcpy(auxiliar[i].nome,eng[i].nome);
        strcpy(auxiliar[i].curso,eng[i].curso);
    }
    j=0;
    for(i=numEng;i<soma;i++){
        auxiliar[i].id=linc[j].id;
        strcpy(auxiliar[i].nome,linc[j].nome);
        strcpy(auxiliar[i].curso,linc[j].curso);
        j++;
    }

    // ORDENAÇÃO

    //printf("\nDigite qual forma deseja ordenar e o numero de operacoes: ");
    scanf("%s", busca);
    scanf("%d", &ope);
    fflush(stdin);
        
    if(strcmp(busca,"ID")==0){   
        MergeSortID(auxiliar, 0, soma-1, ope);
    }else
    {
        MergeSortNome(auxiliar, 0, soma-1, ope);
    }

    // PRINT

    for(i=0;i<soma;i++){
        printf("%s ", auxiliar[i].curso);
        printf("%d", auxiliar[i].id);
        printf("%s", auxiliar[i].nome);
        //printf("\n");
    }
	
    free(eng);
    free(linc);
    free(auxiliar);

	return 0;
}