#include <stdio.h>
#include <stdlib.h>

int main(){
	int k,i;
	int num;
	int stack[100001];
	int result=0;
	int top=0;
	
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d",&num);
		if(num==0)
			top--;
		else{
			stack[top]=num;
			top++;
		}
	}
	
	for(i=0;i<top;i++){
		result=result+stack[i];
	}
	printf("%d\n",result);
}
