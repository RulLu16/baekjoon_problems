#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101]={0,};
int visit[101][101]={0,};
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
vector <int> area;
int result = 0; int n,m;

void paint(int x1, int y1, int x2, int y2){
	for(int i=x1;i<x2;i++){
		for(int j=y1;j<y2;j++){
			map[i][j]=1;
		}
	}
}

void dfs(int x, int y){
	result++;
	for(int i=0;i<4;i++){
		int nextX=x+dirx[i];
		int nextY=y+diry[i];
		
		if(nextX<0 || nextX>=n || nextY<0 || nextY>=m) continue;
		
		if(map[nextX][nextY]==0 && visit[nextX][nextY]==0){
			visit[nextX][nextY]=1;
			dfs(nextX, nextY);
		}
	}
}

int main(){
	int k;
	int ans=0;
	
	scanf("%d %d %d",&m,&n,&k);
	
	for(int i=0;i<k;i++){
		int x1, x2, y1, y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		
		paint(x1, y1, x2, y2);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visit[i][j]==0 && map[i][j]==0){
				ans++; result=0;
				visit[i][j]=1;
				dfs(i,j);
				area.push_back(result);
			}
		}
	}
	sort(area.begin(), area.end());
	
	printf("%d\n",ans);
	for(int i=0;i<ans;i++){
		printf("%d ",area[i]);
	}
	printf("\n");
}
