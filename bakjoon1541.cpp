#include <stdio.h>
#include <stdlib.h>

int main(){
	int num[50];
	char op[50];
	int i,j,length;
	int result;
	int plus=0;
	int temp=0;
	int minus=0;
	
	length=0;
	while(1){
		scanf("%d",&num[length]);
		scanf("%1c",&op[length]);
		
		if(op[length]=='\n')
			break;
		length++;
	}
	
	result=num[0];
	for(i=0;i<length;i++){
		if(minus==1){
			result=result-num[i+1];
		}
		else if(op[i]=='-'){
			minus=1;
			result=result-num[i+1];
		}
		else{
			result=result+num[i+1];
		}
	}
	
	printf("%d\n",result);
	
}
