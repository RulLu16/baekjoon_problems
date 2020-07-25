#include <stdio.h>
#include <stdlib.h>

int main(){
	char str[101];
	int idx=0;
	
	scanf("%s",str);
	
	while(str[idx]!='\0'){
		for(int i=0; i<10;i++){
			if(str[i+idx]=='\0'){
				exit(0);
			}
			printf("%c",str[i+idx]);
		}
		idx+=10;
		printf("\n");
	}
}
