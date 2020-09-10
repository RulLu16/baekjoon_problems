#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[101][101];
int visit[101][101]={0,};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int rain;
int ans=0;
queue <pair<int, int> > que;

void init(){
	while(!que.empty()) que.pop();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visit[i][j]=0;
		}
	}
}

void bfs(){
	while(!que.empty()){
		int x=que.front().first;
		int y=que.front().second;
		que.pop();
		
		for(int i=0;i<4;i++){
			int nextX=x+dx[i];
			int nextY=y+dy[i];
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=n) continue;
			
			if(map[nextX][nextY]>rain && visit[nextX][nextY]==0){
				visit[nextX][nextY]=1;
				que.push(make_pair(nextX,nextY));
			}
		}
	}
}

void sink(){
	int result=0;
	init();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]>rain && visit[i][j]==0){
				visit[i][j]=1;
				que.push(make_pair(i,j));
				bfs();
				result++;
			}
		}
	}
	
	if(result>ans) ans=result;
}

int main(){
	int maxH=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
			
			if(maxH<map[i][j]) maxH=map[i][j];
		}
	}
	
	for(int i=0;i<=maxH; i++){
		rain=i;
		sink();
	}
	
	printf("%d\n",ans);
}
