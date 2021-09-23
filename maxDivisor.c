#include <stdio.h>
#include <stdlib.h>

int divisor(int x, int y);

int main(){
    int x , y, resp;
    scanf("%d %d", &x, &y);

    resp = divisor(x, y);
    printf("%d", resp);

    return 0;
}

int divisor(int x, int y){

    if(x>=y && x%y == 0){
        return y;
    }
    if(x<y){
        return divisor(y, x);
    }
    return divisor(y, x%y);
}