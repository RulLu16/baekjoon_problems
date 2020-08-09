#include <stdio.h>

using namespace std;

int main(){
	int n,k;
	int dp[201][201]={0,};
	
	scanf("%d %d",&n,&k);
	
	for(int i=1;i<=k;i++){
		dp[0][i]=1;
	}
	
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		dp[i][1]=1;
		
		for(int j=2;j<=k;j++){
			for(int s=0;s<=i;s++){
				dp[i][j]=(dp[i][j]+dp[i-s][j-1])%1000000000;
			}
		}
	}
	
	printf("%d\n",dp[n][k]);	
}
