#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long w;
	long long v;
}item;

int main(){
	long long n,k,w,v;
	int i,j;
	long long** dp;
	item* bag;
	
	scanf("%lld %lld",&n,&k);
	
	if(n==0 || k==0){
		printf("0\n");
		return 0;
	}
	
	bag=(item*)malloc(sizeof(item)*(n+1));
	dp=(long long**)malloc(sizeof(long long*)*(n+1));
	for(i=0;i<=n;i++)
		dp[i]=(long long*)malloc(sizeof(long long)*(k+1)); //create array
		
	for(i=1;i<=n;i++){
		scanf("%lld %lld",&w,&v);
		bag[i].w=w;
		bag[i].v=v;
	}
	
	for(i=0;i<=k;i++)
		dp[0][i]=0;
	
	for(i=1;i<=n;i++){
		dp[i][0]=0;
		for(j=1;j<=k;j++){
			if(bag[i].w<=j){
				if(dp[i-1][j-bag[i].w]+bag[i].v>dp[i-1][j])
					dp[i][j]=dp[i-1][j-bag[i].w]+bag[i].v;
				else
					dp[i][j]=dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=k;j++)
			printf("%d ",dp[i][j]);
		printf("\n");
	}
	
	printf("%d\n",dp[n][k]);
		
}
