#include <stdio.h>

int main(){
	int n;
	int sum=0;
	int result=0;
	int ten, one;
	
	scanf("%d",&n);
	sum=n;
	
	while(1){
		if(sum<10){
			sum=sum*10+sum;
		}		
		else{
			one=sum/10+sum%10;
			one%=10;
			ten=sum%10;
			sum=ten*10+one;
		}
		result++;
		if(sum==n){
			printf("%d\n",result);
			break;
		}
	}
}
