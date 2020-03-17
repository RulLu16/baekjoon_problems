#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int);

int main(){
	int i,j;
	int n,m;
	int result=0;
	int min;
	
	scanf("%d",&m);
	scanf("%d",&n);
	
	for(i=m;i<=n;i++){
		if(isprime(i)==1){
			if(result==0)
				min=i;
			result=result+i;
		}
	}
	if(result==0){
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n",result,min);
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

