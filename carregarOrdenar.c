#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa{
	int defy;
	char nota[100];	
}pessoa;

void merge2(pessoa *p, pessoa *p1, int e, pessoa *p2,int d){
	
	int i=0,j=0,k=0;

	while(i<e && j<d){
		if(strcmp(p1[i].nota, p2[j].nota)<0)
			p[k++]=p1[i++];
			
		else 
			p[k++]=p2[j++];
	}
	
	while(i<e) 
		p[k++]=p1[i++];
	while(j<d) 
		p[k++]=p2[j++];
}

void mergesort(pessoa *p ,int n){
	
	int m,i;
    pessoa *p1, *p2;
    
	if(n<2) 
		return; 

	m=n/2; 

	p1=malloc(m*sizeof(pessoa));
	p2=malloc((n - m)*sizeof(pessoa));

	for(i=0; i<m; i++) 
		p1[i]=p[i];
		
	for(i=m; i<n; i++) 
		p2[i-m]=p[i];

	mergesort(p1,m); 
	mergesort(p2,n-m); 
	merge2(p,p1,m,p2,n-m); 
        free(p1);
        free(p2);
}

int func(pessoa *p, char *s, int n){
	
    int b=0, m, a=n-1;

    for(;b<=a;){
        m=(b+a)/2;
        if(strcmp(s, p[m].nota)<0){
            a=m-1;
        }else if(strcmp(s, p[m].nota)>0){
            b=m+1;
        }else{
            return p[m].defy;
        }
    }
    
    return 1;

}

int main(){
	
	int i, n, defy;
	char s[100];
	pessoa *p;
	
	scanf("%d", &n);
	scanf("%s", s);
	
	p=malloc(n*sizeof(pessoa));
	
	for(i=0; i<n; i++){		
		scanf("%d", &p[i].defy);
		scanf("%s", p[i].nota);
	}
	
	mergesort(p, n);
	
	defy = func(p, s, n);
	
	printf("%d\n", defy);
	
	return 0;
	
}
