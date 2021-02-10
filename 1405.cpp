#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int percent[4];
int visit[30][30] = {0,};
vector <int> dir;
int xmove[4] = {0, 0, 1, -1};
int ymove[4] = {1, -1, 0, 0};
double result = 0;

double calculate_percent(){
	double per = 1;
	
	for(int i=0;i<n;i++){
		per *= double(percent[dir[i]])*0.01;
	}
	
	return per;
}

void dfs(int depth, int x, int y){
	if(depth == n){
		result += calculate_percent();
		
		return;
	}
	
	for(int i=0;i<4;i++){
		int nextx = x + xmove[i];
		int nexty = y + ymove[i];
		
		if(visit[nextx][nexty] == 0){
			dir[depth] = i;
			visit[nextx][nexty] = 1;
			dfs(depth+1, nextx, nexty);
			visit[nextx][nexty] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<4;i++)
		scanf("%d", &percent[i]);
	
	dir.assign(n, 0);
	visit[15][15] = 1;
	dfs(0, 15, 15);	
	
	printf("%.10lf\n", result);
}
