#include <stdio.h>
#include <stdlib.h>

long long divide(long long, long long);

int main(){
	long long n,i;
	long long five,two;
	
	scanf("%d",&n);
	five=0;
	two=0;
	
	if(n==0){
		printf("0\n");
		return 0;
	}
	
	for(i=1;i<=n;i++){
		five=five+divide(i,5);
		two=two+divide(i,2);
		
	}
	
	if(five>two)
		printf("%lld\n",two);
	else
		printf("%lld\n",five);
}

long long divide(long long n,long long d){
	long long result=0;
	
	while(1){
		if(n%d!=0)
			break;
		else{
			n=n/d;
			result++;
		}
	}
	return result;
}
