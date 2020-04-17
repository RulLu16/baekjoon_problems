#include <stdio.h>
#include <stdlib.h>

void cutPaper(long long x, long long y, long long size);

int num[2]={0,};
int** paper;

int main(){
	long long n;
	long long i,j;
	
	scanf("%lld",&n);
	
	paper=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++){
		paper[i]=(int*)malloc(sizeof(int)*n);
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&paper[i][j]);
		}
	}
	
	cutPaper(0,0,n);
	
	printf("%d\n%d\n",num[0],num[1]);
}

void cutPaper(long long x, long long y, long long size){
	long long i,j;
	int base=paper[x][y];
	int flag=0;
	long long half=size/2;
	
	if(size<2){
		num[base]++;
		return;
	}
	
	for(i=x;i<x+size;i++){
		for(j=y;j<y+size;j++){
			if(paper[i][j]!=base){
				flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	
	if(flag!=1){
		num[base]++;
		return;
	}
	
	else{
		cutPaper(x,y,half);
		cutPaper(x,y+half,half);
		cutPaper(x+half, y, half);
		cutPaper(x+half, y+half, half);
	}
}
