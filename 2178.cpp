#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int length;
}block;

int n,m;
queue <block> que;
int maze[101][101]={0,};
int visit[101][101]={0,};
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};

void bfs(){	
	while(!que.empty()){
		int x=que.front().x;
		int y=que.front().y;
		int length=que.front().length;
		que.pop();
		//printf("%d %d %d\n",x,y,length);
		
		for(int i=0;i<4;i++){
			int nextX=x+xMove[i];
			int nextY=y+yMove[i];
			
			if(nextX==n-1 && nextY==m-1){
				printf("%d\n",length+1);
				return;
			}
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=m){
				continue;
			}
			
			if(visit[nextX][nextY]==0 && maze[nextX][nextY]==1){
				block newOne;
				newOne.x=nextX; newOne.y=nextY;
				newOne.length=length+1;
				que.push(newOne);
				visit[nextX][nextY]=1;
			}
		}
	}
}

int main(){
	block newOne;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&maze[i][j]);
		}
	}
	
	visit[0][0]=1;
	newOne.x=0; newOne.y=0;
	newOne.length=1;
	que.push(newOne);
	
	bfs();
}
