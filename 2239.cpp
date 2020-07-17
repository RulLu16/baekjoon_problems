#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[9][9];
int row[9][10]={0,};
int col[9][10]={0,};
int section[9][10]={0,};
int blankNum=0;
vector <pair<int, int> > blank;

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
	return;
}

void solveSudoku(int depth){
	if(depth==blankNum){
		printSudoku();
		exit(0);
	}
	
	for(int i=1;i<=9;i++){
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
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			scanf("%1d",&map[i][j]);
			row[i][map[i][j]]=1;
			col[j][map[i][j]]=1;
			section[i/3*3+j/3][map[i][j]]=1;
			
			if(map[i][j]==0){
				blankNum++;
				blank.push_back(make_pair(i,j));
			}
		}
	}
	
	solveSudoku(0);
}
