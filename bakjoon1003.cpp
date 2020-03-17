#include <stdio.h>
#include <stdlib.h>

int dp[45]={1,1,};

int fibonacci(int n) {
    if (n <= 1) {
        return dp[n];
    } 
    else {
        if(dp[n]>0)
        	return dp[n];
    }
    return dp[n]=fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int t;
	int num;
	int i;
	
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&num);
		if(num==0)
			printf("1 0\n");
		else if(num==1)
			printf("0 1\n");
		else{
			fibonacci(num);
			printf("%d %d\n",dp[num-2],dp[num-1]);
		}
		
		//printf("%d %d\n",one,two);
	}
}
