#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int);

int main(){
	int i,j;
	int n;
	int prime[100];
	int result=0;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&prime[i]);
	}
	
	for(i=0;i<n;i++){
		result=result+isprime(prime[i]);
	}
	
	printf("%d\n",result);
}

int isprime(int p){
	int a=sqrt(p);
	int i;
	
	if(p==1)
		return 0;
	for(i=2;i<=a;i++){
		if(p%i==0)
			return 0;
	}
	return 1;
}
