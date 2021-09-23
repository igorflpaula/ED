#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mdc(int x, int y){
	
	if(x>=y && x%y == 0){
        return y;
    }
    if(x<y){
        return mdc(y, x);
    }
    return mdc(y, x%y);
	
}

int mod(int x, int y){
	
	if(x>=y){
		mod(x-y, y);
	}
	else{
		return x;
	}

	return 0;
}

int pot(int x, int y){

	if (y==0){
		return 1;
	}
	
	return x*pot(x,y-1);
}

int main(){
	
	int x, y, i;
	char resp[5];

	scanf("%d %d", &x, &y);
	
	for(i=0; i<4; i++){
		
		scanf("%s", resp);
		
		if(strcmp(resp,"MOD")==0){
			if(x>=y){
				printf("MOD(%d,%d) = %d\n", x, y, mod(x-y,y));
			}
			else{
				printf("MOD(%d,%d) = %d\n", x, y, x);
			}
		}
		
		if(strcmp(resp,"POT")==0){
			printf("POT(%d,%d) = %d\n", x, y, pot(x,y));
		}
		
		if(strcmp(resp,"MDC")==0){
			printf("MDC(%d,%d) = %d\n", x, y, mdc(x,y));
		}
		
		if(strcmp(resp,"OOO")==0){
			break;
		}
	}
	
	return 0;	
	
}