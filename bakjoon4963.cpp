#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}island;

int main(){
	int w,h;
	island* bfs=(island*)malloc(sizeof(island)*(51*51));
	int start,end;
	int map[50][50];
	int mark[50][50];
	int result;
	int i,j;
	int ti,tj;
	int xx,yy;
	
	while(1){
		start=0;
		end=start;
		result=0;
		scanf("%d %d",&w,&h);
		if(w==0 && h==0)
			break; //end
			
		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				mark[i][j]=0;
			}
		} //init mark
		
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				scanf("%d",&map[i][j]);
			}
		}
		
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(map[i][j]==1 && mark[i][j]==0){
					mark[i][j]=1;
					result++;
					bfs[start].x=i;
					bfs[start].y=j;
					end++;
					
					while(1){
						if(start==end)
							break;
						xx=bfs[start].x;
						yy=bfs[start].y;
						
						if(xx>0 && map[xx-1][yy]==1 && mark[xx-1][yy]==0){
							bfs[end].x=xx-1;
							bfs[end].y=yy;
							mark[xx-1][yy]=1;
							end++;
						} //up
						if(xx<h-1 && map[xx+1][yy]==1 && mark[xx+1][yy]==0){
							bfs[end].x=xx+1;
							bfs[end].y=yy;
							mark[xx+1][yy]=1;
							end++;
						} //down
						if(yy>0 && map[xx][yy-1]==1 && mark[xx][yy-1]==0){
							bfs[end].x=xx;
							bfs[end].y=yy-1;
							mark[xx][yy-1]=1;
							end++;
						} //left
						if(yy<w-1 && map[xx][yy+1]==1 && mark[xx][yy+1]==0){
							bfs[end].x=xx;
							bfs[end].y=yy+1;
							mark[xx][yy+1]=1;
							end++;
						} //right
						if(yy<w-1 && xx<h-1 && map[xx+1][yy+1]==1 && mark[xx+1][yy+1]==0){
							bfs[end].x=xx+1;
							bfs[end].y=yy+1;
							mark[xx+1][yy+1]=1;
							end++;
						} //down-right
						if(yy<w-1 && xx>0 && map[xx-1][yy+1]==1 && mark[xx-1][yy+1]==0){
							bfs[end].x=xx-1;
							bfs[end].y=yy+1;
							mark[xx-1][yy+1]=1;
							end++;
						} //up-right
						if(yy>0 && xx<h-1 && map[xx+1][yy-1]==1 && mark[xx+1][yy-1]==0){
							bfs[end].x=xx+1;
							bfs[end].y=yy-1;
							mark[xx+1][yy-1]=1;
							end++;
						} //down-left
						if(yy>0 && xx>0 && map[xx-1][yy-1]==1 && mark[xx-1][yy-1]==0){
							bfs[end].x=xx-1;
							bfs[end].y=yy-1;
							mark[xx-1][yy-1]=1;
							end++;
						} //up-left
						
						start++;
					}
				
				}
			}
		}
		
		printf("%d\n",result);
	}
}
