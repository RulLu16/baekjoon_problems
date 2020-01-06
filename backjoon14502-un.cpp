#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int* t;
	int* p;
	int* check;
	int i;
	
	scanf("%d",&n);
	t=(int*)malloc(sizeof(int)*n);
	p=(int*)malloc(sizeof(int)*n);
	check=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
		scanf("%d %d",&t[i],&p[i]);
	
	
}
