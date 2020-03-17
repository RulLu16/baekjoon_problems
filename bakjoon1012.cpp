#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}veg;

int main(){
	int n,m,k,t;
	veg* bfs=(veg*)malloc(sizeof(veg)*(51*51));
	int start,end;
	int map[50][50];
	int mark[50][50];
	int result;
	int i,j,test;
	int ti,tj;
	int xx,yy;
	
	scanf("%d",&t);
	
	for(test=0;test<t;test++){
		start=0;
		end=start;
		result=0;
		scanf("%d %d %d",&m,&n,&k);

		for(i=0;i<50;i++){
			for(j=0;j<50;j++){
				mark[i][j]=0;
				map[i][j]=0;
			}
		} //init mark
		
		for(i=0;i<k;i++){
			scanf("%d %d",&tj,&ti);
			map[ti][tj]=1;
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
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
						if(xx<n-1 && map[xx+1][yy]==1 && mark[xx+1][yy]==0){
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
						if(yy<m-1 && map[xx][yy+1]==1 && mark[xx][yy+1]==0){
							bfs[end].x=xx;
							bfs[end].y=yy+1;
							mark[xx][yy+1]=1;
							end++;
						} //right
						
						start++;
					}
				
				}
			}
		}
		
		printf("%d\n",result);
	}
}
