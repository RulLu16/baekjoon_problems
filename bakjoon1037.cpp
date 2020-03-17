#include <stdio.h>
#include <stdlib.h>

int main(){
	long long n;
	long long* a;
	long long i;
	long long min,max;
	
	scanf("%lld",&n);
	a=(long long*)malloc(sizeof(long long)*n);
	min=1000000;
	max=0;
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	
	printf("%lld\n",min*max);
		
}
