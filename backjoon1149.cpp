#include <stdio.h>
#include <stdlib.h>

int min(int,int);

int main(){
	int n;
	int r,g,b;
	int i,j;
	int** house;
	int result;
	int** sum;
	scanf("%d",&n);
	
	house=(int**)malloc(sizeof(int*)*n);
	sum=(int**)malloc(sizeof(int*)*n);
	
	for(i=0;i<n;i++){
		house[i]=(int*)malloc(sizeof(int)*3);
		sum[i]=(int*)malloc(sizeof(int)*3);
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d %d",&r,&g,&b);
		house[i][0]=r;
		house[i][1]=g;
		house[i][2]=b;		
	}
	
	sum[0][0]=house[0][0];
	sum[0][1]=house[0][1];
	sum[0][2]=house[0][2];
	
	for(i=1;i<n;i++){
		for(j=0;j<3;j++){
			switch(j){
				case 0:
					sum[i][j]=house[i][j]+min(sum[i-1][1],sum[i-1][2]);
					break;
				case 1:
					sum[i][j]=house[i][j]+min(sum[i-1][0],sum[i-1][2]);
					break;
				case 2:
					sum[i][j]=house[i][j]+min(sum[i-1][1],sum[i-1][0]);
					break;
			}
		}
	}
	
	result=min(sum[n-1][0],sum[n-1][1]);
	result=min(result,sum[n-1][2]);
	
	printf("%d\n",result);
}

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}
