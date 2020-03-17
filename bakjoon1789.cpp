#include <stdio.h>

int main(){
	long long s,n;
	long long i=1;
	
	scanf("%lld",&s);
	
	while(1){
		if(s-i<=i)
			break;
		s-=i;
		i++;
	}
	
	printf("%lld",i);
}
