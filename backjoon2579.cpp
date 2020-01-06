#include <stdio.h>
#include <stdlib.h>

int max(int, int);

int main(){
	int n;
	int* stair;
	int* sum;
	int i,j;
	int rep=0;
	scanf("%d",&n);
	stair=(int*)malloc(sizeof(int)*n);
	sum=(int*)malloc(sizeof(int*)*(n));
/*	for(i=0;i<=n;i++)
		sum[i]=(int*)malloc(sizeof(int)*2);*/
	
	for(i=0;i<n;i++)
		scanf("%d",&stair[i]);
	
	/*sum[0][0]=0;
	sum[0][1]=0;
	rep=0;*/
	
	/*for(i=1;i<=n;i++){
		sum[i][1]=sum[i-1][0];

		if(rep==2){
			sum[i][0]=sum[i-1][1]+stair[i-1];
			rep=1;
		}
		else{
			if(sum[i-1][0]>sum[i-1][1]){
				sum[i][0]=sum[i-1][0]+stair[i-1];
				rep++;
			}
			else{
				sum[i][0]=sum[i-1][1]+stair[i-1];
				rep=1;
			}
		}
		
	}
	for(i=0;i<=n;i++){
		for(j=0;j<2;j++)
			printf("%d ",sum[i][j]);
		printf("\n");
	}*/
	
	sum[0]=stair[0];
	sum[1]=max(sum[0],stair[1]+sum[0]);
	sum[2]=max(stair[1]+stair[2],stair[0]+stair[2]);
	
	for(i=3;i<n;i++){
		sum[i]=max(stair[i]+sum[i-2],stair[i]+stair[i-1]+sum[i-3]);
	}
	
	printf("%d\n",sum[n-1]);			
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
