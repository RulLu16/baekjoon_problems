#include <stdio.h>

int main(){
	int n;
	int x, temp;
	
	scanf("%d %d",&n,&x);
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		
		if(temp<x){
			printf("%d ",temp);
		}
	}
	printf("\n");
}
