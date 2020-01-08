#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	long long* p;
	int i;
	long long temp;
	int* input;
	
	scanf("%d",&n);
	p=(long long*)malloc(sizeof(long long)*100);
	input=(int*)malloc(sizeof(int)*n);
	
	p[0]=1;
	p[1]=1;
	p[2]=1;
	
	for(i=3;i<100;i++){
		p[i]=p[i-3]+p[i-2];
	}
	
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	for(i=0;i<n;i++){
		temp=input[i];
		printf("%llu\n",p[temp-1]);
	}
}
