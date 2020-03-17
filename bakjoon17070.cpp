#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	int dir; //0=right 1=down 2=left down
}cor;

cor que[257];
int n;
int map[16][16];
int mark[16][16]={0,};

int main(){
	int i,j;
	long long result=0;
	int x, y,dir;
	int start=0; 
	int end=0;
	
	scanf("%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	}
	
	que[end].x=0;
	que[end].y=1;
	que[end].dir=0;
	mark[0][1]=1;
	end++;
	
	while(1){
		if(start==end)
			break;
		x=que[start].x;
		y=que[start].y;
		dir=que[start].dir;
		//printf("%d %d\n",x,y);
		if(x==n-1 && y==n-1){
			result++;
			start++;
			continue;
		}
		if(y<n-1 && map[x][y+1]==0){
			if(dir==0||dir==2){
					que[end].x=x;
					que[end].y=y+1;
					que[end].dir=0;
					end++;
				
			}
		}
		if(x<n-1 && map[x+1][y]==0){
			if(dir==1||dir==2){
				
					que[end].x=x+1;
					que[end].y=y;
					que[end].dir=1;
					end++;
				
			}
		}
		if(x<n-1 && y<n-1){
			if(map[x+1][y]==0 && map[x][y+1]==0 && map[x+1][y+1]==0){
				
					que[end].x=x+1;
					que[end].y=y+1;
					que[end].dir=2;
					mark[x+1][y+1]=1;
					end++;
			}
		}
		start++;
		
	}
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",mark[i][j]);
		printf("\n");
	}*/
	printf("%lld\n",result);	
}
