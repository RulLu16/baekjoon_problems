#include <stdio.h>
#include <vector>

using namespace std;

typedef struct{
	long gcd;
	long s; long t;
}ex;

ex extendedGcd(long a, long b){
	long s0 = 1; long t0 = 0; long r0 = a;
	long s1 = 0; long t1 = 1; long r1 = b;
	
	long tmp;
	while(r1 != 0){
		long q = r0 / r1;
		
		tmp = r0 - q * r1;
		r0 = r1;
		r1 = tmp;
		
		tmp = s0 - q*s1;
		s0 = s1;
		s1 = tmp;
		
		tmp = t0 - q*t1;
		t0 = t1;
		t1 = tmp;
	}
	
	if(t0 < 0) t0 += a;
	ex e;
	e.gcd = r0; e.s = s0; e.t = t0;
	
	return e;
}

int main(){
	int t;
	scanf("%d", &t);
	
	// x = 나눠줄 사탕 수
	// y = 봉지 수 
	// k*x + 1 = c*y
	
	for(int i=0;i<t;i++){
		long k, c;
		
		scanf("%ld %ld", &k, &c);
		
		if(k == 1 && c == 1){
			printf("2\n");
			continue;
		}
		if(c == 1){
			if(k+1 > 1000000000){
				printf("IMPOSSIBLE\n");
				continue;
			}
			else{
				printf("%ld\n", k+1);
				continue;
			}
		}
		if(k == 1){
			printf("1\n");
			continue;
		}
		
		// ax + by = c 일 때 c%gcd(a,b) == 0이어야 해를 가짐. 배수 항등식
		ex e = extendedGcd(k, c);
		if(e.gcd != 1 || e.t > 1000000000){
			printf("IMPOSSIBLE\n"); 
		} 
		else{
			printf("%ld\n", e.t);
		}
	}	 
}
