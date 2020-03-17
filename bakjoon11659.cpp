#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n;
	long long m;
	long long* dp;
	long long* num;
	long long i,j;
	long long start, end;
	
	scanf("%lld %lld",&n,&m);
	dp=(long long*)malloc(sizeof(long long)*n);
	num=(long long*)malloc(sizeof(long long)*n);
	scanf("%lld",&num[0]);
	dp[0]=num[0];
	for(i=1;i<n;i++){
		scanf("%lld",&num[i]);
		dp[i]=dp[i-1]+num[i];
	}
	
	for(i=0;i<m;i++){
		scanf("%lld %lld",&start,&end);
		printf("%lld\n",dp[end-1]-dp[start-1]+num[start-1]);
	}
}
