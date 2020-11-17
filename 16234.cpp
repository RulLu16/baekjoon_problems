#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int n,l,r;
queue <pair<int, int> > bfs_que;
queue <pair<int, int> > move_que;
int map[51][51]={0,};
int visit[51][51]={0,};
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visit[i][j]=0;
		}
	}
}

void moving_people(int block, int population){
	int people = population / block;
	
	while(!move_que.empty()){
		map[move_que.front().first][move_que.front().second] = people;
		move_que.pop();
	}
}

int bfs(){
	int block = 0;
	int population = 0;
	
	while(!bfs_que.empty()){
		int x = bfs_que.front().first;
		int y = bfs_que.front().second;
		bfs_que.pop();
		
		block++; 
		population += map[x][y];
		
		for(int i=0;i<4;i++){
			int nextX = x+xMove[i];
			int nextY = y+yMove[i];
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=n) continue;
			
			int minus = abs(map[x][y] - map[nextX][nextY]);
			
			if(minus >= l && minus <=r && visit[nextX][nextY]==0){
				bfs_que.push(make_pair(nextX, nextY));
				move_que.push(make_pair(nextX, nextY));
				visit[nextX][nextY]=1;				
			}
		}
	}
	
	if(block>1){
		moving_people(block, population);
		return 1;
	}	
	else{
		move_que.pop();
		return 0;
	}
}

int main(){
	int ans = 0;
	
	scanf("%d %d %d",&n,&l,&r);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	while(1){
		int is_moving=0;
		init();
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visit[i][j]==0){
					visit[i][j]=1;
					bfs_que.push(make_pair(i,j));
					move_que.push(make_pair(i,j));
					is_moving+=bfs();
				}
			}
		}
		
		if(is_moving>0) ans++;
		else if(is_moving == 0) break;
	}
	
	printf("%d\n",ans);
}
