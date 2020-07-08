#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
	int x;
	int y;
	int rotate;
	int type;
}camera;

int n,m;
int map[8][8];
int copyMap[8][8];
int result=66;
int testCase;
int wallNum=0;
int cameraNum=0;
//int rNum[8]={0,};
vector <camera> cctv;

void init();
void checkType();
void type1(int, int);
void rotateNum(int);

void init(){
	testCase=n*m-wallNum-cameraNum;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			copyMap[i][j]=map[i][j];
		}
	}
}

void checkType(){
	for(int i=0;i<cameraNum;i++){
		//printf("%d\n",cctv[i].rotate);
		switch(cctv[i].type){
		case 1:
			type1(i,cctv[i].rotate);
			break;
		case 2:
			if(cctv[i].rotate==0 || cctv[i].rotate==2){
				type1(i,0);
				type1(i,2);
			}
			else{
				type1(i,1);
				type1(i,3);
			}
			break;
		case 3:
			if(cctv[i].rotate==0){
				type1(i,0);
				type1(i,3);
			}
			else if(cctv[i].rotate==1){
				type1(i,0);
				type1(i,1);
			}
			else if(cctv[i].rotate==2){
				type1(i,1);
				type1(i,2);
			}
			else{
				type1(i,2);
				type1(i,3);
			}
				break;
		case 4:
			if(cctv[i].rotate==0){
				type1(i,0);
				type1(i,3);
				type1(i,2);
				}
			else if(cctv[i].rotate==1){
				type1(i,0);
				type1(i,1);
				type1(i,3);
			}
			else if(cctv[i].rotate==2){
				type1(i,1);
				type1(i,2);
				type1(i,0);
			}
			else{
				type1(i,1);
				type1(i,2);
				type1(i,3);
			}
			break;
		case 5:
			type1(i,0);
			type1(i,1);
			type1(i,2);
			type1(i,3);
			break;
		}
	}
}

void rotateNum(int depth){
	if(depth==cameraNum){
		init();
		checkType();
		if(testCase<result){
			/*for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					printf("%d ",copyMap[i][j]);
				}
				printf("\n");
			}*/
			result=testCase;
		}
		return;
	}

	for(int i=0;i<4;i++){
		if(cctv[depth].type==5 && i>0){
			break;
		}
		cctv[depth].rotate=i;
		rotateNum(depth+1);
	}
}

void type1(int idx, int r){
	int xMove[4]={0,1,0,-1};
	int yMove[4]={1,0,-1,0};
	int x=cctv[idx].x;
	int y=cctv[idx].y;

	while(1){
		x+=xMove[r];
		y+=yMove[r];

		if(x>=n || x<0 || y>=m || y<0)
			break;
		else if(copyMap[x][y]==6)
			break;
		else if(copyMap[x][y]==0){
			copyMap[x][y]=-1;
			testCase--;
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int temp;
			scanf("%1d",&temp);

			if(temp>=1 && temp<=5){
				camera newCam;
				newCam.x=i; newCam.y=j;
				newCam.rotate=0; newCam.type=temp;
				cctv.push_back(newCam);
				cameraNum++;
			}
			else if(temp==6){
				wallNum++;
			}
			map[i][j]=temp;
		}
	}

	rotateNum(0);

	printf("%d\n",result);
}

