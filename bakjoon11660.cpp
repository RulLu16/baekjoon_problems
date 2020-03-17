#include <stdio.h>
#include <stdlib.h>

int main(){
	long long m,n;
	int i,j,k;
	long long** num;
	long long x1,x2,y1,y2;
	long long result;
	
	scanf("%lld %lld",&n,&m);
	
	num=(long long**)malloc(sizeof(long long*)*n);
	for(i=0;i<n;i++)
		num[i]=(long long*)malloc(sizeof(long long)*n);
		
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%lld",&num[i][j]);
		}
	}
	
	/*for(i=0;i<m;i++){
		result=0;
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		
		for(j=x1-1;j<x2;j++){
			for(k=y1-1;k<y2;k++){
				result=result+num[j][k];
			}
		}
		printf("%lld\n",result);
	}*/
	
}
