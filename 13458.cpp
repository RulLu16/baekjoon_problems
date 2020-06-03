#include <stdio.h>
#include <stdlib.h>


int main(){
	long long n;
	long long* a;
	long long b, c;
	long long result=0;
	long long temp, exist;
	
	scanf("%lld",&n);
	a=(long long*)malloc(sizeof(long long)*n);
	
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	scanf("%lld %lld",&b,&c);
	
	for(long long i=0;i<n;i++){
		temp=a[i]-b;
		if(temp<0)
			exist=1;
		else{
			exist=1+(a[i]-b)/c;
		//long long non=a[i]/c;
		
			if((a[i]-b)%c!=0)
				exist++;
		}
		/*if(a[i]/c!=0)
			non++;*/
			
		result+=exist;
	}
	
	printf("%lld\n",result);
}
