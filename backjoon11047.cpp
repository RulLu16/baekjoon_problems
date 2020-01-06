#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,k;
	int* coin;
	int result=0;
	int temp;
	int i,j;
	
	scanf("%d %d",&n,&k);
	coin=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}
	
	i=n-1;
	
	while(k>0){
		if(coin[i]<=k){
			result=result+(k/coin[i]); //calculate sum of coins
			k=k%coin[i]; //calculate remain k
			i--;
		}
		else{
			i--; //take another coin
		}
	}
	
	printf("%d\n",result);
	
}
