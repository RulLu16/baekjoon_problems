#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	long long p[1001];
	long long dp[1001];
	int i,j;
	long long max;
	
	scanf("%d",&n);
	if(n==0){
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	dp[0]=0;
	
	for(i=1;i<=n;i++){
		max=p[i];
		for(j=1;j<=i/2;j++){
			if(max<dp[j]+dp[i-j])
				max=dp[j]+dp[i-j];
		}
		dp[i]=max;
	}
	printf("%d\n",max);
	
}
