#include <stdio.h>
#include <stdlib.h>

typedef struct

{
	int y, x;
}Dir;

Dir moveDir[3] = { { -1, 1 }, {0, 1}, {1, 1} };
char visited[10000][500];
char graph[10000][500];
int r,c;

bool dfs(int y, int x){
    visited[y][x] = true;

    if (x == c - 1)
        return true;
        
    for (int i = 0; i < 3; i++){
        int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		
        if(0<=nextY && nextY < r && 0<=nextX && nextX < c){
			if (!visited[nextY][nextX] && graph[nextY][nextX] == '.'){
				bool flag = dfs(nextY, nextX);
					if (flag)
						return flag;
                }
            }
        }
        
        return false;
}

int main(){
	int i,j;
	int result=0;
	char temp;
	
	scanf("%d %d\n",&r,&c);
	
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			scanf("%1c",&graph[i][j]);
		scanf("%1c",&temp);
	}
	
	for(i=0;i<r;i++){
		result=result+dfs(i,0);
	}
	
	printf("%d\n",result);
}
