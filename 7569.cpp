#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int z;
	int day;
}tomato;

int n,m,h;
int ripped=0;
int maxRip;
int box[101][101][101];
int visit[101][101][101];
int xMove[6]={0,1,0,-1,0,0};
int yMove[6]={1,0,-1,0,0,0};
int zMove[6]={0,0,0,0,1,-1};
queue <tomato> que;

void addTomato(int x, int y, int z, int day){
	visit[x][y][z]=1;
	tomato newOne;
	newOne.x=x; newOne.y=y;
	newOne.z=z; newOne.day=day+1;
	que.push(newOne);
	
	return;
}

void bfs(){	
	while(!que.empty()){
		int x=que.front().x;
		int y=que.front().y;
		int z=que.front().z;
		int day=que.front().day;
		que.pop();
	
		for(int i=0;i<6;i++){
			int nextX=x+xMove[i];
			int nextY=y+yMove[i];
			int nextZ=z+zMove[i];
			
			if(nextX<0 || nextX>=m || nextY<0 || nextY>=n || nextZ<0 || nextZ>=h){
				continue;
			}
			
			if(visit[nextX][nextY][nextZ]==0 && box[nextX][nextY][nextZ]==0){
				if(++ripped==maxRip){
					printf("%d\n",day+1);
					return;
				}
				addTomato(nextX, nextY, nextZ, day);
			}
		}
	}
	
	printf("-1\n");
	return;
}

int main(){	
	scanf("%d %d %d",&n,&m,&h);
	maxRip=n*m*h;
	
	for(int k=0;k<h;k++){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&box[i][j][k]);
				
				if(box[i][j][k]==1){
					ripped++;
					addTomato(i,j,k,-1);
				}
				else if(box[i][j][k]==-1){
					maxRip--;
				}
			}
		}
	}
	
	if(ripped==maxRip){
		printf("0\n");
		return 0;
	}
	
	bfs();
}
