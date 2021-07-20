#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;
vector<vector<char> > map;
vector<vector<int> > visit;
vector<vector<int> > dp;
int xmove[4] = {0,1,0,-1};
int ymove[4] = {1,0,-1,0};
int max_v = 0;
int flag = 0;

int max_cal(int a, int b){
	if(a<b) return b;
	return a;
}

void dfs(int count, int x, int y){
	if(flag == 1) return;
	if(count > max_v) max_v = count;
	
	for(int i=0;i<4;i++){
		int nextx = x + (xmove[i] * (map[x][y] - '0'));
		int nexty = y + (ymove[i] * (map[x][y] - '0'));
		
		if(nextx>=n || nextx<0 || nexty<0 || nexty>=m) 
			continue;
		
		if(visit[nextx][nexty] == 1){
			flag = 1;
			return;
		}
		
		if(map[nextx][nexty] != 'H' && dp[nextx][nexty] < count + 1){
			dp[nextx][nexty] = count + 1;				 
			visit[nextx][nexty] = 1;
			dfs(count + 1, nextx, nexty);
			visit[nextx][nexty] = 0;
		}
	}
	
	return;
	
}

int main(){
	scanf("%d %d", &n, &m);
	getchar();
	
	map.assign(n, vector<char>(m, 0));
	visit.assign(n, vector<int>(m, 0));
	dp.assign(n, vector<int>(m, -1));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			
			scanf("%1c",&tmp);
			map[i][j] = tmp;
		}
		getchar();
	}
	
	visit[0][0] = 1;
	dp[0][0] = 1;	
	dfs(1, 0, 0);
	
	if(flag == 0)
		printf("%d\n", max_v);
	else
		printf("-1\n");
}
