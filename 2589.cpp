#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int depth;
}treasure;

int n,m;
int map[51][51];
int visit[51][51]={0,};
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};
int ans=0;
vector <pair<int, int> > land;
queue <treasure> que;

void init(){
	while(!que.empty()){
		que.pop();
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j]=0;
		}
	}	
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
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=m)
				continue;
			
			if(visit[nextX][nextY]==0 && map[nextX][nextY]==1){
				visit[nextX][nextY]=1;
				treasure newOne; newOne.x=nextX;
				newOne.y=nextY; newOne.depth=depth+1;
				que.push(newOne);
				
				if(depth+1>ans) ans=depth+1;
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	getchar();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char temp;
			scanf("%1c",&temp);
			
			if(temp=='W') map[i][j]=0;
			else {
				map[i][j]=1;
				land.push_back(make_pair(i,j));
			}
		}
		getchar();
	}
	
	for(int i=0;i<land.size();i++){
		init();
		visit[land[i].first][land[i].second]=1;
		treasure newOne; newOne.x=land[i].first;
		newOne.y=land[i].second; newOne.depth=0;
		que.push(newOne);
		bfs();
	}
	
	printf("%d\n",ans);
}
