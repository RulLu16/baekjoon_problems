#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[65][65];
int visit[65][65]={0,};
int dx[2]={1,0};
int dy[2]={0,1};
queue <pair<int, int> > que;
int n;

void bfs(){
	while(!que.empty()){
		int x=que.front().first;
		int y=que.front().second;
		que.pop();
		
		if(x==n-1 && y==n-1){
			printf("HaruHaru\n");
			return;
		}
		
		for(int i=0;i<2;i++){
			int nextX=x+dx[i]*map[x][y];
			int nextY=y+dy[i]*map[x][y];
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=n) continue;
			
			if(visit[nextX][nextY]==0){
				visit[nextX][nextY]=1;
				que.push(make_pair(nextX, nextY));
			}
			
			if(nextX==n-1 && nextY==n-1){
				printf("HaruHaru\n");
				return;
			}
		}
	}	
	
	printf("Hing\n");
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	visit[0][0]=1;
	que.push(make_pair(0,0));
	
	bfs();
}
