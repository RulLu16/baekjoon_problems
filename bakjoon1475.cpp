#include <stdio.h>
#include <stdlib.h>

int main(){
	char n;
	int num[10]={0,};
	int i;
	int temp;
	int max=0;
	
	while(1){
		scanf("%1c",&n);
		if(n=='\n')
			break;
		
		temp=((int)n)-48;
		
		if(temp==6 || temp==9){
			if(num[6]==num[9])
				num[temp]++;
			else if(num[6]<num[9])
				num[6]++;
			else
				num[9]++;
		}
		else{
			num[temp]++;
		}
		
	}
	
	for(i=0;i<10;i++){
		if(max<num[i])
			max=num[i];
	}
	printf("%d\n",max);
}
