#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* dp;
	int i;
	
	scanf("%d",&n);
	
	if(n<3){
		if(n==1){
			printf("1\n");
			return 0;
		}
		if(n==2){
			printf("3\n");
			return 0;
		}
	}
	else{
		dp=(int*)malloc(sizeof(int)*n);
		dp[0]=1;
		dp[1]=3;
		
		for(i=2;i<n;i++){
			dp[i]=(dp[i-2]*2+dp[i-1])%10007;
		}
		printf("%d\n",dp[n-1]);
	}
}
