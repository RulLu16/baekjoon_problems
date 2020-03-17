#include <stdio.h>
#include <stdlib.h>

int main(){
	long n;
	int* num;
	int* dp;
	long i,j;
	int max;
	int temp;
	
	scanf("%ld",&n);
		
	num=(int*)malloc(sizeof(int)*n);
	dp=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	if(n<2){
		printf("%d\n",num[0]);
		return 0;
	}
	
	dp[0]=num[0];
	
	for(i=1;i<n;i++){
		if(dp[i-1]+num[i]>num[i])
			dp[i]=dp[i-1]+num[i];
		else
			dp[i]=num[i];
	}
	
	max=dp[0];
	for(i=1;i<n;i++){
		if(max<dp[i])
			max=dp[i];
	}
	printf("%d\n",max);
}
