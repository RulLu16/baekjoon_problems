#include <stdio.h>

int main(){
	char result;
	int flag=1;
	int grade=0;
	int n;
	
	scanf("%d",&n);
	getchar();
	
	for(int i=0;i<n;i++){
		grade=0;
		flag=1;
		while(1){
			scanf("%1c",&result);
			
			if(result=='O'){
				grade+=flag;
				flag++;
			}
			else if(result=='\n'){
				printf("%d\n",grade);
				break;
			}
			else{
				flag=1;
			}
		}
	}
}
