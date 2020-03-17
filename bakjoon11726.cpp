#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* dp;
	int i;
	
	scanf("%d",&n);
	
	if(n<3){
		if(n==1){
			printf("1\n"); //when n=1 there is only 1 case.
			return 0;
		}
		if(n==2){
			printf("2\n"); // also n=2, there are just 2 cases.
			return 0;
		}
	}
	else{
		dp=(int*)malloc(sizeof(int)*n); //malloc dp table
		dp[0]=1;
		dp[1]=2;
		
		for(i=2;i<n;i++){
			dp[i]=(dp[i-2]+dp[i-1])%10007; //calculate dp
		}
		printf("%d\n",dp[n-1]);
	}
}
