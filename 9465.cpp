#include <stdio.h>

int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int n,t;
	int sticker[2][100000];
	int dp[2][100000];
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		
		for(int j=0;j<2;j++){
			for(int k=0;k<n;k++)
				scanf("%d",&sticker[j][k]);
		}
		
		dp[0][0]=sticker[0][0];
		dp[1][0]=sticker[1][0];
		
		for(int j=1;j<n;j++){
			if(j-2>=0){
				dp[0][j]=sticker[0][j]+max(dp[1][j-1],dp[1][j-2]);
			}
			else{
				dp[0][j]=sticker[0][j]+dp[1][j-1];
			}
			
			if(j-2>=0){
				dp[1][j]=sticker[1][j]+max(dp[0][j-1],dp[0][j-2]);
			}
			else{
				dp[1][j]=sticker[1][j]+dp[0][j-1];
			}
		}	
		
		printf("%d\n",max(dp[0][n-1], dp[1][n-1]));		
	}
}
