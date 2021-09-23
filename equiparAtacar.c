#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void conquest(double *v, int i, int f, int m){

    double *vAux=malloc((f-i+1)*sizeof(double)); 

    int start=i;
    int meio=m+1;
    int cont=0;

    while ((start<=m) && (meio<=f)){

        if(v[start]>v[meio]){

            vAux[cont]=v[meio];
            meio++;

        } else{
            vAux[cont]=v[start];
            start++;
        }
        cont++;
    }

    while(start<=m){
        vAux[cont]=v[start];
        start++;
        cont++;
    }

    while(meio<=f){
        vAux[cont]=v[meio];
        meio++;
        cont++;
    }

    int k;
    for(k=i , cont=0; k<=f; k++, cont++){
        v[k]=vAux[cont];
    }

    free(vAux);

}

void merge(double *v,int i, int f, int s){

    if(i<f){
        int m=(i+f)/2;
        merge(v,i,m,s);
        merge(v,m+1,f,s);
        conquest(v,i,f,m);

    }

}

void bb(double *v, double x, int l, int r, int *inter, int size){ 
    while((l<r) && (l!=(size-1))){ 
        int m=(r+l)/2; 
  
        if (v[m]<=x){
            inter[0]=m;
            if((inter[0]!=-1) && (inter[1]!=-1)){
                return;
            }
            l=m; 
            
        }else{
            inter[1]=m;
            if((inter[0]!=-1) && (inter[1]!=-1)){
                return;
            }
            
            r=m;  
        }
    }   
}

int main(){

    int n, q, *inter, abat;
    double x0, y0, xe, ye, r, *enemy;
    int i;

    scanf("%d", &n);
    scanf("%d", &q);
    scanf("%lf%lf", &x0, &y0);

    enemy=malloc(n*sizeof(double));
    inter=malloc(2*sizeof(int));
    
    for(i=0;i<n; i++){

        scanf("%lf%lf", &xe, &ye);
        enemy[i]= sqrt(pow(x0 - xe, 2)+ pow(y0 - ye, 2));

    }

    merge(enemy,0,n-1,n-1);

    i=0;

    while(i<q){

        scanf("%lf", &r);
        inter[0]=-1;
        inter[1]=-1;

        bb(enemy, r, 0, n, inter, n);
        abat=inter[0];

        if((inter[0]!=-1) && (inter[1]!=-1)){
            for(abat=inter[0]; abat<inter[1]; abat++){
                if(enemy[abat]>r){
                    break;
                }
            }
            
            printf("%d\n", abat);
            
        }else if(inter[0] == -1){
            printf("0\n");
        }else if(inter[1] == -1){
            printf("%d\n", n);
        }
        
        i++;
    }
    
    return 0;
}
