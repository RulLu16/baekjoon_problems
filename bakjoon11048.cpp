#include <stdio.h>
#include <stdlib.h>

int max_n(int a, int b){
	if(a<b)
		return b;
	return a;
}
int main(){
	long long n,m;
	long long** dp;
	long long** map;
	long long i,j;
	
	scanf("%lld %lld",&n,&m);
	dp=(long long**)malloc(sizeof(long long*)*n);
	map=(long long**)malloc(sizeof(long long*)*n);
	for(i=0;i<n;i++){
		dp[i]=(long long*)malloc(sizeof(long long)*m);
		map[i]=(long long*)malloc(sizeof(long long)*m);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			scanf("%lld",&map[i][j]);
	}
	dp[0][0]=map[0][0];
	
	for(i=1;i<m;i++){
		dp[0][i]=dp[0][i-1]+map[0][i];
	}
	for(i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+map[i][0];
		for(j=1;j<m;j++){
			dp[i][j]=dp[i-1][j]+map[i][j];
			dp[i][j]=max_n(dp[i][j],dp[i][j-1]+map[i][j]);
			dp[i][j]=max_n(dp[i][j],dp[i-1][j-1]+map[i][j]);
		}
	}
	
	printf("%lld\n",dp[n-1][m-1]);
}
