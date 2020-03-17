#include <stdio.h> 
#include <stdlib.h>

int gcd(int, int);

int main(){
	int n;
	int* num;
	int i;
	int gcdnum;
	
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	
	for(i=1;i<n;i++){
		gcdnum=gcd(num[0],num[i]);
		printf("%d/%d\n",num[0]/gcdnum,num[i]/gcdnum);
	}	
}

int gcd(int a, int b){
	int result;
	
	while(b){
		result=a%b;
		a=b;
		b=result;
	}
	return a;
}

