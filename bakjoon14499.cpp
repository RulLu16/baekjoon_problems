#include <stdio.h>
#include <stdlib.h>

int dice[6];
int n,m;
int x,y;

int out(int dir){
	switch(dir){
		case 1:
			if(y==m-1)
				return 1;
			break;
		case 2:
			if(y==0)
				return 1;
			break;
		case 3:
			if(x==0)
				return 1;
			break;
		case 4:
			if(x==n-1)
				return 1;
			break;
	}
	return 0;
}

void changed(int);

int main(){
	int map[21][21]={0,};
	int k;
	int up[4]={0,0,-1,1};
	int right[4]={1,-1,0,0};
	int i,j;
	int dir;
	int up_n=0;
	int ri_n=0;
	int no=1;
	int result;
	
	scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	}
	
	for(i=0;i<k;i++){
		scanf("%d",&dir);
		if(out(dir)==1)
			continue;
		
		changed(dir);
		x+=up[dir-1];
		y+=right[dir-1];
		//printf("%d %d\n",x,y);
		if(map[x][y]==0){
			map[x][y]=dice[5];
		}
		else{
			dice[5]=map[x][y];
			map[x][y]=0;
		}
		
		printf("%d\n",dice[0]);
	}
}

void changed(int dir){
	int temp[6];
	
	for(int i=0;i<6;i++)
		temp[i]=dice[i];
		
	switch(dir){
		case 1:
			temp[0]=dice[3];
			temp[2]=dice[0];
			temp[3]=dice[5];
			temp[5]=dice[2];
			break;
		case 2:
			temp[0]=dice[2];
			temp[2]=dice[5];
			temp[3]=dice[0];
			temp[5]=dice[3];
			break;
		case 3:
			temp[0]=dice[4];
			temp[1]=dice[0];
			temp[4]=dice[5];
			temp[5]=dice[1];
			break;
		case 4:
			temp[0]=dice[1];
			temp[1]=dice[5];
			temp[4]=dice[0];
			temp[5]=dice[4];
			break;	
	}
	
	for(int i=0;i<6;i++)
		dice[i]=temp[i];
}
