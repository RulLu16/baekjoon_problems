#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
	int i;
	int j;
	int k;
	int count;
}que;

int originMaze[5][5][5]={0,};
int rotateMaze[5][5][5];
int designMaze[5][5][5];
int rNum[5]={0,};
int fNum[5]={0,};
int fVisit[5]={0,};
int mazeVisit[5][5][5]={0,};
int result=2000;
int iMove[6]={0,0,0,0,1,-1};
int jMove[6]={0,1,0,-1,0,0};
int kMove[6]={1,0,-1,0,0,0};
int startPoint[4][3]={{0,0,0},{0,0,4},{0,4,4},{0,4,0}};
int endPoint[4][3]={{4,4,4},{4,4,0},{4,0,0},{4,0,4}};
que movement[125];

void rotateNum(int);
void rotate(int);
void init();
void floorNum(int);
void placeMaze();
void bfs();

void rotateNum(int depth){
	if(depth==5){
		init();
		for(int i=0;i<5;i++){
			for(int j=0;j<rNum[i];j++){
				rotate(i);
			}
		}
		floorNum(0);
		return;
	}
		
	for(int i=0;i<4;i++){
		rNum[depth]=i;
		rotateNum(depth+1);
	}
}

void rotate(int idx){	
	int copy[5][5];
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			copy[i][j]=rotateMaze[idx][i][j];
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			rotateMaze[idx][i][j]=copy[4-j][i];
		}
	}	
}

void init(){
	for(int i=0;i<5;i++){
		fVisit[i]=0;
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				rotateMaze[i][j][k]=originMaze[i][j][k];
			}
		}
	}
}

void floorNum(int depth){
	if(depth==5){
		placeMaze();
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++){
					mazeVisit[i][j][k]=0;
				}
			}
		}
		bfs();
		return;
	}
	
	for(int i=0;i<5;i++){
		if(fVisit[i]==0){
			fVisit[i]=1;
			fNum[depth]=i;
			floorNum(depth+1);		
			fVisit[i]=0;	
		}
	}
}

void placeMaze(){
	for(int i=0;i<5;i++){
		int position=fNum[i];
		
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				designMaze[position][j][k]=rotateMaze[i][j][k];
			}
		}
	}
}

void bfs(){
	int front=0;
	int end=0;
	
	for(int start=0;start<4;start++){
		front=0; end=0;
		int sI=startPoint[start][0];
		int sJ=startPoint[start][1];
		int sK=startPoint[start][2];
		
		if(designMaze[sI][sJ][sK]!=1){
			continue;
		}
		
		mazeVisit[sI][sJ][sK]=1;
		movement[0].i=sI;
		movement[0].j=sJ;
		movement[0].k=sK;
		movement[0].count=0;
		end++;
		
		while(front!=end){
			int mI=movement[front].i;
			int mJ=movement[front].j;
			int mK=movement[front].k;
			int count=movement[front].count;
			
			if(mI==endPoint[start][0] && mJ==endPoint[start][1] && mK==endPoint[start][2]){
				if(result>count)
					result=count;
				break;
			}
			
			for(int temp=0;temp<6;temp++){
				int nextI=mI+iMove[temp];
				int nextJ=mJ+jMove[temp];
				int nextK=mK+kMove[temp];
				
				if(nextI<0 || nextI>=5 || nextJ<0 || nextJ>=5 || nextK<0 || nextK>=5){
					continue;
				}
				
				if(designMaze[nextI][nextJ][nextK]==1 && mazeVisit[nextI][nextJ][nextK]==0){
					movement[end].i=nextI;
					movement[end].j=nextJ;
					movement[end].k=nextK;
					movement[end].count=count+1;
					mazeVisit[nextI][nextJ][nextK]=1;
					end++;
				}
			}
			front++;
		}
	}
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				scanf("%1d",&originMaze[i][j][k]);
				//designMaze[i][j][k]=originMaze[i][j][k];
			}
		}
	}
	
	rotateNum(0);
	
	if(result==2000){
		printf("-1\n");
	}
	else
		printf("%d\n",result);
}
