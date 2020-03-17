#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(){
	int n;
	int a,b;
	int i;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(a<b){
			printf("%d\n",a*b/gcd(b,a));
		}
		else
			printf("%d\n",a*b/gcd(a,b));
	}
}

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
