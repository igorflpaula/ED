#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Comparacao eh o IF
Operacoes eh o que tem dentro do IF

No Insert, Prefeito=Eleito
*/

//Bubblesort Melhorado

void bsm(int *vetor, int count){
	int i, j, q, aux, bbw=1, comp=0, ope=0, item[count];
	
	for(q=0;q<=count;q++){  //COPIA
		item[q]=vetor[q];
	}
	
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
	
	printf("\nBubblesort v2 = %d comparacoes, %d operacoes", comp, ope);
}

//Bubblesort Simples

void bss(int *vetor, int count){
	int n, i, q, aux, comp=1, ope=0, item[count];
	
	for(q=0;q<=count;q++){ //COPIA
		item[q]=vetor[q];
	}
	
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
	
	printf("Bubblesort v1 = %d comparacoes, %d operacoes", comp, ope);
}

//Insertsort

void ins(int *vetor, int count){
	int i, j, q, prefeito, comp=1, ope=0, item[count];
	
	for(q=0;q<=count;q++){ //COPIA
		item[q]=vetor[q];
	}
	
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
	
	printf("\nInsertionsort = %d comparacoes, %d operacoes", comp-1, ope);
}

int main(){
	
	int tam, i;
	
	//printf("Digite o tamanho do vetor:\n");
	scanf("%d", &tam);
	
	int vet[tam];
	//printf("Digite o vetor:\n");
	
	for(i=0;i<tam;i++){
		scanf("%d", &vet[i]);
	}
	
	bss(vet, tam);
	bsm(vet, tam);
	ins(vet, tam);
	
	return 0;
	
}