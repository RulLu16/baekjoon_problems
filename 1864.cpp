#include <stdio.h>

char a[20];

void deci(){
	int sum=0;
	int ope;
	
	for(int i=0;i<20;i++){
		
		switch(a[i]){
			case '-':
				ope=0;
				break;
			case '\\':
				ope=1;
				break;
			case '(':
				ope=2;
				break;
			case '@':
				ope=3;
				break;
			case '?':
				ope=4;
				break;
			case '>':
				ope=5;
				break;
			case '&':
				ope=6;
				break;
			case '%':
				ope=7;
				break;
			case '/':
				ope=-1;
				break;
		}
		
		if(a[i]=='\0'){
			break;
		}
		
		sum=sum*8+(ope);
	}
	
	printf("%d\n",sum);
}

int main(){
	
	while(1){
		scanf("%s",a);
		if(a[0]=='#')
			break;
		
		deci();
	}
}
