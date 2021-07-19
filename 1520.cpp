#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long result=0;

int map[501][501];
int visit[501][501]={0,};
long long dp[501][501]={0,};

int moveX[4]={0,1,0,-1};
int moveY[4]={1,0,-1,0};

int dfs(int x, int y){
	if(x==m-1 && y==n-1){
		return 1;
	}
	if(visit[x][y]==1){
		return dp[x][y];
	}
	
	for(int i=0;i<4;i++){
		int nextX=x+moveX[i];
		int nextY=y+moveY[i];
		
		if(nextX<0 || nextX>=m || nextY<0 || nextY>=n){
			continue;
		}
		if(map[x][y]>map[nextX][nextY]){
			visit[x][y]=1;
			dp[x][y]+=dfs(nextX, nextY);
		}
	}
	return dp[x][y];
}

int main(){
	scanf("%d %d",&m, &n);
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	dfs(0, 0);	
	printf("%lld",dp[0][0]);
}

