#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int r,c;
int board[21][21]={0,};
int boardVisit[21][21]={0,};
int alphaVisit[26]={0,};
int xMove[4]={0,1,0,-1};
int yMove[4]={1,0,-1,0};
int result=0;

void dfs(int x, int y, int depth){
	if(depth==26){
		result=26;
		return;
	}
	
	for(int i=0;i<4;i++){
		int nextX=x+xMove[i];
		int nextY=y+yMove[i];
		
		if(nextX<0 || nextX>=r || nextY<0 || nextY>=c)
			continue;
		
		if(boardVisit[nextX][nextY]==0 && alphaVisit[board[nextX][nextY]]==0){
			boardVisit[nextX][nextY]=1;
			alphaVisit[board[nextX][nextY]]=1;
			dfs(nextX, nextY, depth+1);
			boardVisit[nextX][nextY]=0;
			alphaVisit[board[nextX][nextY]]=0;
		}
	}
	
	if(depth>result) result=depth;
}

int main(){
	scanf("%d %d",&r,&c);
	getchar();
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char temp;
			scanf("%1c",&temp);
			board[i][j]=(int)temp-'A';
		}
		getchar();
	}
	
	alphaVisit[board[0][0]]=1;
	boardVisit[0][0]=1;
	dfs(0,0,1);
	
	printf("%d\n",result);
}
