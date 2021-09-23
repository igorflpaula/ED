#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct pessoa{
	int id;
	char nome[102];
    char curso[15];
};

void bsmID(struct pessoa *item, int soma){
	int q, p;
    struct pessoa aux;

    for(q=1;q<soma;q++){
        for (p=0; p<soma-1; p++){
            if(item[p].id>item[p+1].id){
                aux=item[p];
                item[p]=item[p+1];
                item[p+1]=aux;
            }
        }
    }

}

void bsmNome(struct pessoa *item, int soma){
	int q, p;
    struct pessoa aux;

    for(q=1;q<soma;q++){
        for(p=0; p<soma-1; p++){
            if(strcmp(item[p].nome,item[p+1].nome)>0){
                aux=item[p];
                item[p]=item[p+1];
                item[p+1]=aux;
            }
        }
    }
	
}

/*
void engenharia(int numEng, struct pessoa *eng){
    int i;

    for(i=0;i<numEng;i++){
        printf("Digite o ID do aluno %d: ", i);
        fgets(eng[i].nome,sizeof(eng[i].nome), stdin);
        printf("Digite o Nome do aluno %d: ", i);
        fgets(eng[i].id,sizeof(eng[i].id), stdin);
        *eng[i].curso= "ENGCOMP";
    }
}

void licenciatura(int i, struct pessoa *linc){
    
    printf("Digite o ID: ");
    scanf("%s", linc[i].id);
    printf("Digite o Nome: ");
    scanf("%s", linc[i].nome);
}*/

int main(){
	
    char aux1[15], aux2[15];
    char busca[5];
    struct pessoa *eng, *linc, *auxiliar;
    int i, j=0, numEng, numLinc, soma;

    //printf("Digite o nome do Curso 1: ");
    scanf("%s", aux1);

    //printf("Digite o numero de alunos: ");
    scanf("%d", &numEng); //Le numero de alunos no curso
    eng=malloc(numEng*sizeof(struct pessoa)); 
    //engenharia(numEng, eng);
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
    //licenciatura(numLinc, linc);
    for(i=0;i<numLinc;i++){
        strcpy(linc[i].curso, aux2);
        //printf("Digite o ID do aluno %d: ", i+1);
        scanf("%d", &linc[i].id);
        fflush(stdin);
        //printf("Digite o Nome do aluno %d: ", i+1);
        fgets(linc[i].nome, 102, stdin);
    }

    /*if(j=2){
        printf("Curso nao existe");
        return 0;
    }*/

    /*for(i=0;i<2;i++){
        printf("Digite o nome do curso: ");
        scanf("%s", aux);

        if(strcmp(aux,"ENGCOMP")==0 || strcmp(aux,"LICENCIATURA")==0){
            for(i=0;i<2;i++){	
                if(strcmp(aux,"ENGCOMP")==0){
                    printf("Digite o numero de alunos: ");
                    scanf("%d", &numEng); //Le numero de alunos no curso
                    eng=malloc(numEng*sizeof(struct pessoa)); 
                    engenharia(numEng, eng);
                }
                
                if(strcmp(aux,"LICENCIATURA")==0){
                    printf("Digite o numero de alunos: ");
                    scanf("%d", &numLinc); //Le numero de alunos no curso
                    eng=malloc(numLinc*sizeof(struct pessoa));
                    licenciatura(numLinc, linc);
                }
            }
        }else{
            printf("Curso nao existe\n");
        }
    }*/

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

    //printf("\nDigite qual forma deseja ordenar: ");
    scanf("%s", busca);
        
    if(strcmp(busca,"ID")==0){   
        bsmID(auxiliar,soma);
    }else
    {
        bsmNome(auxiliar,soma);
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