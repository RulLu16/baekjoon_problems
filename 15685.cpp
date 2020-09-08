#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101]={0,};
int xMove[4]={0,-1,0,1};
int yMove[4]={1,0,-1,0};
int x,y,d,g;

void curve(){
	vector <int> stack;
	int nextX=x; int nextY=y;
	
	stack.push_back(d);
			
	for(int i=0;i<g;i++){
		int size=stack.size();
		
		for(int j=size-1;j>=0;j--){
			int dir=(stack[j]+1)%4;
			
			stack.push_back(dir);
		}
	}
	
	map[x][y]=1;
	for(int i=0;i<stack.size();i++){
		nextX+=xMove[stack[i]];
		nextY+=yMove[stack[i]];
		
		map[nextX][nextY]=1;
	}
}

void checkSquare(){
	int ans=0;
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			int base = map[i][j];
			if(base==0) continue;
			
			if(base==map[i+1][j] && base==map[i][j+1] && base==map[i+1][j+1]){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){		
		scanf("%d %d %d %d",&y,&x,&d,&g);
		curve();
	}
	
	checkSquare();
}
