#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *busca(int *v, int *w, int tam1, int tam2);

int main(){
    int x, c, i;
    int *v, *w, *r;

    scanf("%d", &x);
    v = malloc(sizeof(int)*x);
    scanf("%d", &c);
    w = malloc(sizeof(int)*c);


    for(i=0; i<x; i++){
        scanf("%d", &v[i]);
    }
     for(i=0; i<c; i++){
        scanf("%d", &w[i]);
    }

    r = busca(v, w, c, x);

    for(i=0; i<c; i++)
    printf("%d\n", r[i]);


    free(v);
    free(w);
    free(r);

}

int *busca(int *v, int *w, int tam1, int tam2){
    int lower, mid, higher, contador, i;
    int *r;
    r = malloc(sizeof(int)*tam1);

    for(i=0; i<tam1; i++){
        lower = 0;
        higher = tam2-1;
        contador = 0;
        while(lower <= higher){
            mid = (lower+higher)/2;
            if(w[i]<v[mid]){
                higher = mid-1;
            }else if(w[i]>v[mid]){
                lower = mid + 1;
            }else{
                contador++;
                    if(w[i]==v[mid-1]){
                        higher = mid-1;
                    }else if(w[i]==v[mid+1]){
                        lower = mid + 1;
                    }
                    else{
                        break;
                    }

                }
            }
        r[i] = contador;
    }

    return r;
}
