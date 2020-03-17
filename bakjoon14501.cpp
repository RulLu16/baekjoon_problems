#include <stdio.h>
#include <stdlib.h>

int max_n(int a, int b){
	if(a<b)	
		return b;
		
	return a;
}

int main(){
	int n;
	int time[1000]={0,};
	int price[1000]={0,};
	int dp[1000]={0,};
	int i,j;
	int temp;
	
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		scanf("%d %d",&time[i],&price[i]);
	}
	
	for(i=n;i>0;i--){
		temp=i+time[i];
		if(temp>n+1){
			dp[i]=dp[i+1];
		}
		else{
			dp[i]=max_n(dp[i+1],dp[temp]+price[i]);
		}
	}
	
	printf("%d\n",dp[1]);
}
