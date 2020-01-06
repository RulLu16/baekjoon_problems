#include <stdio.h>
#include <stdlib.h>


int main(){
	int result,flag;
	int n,i;
	char temp;
	int* re;
	
	scanf("%d",&n);
	getchar();

	for(i=0;i<n;i++){
		result=0;
		flag=0;
		while(1){
			scanf("%c",&temp);
			if(temp=='\n')
				break;
			
			if(temp=='(')
				result++;
			else{
				result--;
				if(result<0)
					flag=1;
			}
				
		}
		if(result==0){
			if(flag==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else{
			printf("NO\n");
		}
			
	}
}
