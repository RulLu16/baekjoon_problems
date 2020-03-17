#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int);

int main(){
	int m,n;
	int i;
	
	scanf("%d %d",&m,&n);
	for(i=m;i<=n;i++){  
		if(isprime(i)==1)
			printf("%d\n",i);
	}
	
}

int isprime(int a){
	int temp;
	int i;
	
	if(a==1)
		return 0;
		
	temp=sqrt(a);
	for(i=2;i<=temp;i++){
		if(a%i==0){
			//printf("%d ",a);
			return 0;
		}
	}
	return 1;
}

