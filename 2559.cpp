#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	vector <int> deg;
	vector <int> dp(100000);
	int n,k,sum;
	int max_val=0;
	
	scanf("%d %d",&n,&k);
	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		deg.push_back(temp);
	}
	
	sum=0;
	for(int i=0;i<k;i++){
		sum+=deg[i];
	}
	dp[0]=sum;
	max_val=dp[0];
	
	for(int i=1;i<=n-k;i++){
		dp[i]=dp[i-1]-deg[i-1]+deg[i+k-1];
		
		if(dp[i]>max_val){
			max_val=dp[i];
		}
	}
	
	printf("%d\n",max_val);
}
