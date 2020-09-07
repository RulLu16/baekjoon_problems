#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int depth;
}square;

queue <square> que;
int n,m;
int h,w;
int endX, endY;
int map[1001][1001];
int visit[1001][1001]={0,};
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};

int checkMove(int x, int y){
	for(int i=x;i<x+h;i++){
		if(i<0 || i>=n || y+w-1>=m) return 1;
		
		if(map[i][y]==1 || map[i][y+w-1]==1) return 1;
	}
	for(int i=y;i<y+w;i++){
		if(i<0 || i>=m || x+h-1>=n) return 1;
		
		if(map[x][i]==1 || map[x+h-1][i]==1) return 1;
	}
	
	return 0;
}

void bfs(){
	while(!que.empty()){
		int x=que.front().x;
		int y=que.front().y;
		int depth=que.front().depth;
		que.pop();
		
		for(int i=0;i<4;i++){
			int nextX=x+xMove[i];
			int nextY=y+yMove[i];
			
			if(checkMove(nextX, nextY)==1) continue;
			
			if(nextX==endX && nextY==endY){
				printf("%d\n",depth+1);
				return;
			}
			
			if(visit[nextX][nextY]==0){
				square newOne; newOne.x=nextX;
				newOne.y=nextY; newOne.depth=depth+1;
				que.push(newOne);
				visit[nextX][nextY]=1;
			}
		}
	}
	printf("-1\n");
}

int main(){
	int startX, startY;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	scanf("%d %d",&h,&w);
	scanf("%d %d %d %d",&startX, &startY, &endX, &endY);
	startX--; startY--; endX--; endY--;
	
	if(startX==endX && startY==endY){
		printf("0\n");
		return 0;
	}
	
	square newOne; newOne.x=startX;
	newOne.y=startY; newOne.depth=0;
	que.push(newOne);
	visit[startX][startY]=1;
	
	bfs();
}
