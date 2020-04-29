#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a>b){
		return a;
	}
	
	return b;
}

int main(){
	int n,i,j;
	int a[1001];
	int dp[1001];
	int max_result=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	dp[0]=a[0];
	max_result=a[0];
	
	for(i=1;i<n;i++){
		dp[i]=a[i];
		for(j=i-1;j>=0;j--){
			if(a[j]<a[i]){
				dp[i]=max(dp[i], dp[j]+a[i]);
			}
		}
		max_result=max(max_result, dp[i]);
	}
	
	printf("%d\n",max_result);
}
