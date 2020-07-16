#include <stdio.h>

long long result=0;
long long n;

void mySqrt(){
	long long left=0;
	long long right=n;
	long long mid;
	
	while(left<=right){
		mid=(left+right)/2;
		
		if(mid<=n/mid){
			left=mid+1;
			result=mid;
		}
		else{
			right=mid-1;
		}
	}
}

int main(){
	
	scanf("%lld",&n);
	
	if(n==0){
		printf("0\n");
		return 0;
	}
	else if(n==1){
		printf("1\n");
		return 0;
	}
	
	mySqrt();
	
	if(result*result==n) printf("%lld\n",result);
	else printf("%lld\n", result+1);
}
