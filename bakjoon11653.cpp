#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	long long n;
	long long i,j;
	
	scanf("%lld",&n);
	j=sqrt(n);
	for(i=2;i<=j;i++){
		while(n%i==0){
			printf("%lld\n",i);
			n=n/i;
		}	
	}
	if(n>1)
		printf("%lld\n",n);
	
}
