#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* dp;
	int i;
	
	scanf("%d",&n);
	dp=(int*)malloc(sizeof(int)*n);
	
	if(n==1){
		printf("9\n");
		return 0;
	}
	
	dp[0]=9;

	for(i=1;i<n;i++){
		dp[i]=((dp[i-1]-1)*2+1)%1000000000; // have *2 (former number-1)+1
	}
	
	printf("%d\n",dp[n-1]);
}
