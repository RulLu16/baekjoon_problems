#include <stdio.h>
#include <stdlib.h>

int main(){
	int map[16][16];
	int i,j;
	int n;
	long long dp[16][16][3]={0,};
	
	scanf("%d\n",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	}
	dp[0][1][0]=1;
	dp[0][1][1]=0;
	dp[0][1][2]=0;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<n-1 && map[i][j+1]==0){
				dp[i][j+1][0]+=dp[i][j][0]+dp[i][j][2];
			}
			if(i<n-1 && map[i+1][j]==0){
				dp[i+1][j][1]+=dp[i][j][2]+dp[i][j][1];
			}
			if(i<n-1 && j<n-1 && map[i+1][j+1]==0){
				if(map[i+1][j]==0 && map[i][j+1]==0 && map[i+1][j+1]==0){
					dp[i+1][j+1][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2];
				}
			}
		}
	}
	
	printf("%lld\n",dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2]);
	
}
