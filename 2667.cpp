#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int visit[25][25]={0,};
int map[25][25]={0,};
int ans=0;
int n;
vector <int> result;
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};

void dfs(int x, int y){
	ans++;
	visit[x][y]=1;
	for(int i=0;i<4;i++){
		int xNext=x+xMove[i];
		int yNext=y+yMove[i];
		
		if(xNext<0 || xNext>=n || yNext<0 || yNext>=n){
			continue;
		}
		
		if(visit[xNext][yNext]==0 && map[xNext][yNext]==1){
			dfs(xNext, yNext);
		}
	}
	return;
}

int main(){	
	int num=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==1 && visit[i][j]==0){
				ans=0;
				dfs(i,j);
				result.push_back(ans);
				num++;
			}
		}
	}
	sort(result.begin(),result.end());
	
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%d\n",result[i]);
	}
}
