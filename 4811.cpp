#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
long long result=0;
long long dp[31][31]={0,};

long long dfs(int w, int h){
	if(dp[w][h]!=0){
		return dp[w][h];
	}
	
	if(w==0){
		return 1;
	}
	
	dp[w][h]=dfs(w-1, h+1);
	if(h>0){
		dp[w][h]+=dfs(w, h-1);
	}
	
	return dp[w][h];
}

int main(){	

	while(1){
		scanf("%d",&n);
		
		if(n==0){
			break;
		}
		
		result=dfs(n,0);
		printf("%lld\n",result);
	}
}
