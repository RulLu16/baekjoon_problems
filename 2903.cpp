#include <stdio.h>

long long pow(long long a, long long b){
	if(b==1){
		return a;
	}
	
	if(b%2==0){
		return pow(a,b/2)*pow(a,b/2);
	}
	else{
		return a*pow(a,(b-1)/2) * pow(a,(b-1)/2);
	}
}

int main(){
	int n;
	
	scanf("%d",&n);

	printf("%lld\n",pow(1+pow(2,n),2));
	
}
