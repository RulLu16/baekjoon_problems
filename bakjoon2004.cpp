#include <stdio.h>
#include <stdlib.h>

long long divide(long long, long long);

int main(){
	long long n,m,i;
	long long five_up, five_down;
	long long two_up, two_down;
	long long five, two;
	
	scanf("%lld %lld",&n,&m);
	five_up=0;
	five_down=0;
	two_up=0;
	five=0; 
	two=0;
	two_down=0;
	
	/*if(n==0){
		printf("0\n");
		return 0;
	}*/	
	//printf("%d %d\n",five_down, two_down);
	five=divide(n,5)-divide(n-m,5)-divide(m,5);
	two=divide(n,2)-divide(n-m,2)-divide(m,2);
	
	if(five>two)
		printf("%lld\n",two);
	else
		printf("%lld\n",five);
}

long long divide(long long n,long long d){
	long long result=0;
	long long i;
	
	for(i=d;i<=n;i*=d){
		result=result+n/i;
	}
	return result;
}
