#include <stdio.h>
#include <stdlib.h>

int min(int, int);

int main(){
	int x,y,h,w;
	int r1,r2,result;
	
	scanf("%d %d %d %d",&x,&y,&w,&h);
	
	r1=min(h-y,w-x);
	r2=min(x,y);
	result=min(r1,r2);
	
	printf("%d\n",result);
}

int min(int a,int b){
	if(a<b)
		return a;
	else
		return b;
}
