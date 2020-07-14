#include <stdio.h>

int Xblocks[13][4]={{0,1,2,2},{0,0,0,1},{0,0,1,2},{0,1,1,1},{0,1,1,2},{0,0,1,1},{0,0,0,1},{0,1,1,2},{0,1,1,1},{0,1,1,2},{0,1,2,3},{0,0,0,0},{0,0,1,1}};
int Yblocks[13][4]={{0,0,0,1},{0,1,2,0},{0,1,1,1},{0,0,-1,-2},{0,0,1,1},{0,-1,-1,-2},{0,1,2,1},{0,0,-1,0},{0,0,-1,1},{0,0,1,0},{0,0,0,0},{0,1,2,3},{0,1,0,1}};
int map[500][500];
int n,m;
int result=0;

void calculateSum(int x, int y, int form, int sym){
	int sum=0;
	
	for(int i=0;i<4;i++){
		int nextX=x+Xblocks[form][i];
		int nextY;
		if(sym==0) nextY=y+Yblocks[form][i];
		else nextY=y-Yblocks[form][i];
		//printf("%d %d\n",nextX, nextY);
		
		if(nextX>=n || nextX<0 || nextY>=m || nextY<0){
			break;
		}
		
		sum+=map[nextX][nextY];	
	}
	
	if(sum>result) result=sum;
	
	return;
}

void tetris(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<13;k++){
				calculateSum(i,j,k,0);
				
				if(k<6){
					calculateSum(i,j,k,1);
				}
			}
		}
	}
	
	return;
}

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	tetris();
	
	printf("%d\n",result);
}
