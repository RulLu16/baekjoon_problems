#include <stdio.h>

long long c;

long long pow(long long a, long long b){
	if(b==1){
		return a;
	}
	
	if(b%2==0){
		return ((pow(a,b/2)%c)*(pow(a,b/2)%c))%c;
	}
	else{
		return ((a%c)*(pow(a,(b-1)/2)%c))%c * (pow(a,(b-1)/2)%c)%c;
	}
}

int main(){
	long long a, b;
	
	scanf("%lld %lld %lld",&a,&b,&c);
	
	printf("%lld\n",pow(a,b)%c);
}
