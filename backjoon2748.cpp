#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n;
	long long* fibo;
	int i;
	
	scanf("%llu",&n);
	fibo=(long long*)malloc(sizeof(long long)*n+1);
	
	fibo[0]=0;
	fibo[1]=1;
	for(i=2;i<=n;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
	
	printf("%llu\n",fibo[n]);
}
