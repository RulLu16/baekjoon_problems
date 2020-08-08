#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int map[9][9];
int row[9][10]={0,};
int col[9][10]={0,};
int section[9][10]={0,};
int blankNum=0;
int findSudoku=0;
vector <pair<int, int> > blank;

void initSudoku(){
	blankNum=0;
	findSudoku=0;
	blank.clear();
	
	for(int i=0;i<9;i++){
		for(int j=0;j<10;j++){
			row[i][j]=0;
			col[i][j]=0;
			section[i][j]=0;
		}
	}
}

int checkSudoku(int x, int y, int num){
	if(row[x][num]==1) return 0;
	if(col[y][num]==1) return 0;
	if(section[x/3*3+y/3][num]==1) return 0;
	
	return 1;
}

void printSudoku(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void solveSudoku(int depth){
	if(depth==blankNum){
		printSudoku();
		findSudoku=1;
		return;
	}
	
	for(int i=1;i<=9;i++){
		if(findSudoku==1) return;
		
		int x=blank[depth].first;
		int y=blank[depth].second;
		
		if(checkSudoku(x,y,i)==1){
			map[x][y]=i;
			row[x][i]=1;
			col[y][i]=1;
			section[x/3*3+y/3][i]=1;
			solveSudoku(depth+1);
			map[x][y]=0;
			row[x][i]=0;
			col[y][i]=0;
			section[x/3*3+y/3][i]=0;
		}
		else continue;
	}
}

int main(){
	int t;
	int error=0;
	
	scanf("%d",&t);
	
	for(int k=0;k<t;k++){
		initSudoku();
		error=0;
		
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				scanf("%1d",&map[i][j]);
				
				if(map[i][j]!=0){
					if(checkSudoku(i,j,map[i][j])==1){
						row[i][map[i][j]]=1;
						col[j][map[i][j]]=1;
						section[i/3*3+j/3][map[i][j]]=1;
					}
					else error=1;
				}
				
				else{
					blankNum++;
					blank.push_back(make_pair(i,j));
				}
			}
		}
		if(error==1){
			printf("Could not complete this grid.\n\n");
			continue;
		}
		
		solveSudoku(0);
		
		if(findSudoku==0){
			printf("Could not complete this grid.\n\n");
		}
	}
	
}
