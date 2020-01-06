#include <stdio.h>
#include <stdlib.h>

int max(int, int);

int main(){
	int n;
	int** triangle;
	int** sum;
	int i,j;
	int result=0;
	
	scanf("%d",&n);
	
	triangle=(int**)malloc(sizeof(int*)*n);
	sum=(int**)malloc(sizeof(int*)*n);
	
	for(i=0;i<n;i++){
		triangle[i]=(int*)malloc(sizeof(int)*(i+1));
		sum[i]=(int*)malloc(sizeof(int)*(i+1));
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			scanf("%d",&triangle[i][j]);
		}
	}
	
	sum[0][0]=triangle[0][0];
	
	for(i=1;i<n;i++){
		for(j=0;j<=i;j++){
			if(j==0)
				sum[i][j]=triangle[i][j]+sum[i-1][j];
			else if(j==i)
				sum[i][j]=triangle[i][j]+sum[i-1][j-1];
			else
				sum[i][j]=triangle[i][j]+max(sum[i-1][j],sum[i-1][j-1]);
		}
	}
	
	for(i=0;i<n;i++){
		result=max(result,sum[n-1][i]);
	}
	
	printf("%d\n",result);
}

int max(int a,int b){
	if(a>b)
		return a;
	else 
		return b;
}
