#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n;
	long long* sum;
	long long i;
	
	scanf("%lld",&n);
	sum=(long long*)malloc(sizeof(long long)*n);
	
	if(n<3){
		switch(n){
			case 1:
				printf("1\n");
				break;
			case 2:
				printf("2\n");
		}
	}
	else{
		sum[0]=1;
		sum[1]=2;
		for(i=2;i<n;i++){
			sum[i]=(sum[i-1]+sum[i-2])%15746;
		}
		
		printf("%lld\n",sum[n-1]);
	}
}
