#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
ini = inicio
seg = proximo
back = ultimo
*/

struct queue{
    char date[9];
    int tamanho;
    struct queue *ini;
    struct queue *back;
    struct queue *seg;
};

typedef struct queue Queue;

void start(Queue *queue){
    queue->tamanho= 0;
    queue->ini= NULL;
    queue->back= NULL;
}

void enqueue(Queue *queue, char *element){
    Queue *new= (Queue *) malloc(sizeof(Queue));
    if(new!= NULL){
        strcpy(new->date, element);
        new->seg= NULL;

        if(queue->ini== NULL){
            queue->ini= new;
            queue->back= new;
        }else{
            queue->back->seg = new;
            queue->back= new;
        }
    }
}

void dequeue(Queue *queue){
    Queue *ini= queue->ini;

    if(queue!= NULL){
        queue->ini= ini->seg;
        free(ini);
    }
    
}

void display(Queue *queue){
    Queue *element= queue->ini;
    
    while(element!= NULL){
        printf("%s ", element->date);
        element= element->seg;
    }
    printf("\n");
}

void displayIni(Queue *queue){
    Queue *element =queue->ini;
    printf("%s ", element->date);

}

int main(){
    int n, aux, flag;

    Queue *q =malloc(sizeof(Queue));
    start(q);

    scanf("%d", &n);
    
    enqueue(q, "7");
    aux =0;
    flag =10 * atoi(q->ini->date);

    while(flag<= n){
        if(aux ==0){
            enqueue(q, q->ini->date);
            strcat(q->back->date,"0");
            aux =7;
            flag =10 * atoi(q->ini->date);
        }else if(aux ==7){
            enqueue(q, q->ini->date);
            strcat(q->back->date,"7");
            displayIni(q);
            dequeue(q);
            aux =0;
            flag =10 * atoi(q->ini->date)+7;
        }
    }
    display(q);
    return 0;
}
