#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	long long* dp; // for too big number
	int i;
	
	scanf("%d",&n);
	if(n<3){
		if(n==1){
			printf("1\n"); // if n==1 then just 1 case
			return 0;
		}
		if(n==2){
			printf("1\n"); // also if n==2 there is just 1 case.
			return 0;
		}
	}
	else{
		dp=(long long*)malloc(sizeof(long long)*n); //malloc for dp table
		dp[0]=1;
		dp[1]=1; //to calculate more than number 2
		
		for(i=2;i<n;i++){
			dp[i]=dp[i-1]+dp[i-2]; // calculate the answer when n=i;
		}
		
		printf("%llu",dp[n-1]); // print result
	}
}
