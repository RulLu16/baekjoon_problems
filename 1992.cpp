#include <stdio.h>

using namespace std;

int map[65][65]={0,};
int n;

int check(int x, int y, int size){
	int temp=map[x][y];
	
	for(int i=x; i<x+size;i++){
		for(int j=y;j<y+size;j++){
			if(temp!=map[i][j]) return -1;
		}
	}
	
	return temp;
}

void compress(int x, int y, int size){
	int num;
	int half=size/2;
	
	if(size==1){
		printf("%d",map[x][y]);
		return;
	}
	
	num=check(x,y,size);
	if(num<0){
		printf("(");
		compress(x,y,half);
		compress(x,y+half,half);
		compress(x+half,y,half);
		compress(x+half,y+half,half);
		printf(")");	
	}
	else{
		printf("%d",num);
		return;
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&map[i][j]);
		}
	}
	
	compress(0,0,n);
	printf("\n");
}
