#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int depth;
}virus;

int n,m;
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};
int map[51][51];
int visit[51][51]={0,};
int virusVisit[51]={0,};
int virusPosition[11]={0,};
int ans=30000;
int spreadNum=0;
int maxNum=0;
queue <virus> que;
vector <pair<int, int> > twoPosition;

void init(){
	while(!que.empty()){
		que.pop();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			visit[i][j]=0;
		}
	}
	spreadNum=0;
	
	return;
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
			
			if(nextX<0 || nextX>=n || nextY<0 || nextY>=n)
				continue;
			
			if(visit[nextX][nextY]==0 && map[nextX][nextY]!=1){
				visit[nextX][nextY]=1;
				virus newOne; newOne.x=nextX;
				newOne.y=nextY; newOne.depth=depth+1;
				que.push(newOne);
				spreadNum++;
			}
			if(spreadNum==maxNum) break;
		}
		if(spreadNum==maxNum){
			if(ans>depth+1) ans=depth+1;
			break;
		}
	}
}

void dfs(int depth, int pre){
	if(depth==m){
		init();
		for(int i=0;i<m;i++){
			int x=twoPosition[virusPosition[i]].first;
			int y=twoPosition[virusPosition[i]].second;
			visit[x][y]=1;
			virus newOne; newOne.x=x;
			newOne.y=y; newOne.depth=0;
			que.push(newOne);
			spreadNum++;
		}
		if(spreadNum==maxNum){
			ans=0;
			return;
		}
		bfs();
		return;
	}
	
	for(int i=0;i<twoPosition.size();i++){
		if(i<pre) continue;
		
		if(virusVisit[i]==0){
			virusVisit[i]=1;
			virusPosition[depth]=i;
			dfs(depth+1, i);
			virusVisit[i]=0;
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&map[i][j]);
			
			if(map[i][j]==2){
				twoPosition.push_back(make_pair(i,j));
				maxNum++;
			}
			else if(map[i][j]==0){
				maxNum++;
			}
		}
	}
	
	dfs(0, 0);
	
	if(ans==30000){
		printf("-1\n");
	}	
	else{
		printf("%d\n",ans);
	}
}
