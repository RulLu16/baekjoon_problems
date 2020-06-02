#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[1024][1024];
long long dp[1024][1024];
int x1, x2, y1,y2;
int n,m;

void initMap();
long long findDp();

void initMap(){
	dp[0][0]=map[0][0];
	
	for(int i=1;i<n;i++){
		dp[0][i]=dp[0][i-1]+map[0][i];
	}
	
	for(int i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+map[i][0];
		for(int j=1;j<n;j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]+map[i][j]-dp[i-1][j-1];
		}
	}
	
/*	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
}

long long findDp(){
	long long result=dp[x2][y2];
	if(x1==0 && y1==0){
		return result;
	}

	if(x1==0){
		result-=dp[x2][y1-1];
	}
	else if(y1==0){
		result-=dp[x1-1][y2];
	}
	else{
		result-=dp[x2][y1-1];
		result-=dp[x1-1][y2];
		result+=dp[x1-1][y1-1];
	}
	return result;
}

int main(){	
	scanf("%d %d",&n, &m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}	
	
	initMap();
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		x1--; y1--; x2--; y2--;
		printf("%lld\n",findDp());
	}
}
