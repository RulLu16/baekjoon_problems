#include <stdio.h>
#include <stdlib.h>

int minn(int a, int b){
	if(a==0)
		return b;
	if(a<b)
		return a;
	return b;
}

int main(){
	long long n,k;
	long long *dp;
	long long coin[101];
	long long i,j;
	long long temp;
	
	scanf("%lld %lld",&n, &k); 
	for(i=0;i<n;i++)
		scanf("%lld",&coin[i]);
	dp=(long long*)malloc(sizeof(long long)*(k+1));
	for(i=0;i<=k;i++){
		dp[i]=10001;
	}
	
	dp[0]=0;
	
	for(i=0;i<n;i++){
		for(j=coin[i];j<=k;j++){
			dp[j]=minn(dp[j],dp[j-coin[i]]+1);
		}
	}
	
	if(dp[k]==10001){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",dp[k]);

}
