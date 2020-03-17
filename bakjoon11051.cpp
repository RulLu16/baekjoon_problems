#include <stdio.h>
#include <stdlib.h>

//long long ihang(long long, long long);

int main(){
	long long n,k;
	long long i,j;
	long long result;
	long long** dp;
	
	scanf("%lld %lld",&n,&k);
	if(k==0){
		printf("1\n");
		return 0;
	}
	
	dp=(long long**)malloc(sizeof(long long*)*(n+1));
	
	for(i=0;i<=n;i++){
		dp[i]=(long long*)malloc(sizeof(long long)*(n+1));
	}
	for(i=0;i<=n;i++){
		dp[i][0]=1;
	}

	for(i=0;i<=n;i++){
		dp[i][i]=1;
	}
	
	for(i=0;i<=n;i++){
		for(j=1;j<i;j++){
			dp[i][j]=((dp[i-1][j-1]%10007)+(dp[i-1][j]%10007))%10007;
		}
	}
	
	printf("%lld\n",dp[n][k]);
	
}


