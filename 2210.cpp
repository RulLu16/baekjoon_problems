#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int x_move[4]={0,1,0,-1};
int y_move[4]={1,0,-1,0};
int map[5][5]={0,};
set <int> result;

void dfs(int x, int y, int depth, int str){
	int next_x;
	int next_y;
	
	if(depth==6){
		result.insert(str);
		return;
	}
	
	for(int i=0;i<4;i++){
		next_x=x+x_move[i];
		next_y=y+y_move[i];
		
		if(next_x<0 || next_x>=5 || next_y<0 || next_y>=5){
			continue;
		}
		
		dfs(next_x, next_y, depth+1, str*10+map[next_x][next_y]);
	}
	
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dfs(i,j,0,0);
		}
	}
	
	printf("%d\n",result.size());	
}
