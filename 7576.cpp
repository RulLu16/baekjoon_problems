#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int day;
}tomato;

int n,m;
int ripped=0;
int maxRip;
int box[1001][1001];
int visit[1001][1001];
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};
queue <tomato> que;

void bfs(){	
	while(!que.empty()){
		int x=que.front().x;
		int y=que.front().y;
		int day=que.front().day;
		que.pop();
		//printf("%d %d %d\n",x,y,day);
	
		for(int i=0;i<4;i++){
			int nextX=x+xMove[i];
			int nextY=y+yMove[i];
			
			if(nextX<0 || nextX>=m || nextY<0 || nextY>=n){
				continue;
			}
			
			if(visit[nextX][nextY]==0 && box[nextX][nextY]==0){
				if(++ripped==maxRip){
					printf("%d\n",day+1);
					return;
				}
				visit[nextX][nextY]=1;
				tomato newOne;
				newOne.x=nextX; newOne.y=nextY;
				newOne.day=day+1;
				que.push(newOne);
			}
		}
	}
	
	printf("-1\n");
	return;
}

int main(){	
	scanf("%d %d",&n,&m);
	maxRip=n*m;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&box[i][j]);
			
			if(box[i][j]==1){
				ripped++;
				visit[i][j]=1;
				tomato newOne;
				newOne.x=i; newOne.y=j;
				newOne.day=0;
				que.push(newOne);
			}
			else if(box[i][j]==-1){
				maxRip--;
			}
		}
	}
	
	if(ripped==maxRip){
		printf("0\n");
		return 0;
	}
	
	bfs();
}
