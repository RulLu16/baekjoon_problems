#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int main(){
	int n,i;
	int* wine;
	int temp;
	int* dp;
	
	scanf("%d",&n);
	wine=(int*)malloc(sizeof(int)*n);
	dp=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		scanf("%d",&wine[i]);
	}
	
	if(n<3){
		if(n==1)
			printf("%d\n",wine[0]);
		else if(n==2)
			printf("%d\n",wine[0]+wine[1]);	
		else{
			temp=max(wine[0]+wine[2],wine[0]+wine[1]);
			printf("%d\n",max(temp,wine[2]+wine[1]));
		}
	}
	else{
		dp[0]=wine[0];
		dp[1]=wine[0]+wine[1];
		temp=max(wine[0]+wine[2],wine[0]+wine[1]);
		dp[2]=max(temp,wine[2]+wine[1]);
		
		for(i=3;i<n;i++){
			temp=max(dp[i-1],dp[i-2]+wine[i]);
			dp[i]=max(temp,dp[i-3]+wine[i-1]+wine[i]);
		}
		printf("%d\n",dp[n-1]);		
	}
		
}
