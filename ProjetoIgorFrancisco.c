#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

//IGOR FRANCISCO LIMA DE PAULA	

/*Comparacao eh o IF
Operacoes eh o que tem dentro do IF

No Insert e no Selection, Prefeito=Eleito
*/

struct time{ 
	int tam;
	double sec;
};

//Bubblesort Melhorado

void bsm(int *item, int count){
	int i, j, q, aux, bbw=1, comp=0, ope=0;
	
	/* Função de Copia, no Projeto não é usada
	for(q=0;q<=count;q++){
		item[q]=vetor[q];
	}
	*/
	
	for(i=0; i<count-1 && bbw==1; i++){
        bbw=0;
        for(j=0;j<count-1;j++){
            comp++;
            if(item[j]>item[j+1]){
                bbw=1;
                aux=item[j];                      
                item[j]=item[j+1];
                item[j+1]=aux;
                ope=ope+3;
            }
        }        
    }
	
	/*
	printf("\nVetor Ordenado BSM: ");
	for(i=0;i<count;i++){
		printf("%d ", item[i]);
	}
	*/
	
	//printf("\nBubblesort v2 = %d comparacoes, %d operacoes", comp, ope);
}

//Bubblesort Simples

void bss(int *item, int count){
	int n, i, q, aux, comp=1, ope=0;
	
	/* Função de Copia, no Projeto não é usada
	for(q=0;q<=count;q++){
		item[q]=vetor[q];
	}
	*/
	
	for(n=1;n<=count;n++){
		comp--;
		for(i=0;i<count-1;i++){
			if(item[i]>item[i+1]){
				aux=item[i];
				item[i]=item[i+1];
				item[i+1]=aux;
				ope=ope+3;
			}
			comp++;
		}
	}
	
	/*
	printf("\nVetor Ordenado BSS: ");
	for(i=0;i<count;i++){
		printf("%d ", item[i]);
	}
	*/
	
	//printf("Bubblesort v1 = %d comparacoes, %d operacoes", comp, ope);
}

//Insertsort

void ins(int *item, int count){
	int i, j, q, prefeito, comp=1, ope=0;
	
	/* Função de Copia, no Projeto não é usada
	for(q=0;q<=count;q++){
		item[q]=vetor[q];
	}
	*/
	
	for(i=1;i<=count-1;i++){
		prefeito=item[i];
		j=i-1;
		comp++;
		
		while(j>=0 && item[j]>prefeito){
			item[j+1]=item[j];
			j=j-1;
			ope=ope+2;
			comp++;
		}
		
		item[j+1]=prefeito;
	}
	
	/*
	printf("\nVetor Ordenado INS: ");
	for(i=0;i<count;i++){
		printf("%d ", item[i]);
	}
	*/
	
	//printf("\nInsertionsort = %d comparacoes, %d operacoes", comp-1, ope);
}

//SelectionSort

void selec(int *item, int count){

	int i, j, q, prefeito, menor, pos;

	/* Função de Copia, no Projeto não é usada
	for(q=0;q<=count;q++){
		item[q]=vetor[q];
	}
	*/

    for(i=0;i<count-1;i++){
        prefeito=item[i];
        menor=item[i+1];
        pos=i+1;

        for(j=i+1;j<count;j++){
            if(item[j]<menor){
                menor=item[j];
                pos=j;
            }
        }

        if(menor<prefeito){
            item[i]=item[pos];
            item[pos]=prefeito;
        }
    }

	//Selection ainda não conta comparações e operações
	//printf("\nSelectionSort = %d comparacoes, %d operacoes", comp-1, ope);
}

int main(){
	
	int i, j, aux;
	struct timeval start, stop;
	struct time bubble[6];
	struct time bmelhor[6];
	struct time insertion[6];
	struct time selection[6];
	
	int *p, *p1, *p2, *p3;

	printf("Espere o programa trabalhar xD\n\n");

	for(i=0;i<6;i++){

		aux=5000*(i+1);

        p=malloc(aux*sizeof(int));
        p1=malloc(aux*sizeof(int));
        p2=malloc(aux*sizeof(int));
        p3=malloc(aux*sizeof(int));

        srand(time(NULL));
        for(j=0;j<aux;j++){

            p[j]=rand()%aux;

            p1[j]=p[j];
            p2[j]=p[j];
            p3[j]=p[j];
        }

		//BUBBLE

        gettimeofday(&start, NULL);
        
        bss(p,aux);

        gettimeofday(&stop, NULL);

        bubble[i].tam=aux;
        bubble[i].sec=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

		//BUBBLE MELHORADO
        
        gettimeofday(&start, NULL);
        
        bsm(p1,aux);

        gettimeofday(&stop, NULL);

        bmelhor[i].tam=aux;
        bmelhor[i].sec=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

		//INSERTION

        gettimeofday(&start, NULL);
        
        ins(p2,aux);

        gettimeofday(&stop, NULL);

        insertion[i].tam=aux;
        insertion[i].sec=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

		//SELECTION

        gettimeofday(&start, NULL);
        
        selec(p3,aux);

        gettimeofday(&stop, NULL);

        selection[i].tam=aux;
        selection[i].sec=(double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

		//Libera a Badernah

		free(p);
		free(p1);
		free(p2);
		free(p3);

	}
	
    for(i=0;i<6;i++){
        aux=5*(i+1);
        printf("TAMANHO %dK\n",aux);
        printf("Bubble Simples: %lf\n", bubble[i].sec);
        printf("Bubble Melhorado: %lf\n", bmelhor[i].sec);
        printf("Insertion: %lf\n", insertion[i].sec);
        printf("Selection: %lf\n\n", selection[i].sec);
    }

	return 0;
}