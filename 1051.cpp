#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int map[51][51];
int ans=0;

void square(int x, int y){
	for(int i=ans+1;x+i<n && y+i<m;i++){		
		if(map[x][y]==map[x+i][y+i] && map[x][y]==map[x][y+i] && map[x][y]==map[x+i][y]){
			ans=i;
		}
	}
}

int main(){	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			square(i,j);
		}
	}
	
	printf("%d\n",(ans+1)*(ans+1));
}
