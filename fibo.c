#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibo(int n);
int count = 0;

int main(){
    int n, resp;

    scanf("%d", &n);

    resp = fibo(n);
    printf("Fib(%d)= %d Calls= %d", n, resp, count-1);

}

int fibo (int n){
   
    if(n == 0){
        count ++;
        return 0;
    }
    if( n == 1){
        count ++;
        return 1;
    }
    count ++;
    return fibo(n-1)+fibo(n-2);
    
}