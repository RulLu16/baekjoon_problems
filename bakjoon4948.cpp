#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int);

int main(){
	int n,i;
	int result=0;
	int mid;
	
	while(1){
		scanf("%d",&n);
		
		if(n==0)
			break;
		result=0;
		for(i=n+1;i<=2*n;i++){
			if(isprime(i))
				result++;
		}
		printf("%d\n",result);
	}
}

int isprime(int a){
	int i;
	int root;
	
	if(a<2)
		return 0;
	
	root=sqrt(a);
	
	for(i=2;i<=root;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}
