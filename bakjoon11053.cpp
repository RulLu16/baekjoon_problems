#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* a;
	int* dp;
	int result;
	int max;
	int i,j;
	
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	dp=(int*)malloc(sizeof(int)*n);
	
	if(n<2){
		printf("1\n");
		return 0; //if there is too little num n
	}
	else{
		dp[0]=1;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++){
			max=0;
			for(j=0;j<i;j++){
				if(a[i]>a[j] && max<dp[j]){
					max=dp[j]; //find dp
				}
			}
			dp[i]=max+1;
			
		}
		max=0;
		for(i=0;i<n;i++){
			if(max<dp[i])
				max=dp[i];
		}
			
		printf("%d\n",max); // print result
	}
}
