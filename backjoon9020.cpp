#include <stdio.h>
#include <stdlib.h>

int isPrime(int);

int main(){
	int test;
	int n,i;
	int min,max;
	int w;
	
	scanf("%d",&test);
	for(i=0;i<test;i++){
		scanf("%d",&n);
		min=n/2;
		max=n/2;
		w=0;
		
		while(min-w>1){
			if(isPrime(min-w)==0 && isPrime(max+w)==0){
				printf("%d %d\n",min-w,max+w);
				break;
			}
			w++;
		}
	}
	
}

int isPrime(int num){
	int i;
	
	for(i=2;i<num;i++){
		if(num%i==0){
			return 1;
		}
	}
	return 0;
}
