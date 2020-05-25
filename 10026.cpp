#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int ns_result=0;
int ps_result=0;
char map[100][100]={0,}; 
int normal_visit[100][100]={0,};
int problem_visit[100][100]={0,};

void normal_dfs(int x, int y){
	
	if(y+1<n && map[x][y+1]==map[x][y] && normal_visit[x][y+1]==0){
		normal_visit[x][y+1]=1;
		normal_dfs(x,y+1);		
	}	
	if(x+1<n && map[x+1][y]==map[x][y] && normal_visit[x+1][y]==0){
		normal_visit[x+1][y]=1;
		normal_dfs(x+1,y);		
	}
	if(y-1>=0 && map[x][y-1]==map[x][y] && normal_visit[x][y-1]==0){
		normal_visit[x][y-1]=1;
		normal_dfs(x,y-1);		
	}
	if(x-1>=0 && map[x-1][y]==map[x][y] && normal_visit[x-1][y]==0){
		normal_visit[x-1][y]=1;
		normal_dfs(x-1,y);		
	}
	
	return;
}

void problem_dfs(int x, int y){
	if(y+1<n && problem_visit[x][y+1]==0){
		if(map[x][y+1]==map[x][y] || (map[x][y]=='R' && map[x][y+1]=='G') || (map[x][y]=='G' && map[x][y+1]=='R')){
			problem_visit[x][y+1]=1;
			problem_dfs(x,y+1);	
		}
	}	
	if(x+1<n && problem_visit[x+1][y]==0){
		if(map[x+1][y]==map[x][y] || (map[x][y]=='R' && map[x+1][y]=='G') || (map[x][y]=='G' && map[x+1][y]=='R')){
			problem_visit[x+1][y]=1;
			problem_dfs(x+1,y);	
		}
	}
	if(y-1>=0 && problem_visit[x][y-1]==0){
		if(map[x][y-1]==map[x][y] || (map[x][y]=='R' && map[x][y-1]=='G') || (map[x][y]=='G' && map[x][y-1]=='R')){
			problem_visit[x][y-1]=1;
			problem_dfs(x,y-1);	
		}		
	}
	if(x-1>=0 && problem_visit[x-1][y]==0){
		if(map[x-1][y]==map[x][y] || (map[x][y]=='R' && map[x-1][y]=='G') || (map[x][y]=='G' && map[x-1][y]=='R')){
			problem_visit[x-1][y]=1;
			problem_dfs(x-1,y);	
		}	
	}
	
	return;	
}

int main(){	
	scanf("%d",&n);
	getchar();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1c",&map[i][j]);
		}
		getchar();
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(normal_visit[i][j]==0){
				normal_visit[i][j]=1;
				normal_dfs(i,j);
				ns_result++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(problem_visit[i][j]==0){
				problem_visit[i][j]=1;
				problem_dfs(i,j);
				ps_result++;
			}
		}
	}
	
	printf("%d %d\n",ns_result, ps_result);	
}
