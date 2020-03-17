#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    long long dp[101][11]={0,};
    long long sum=0;
	int i,j;
    // dp[N][L] = dp[N - 1][L - 1] + dp[N - 1][L + 1]
    // 길이 N, 마지막 숫자가 L일 경우
 	scanf("%d",&n);
 	
    for (i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        for (j = 1; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
 
    for (i = 0; i < 10; i++) {
        sum += dp[n][i];
        //sum%=1000000000;
    }
    
    printf("%lld",sum%1000000000);
    printf("\n");
}



