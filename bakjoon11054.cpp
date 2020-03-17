#include <stdio.h>
#include <stdlib.h>

int max_item(int a, int b){
	if(a<b)
		return b;
	else
		return a;
}

int main(){
	int n;
	int a[1001];
	int i,j;
	int dp[1001][2]={0,};
	int max=0;
	int temp;
	
	scanf("%d",&n);
	
	if(n==0){
		printf("0\n");
		return 0;
	}
	if(n==1){
		printf("1\n");
		return 0;
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dp[0][0]=1;
	dp[0][1]=1;
	
	for(i=0;i<n;i++){
		dp[i][0]=1;
		dp[i][1]=1;
		for(j=0;j<i;j++){
			if(a[i]<a[j]){
				temp=max_item(dp[j][0]+1,dp[j][1]+1);
				dp[i][0]=max_item(dp[i][0],temp);
			}
			else if(a[i]>a[j]){
				dp[i][1]=max_item(dp[i][1],dp[j][1]+1);
			}
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<2;j++){
			if(max<dp[i][j])
				max=dp[i][j];
		}
	}
	
	printf("%d\n",max);
	
}
