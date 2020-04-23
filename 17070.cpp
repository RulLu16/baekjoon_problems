#include <stdio.h>
#include <stdlib.h>

int result;
int size;
int house[16][16]={0,};

void pipe(int x, int y, int vec){
	if(x==size-1 && y==size-1){
		result++;
		return;
	}
	
	if(vec==0){
		if(y+1<size && house[x][y+1]==0){
			pipe(x,y+1,0);
		}
		if(x+1<size && y+1<size && (house[x+1][y+1]==0 && house[x][y+1]==0 && house[x+1][y]==0)){
			pipe(x+1, y+1, 2);
		}		
	}
	else if(vec==1){
		if(x+1<size && house[x+1][y]==0){
			pipe(x+1, y, 1);
		}		
		if(x+1<size && y+1<size && (house[x+1][y+1]==0 && house[x][y+1]==0 && house[x+1][y]==0)){
			pipe(x+1, y+1, 2);
		}
	}
	else{
		if(y+1<size && house[x][y+1]==0){
			pipe(x, y+1, 0);
		}
		if(x+1<size && house[x+1][y]==0){
			pipe(x+1, y, 1);
		}
		if(x+1<size && y+1<size && (house[x+1][y+1]==0 && house[x][y+1]==0 && house[x+1][y]==0)){
			pipe(x+1, y+1, 2);
		}		
	}
}

int main(){
	int i,j;
	result=0;
	
	scanf("%d",&size);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&house[i][j]);
		}
	}	
	
	pipe(0,1,0);	
	
	printf("%d\n",result);
}
