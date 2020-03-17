#include <stdio.h>

long gcd(long, long);

int main(){
	long fa,fb;
	long sa,sb;
	long a,b;
	long g;
	
	scanf("%ld %ld",&fa,&fb);
	scanf("%ld %ld",&sa,&sb);
	
	a=fa*sb+fb*sa;
	b=sb*fb; //the numbers which are not divided by gcd 
	if(a>b)
		g=gcd(b,a); //calculate gcd when a>b
	else
		g=gcd(a,b); // calculate when a<b
	a=a/g;
	b=b/g;
	
	printf("%ld %ld\n",a,b);
}

long gcd(long a, long b){ //to find gcd, use uclid method
	if(b%a==0)
		return a; //find gcd.
	return gcd(b%a,a); //not find then continue uclid method
}
