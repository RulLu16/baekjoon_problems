#include <stdio.h>
#include <stdlib.h>

int main(){
	int c_pre=26;
	int d_pre=10;
	char temp, pre_temp;
	long long result=1;
	
	scanf("%1c",&temp);
	if(temp=='c'){
		pre_temp=temp;
		result*=c_pre;
	}
	else if(temp=='d'){
		
		pre_temp=temp;
		result*=d_pre;
	}
	/*else{
		printf("0\n");
		return 0;
	}
	*/
	for(int i=0;i<4;i++){
		scanf("%1c",&temp);
		
		if(temp=='\n'){
			break;
		}
		
		if(temp=='c'){
			if(pre_temp=='c'){
				result*=25;
			}
			else{
				c_pre=26;
				result*=c_pre;
			}
		}
		else if(temp=='d'){
			if(pre_temp=='d'){
				result*=9;
			}
			else{
				d_pre=10;
				result*=d_pre;
			}
		}
		
		pre_temp=temp;
	}
	
	
	printf("%lld\n",result);
}
