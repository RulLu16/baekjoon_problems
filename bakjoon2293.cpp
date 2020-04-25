#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,n,k;
	int dp[10001]={0,};
	int coin[101]={0,};
	
	scanf("%d %d",&n, &k);
	
	for(i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}	
	
	dp[0]=1;
	
	for(i=0;i<n;i++){
		for(j=coin[i];j<=k;j++){
			if(j-coin[i]>=0){
				dp[j]+=dp[j-coin[i]];
			}
		}
	}
	
	printf("%d\n",dp[k]);
}
