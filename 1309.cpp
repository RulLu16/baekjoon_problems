#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n,i;
	long long* dp;
	
    scanf("%lld", &n);
    
    dp=(long long*)malloc(sizeof(long long)*(n+1));
    
    dp[0] = 1;
	dp[1] = 3;
    for (i = 2; i <= n; i++) {
    	dp[i] = (dp[i-1]*2 + dp[i-2]) % 9901;
	}
    printf("%lld\n", dp[n]);

    return 0;
}
