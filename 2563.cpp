#include <stdio.h>

int paper[100][100]={0,};

void color(int x, int y){
	for(int i=x;i<x+10;i++){
		for(int j=y;j<y+10;j++){
			paper[i][j]=1;
		}
	}
}

int main(){
	int n;
	int black=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&y,&x);
		
		color(x,y);
	}
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(paper[i][j]==1) black++;
		}
	}
	
	printf("%d\n",black);
}
