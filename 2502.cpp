#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> fibo;

long long getFibo(int target){
	if(target == 1 || target == 2) return 1;
	
	if(fibo[target] != 1) return fibo[target];
	
	fibo[target] = getFibo(target-1) + getFibo(target-2);
	
	return fibo[target];
}

int main(){
	int d, k;
	
	scanf("%d %d", &d, &k);
	fibo.assign(d+1, 1);
	
	long long a = getFibo(d - 2);
	long long b = getFibo(d - 1);
	
	long long first = 1;
	while(1){
		if((k - first * a) % b == 0){
			printf("%lld\n%lld\n", first, (k-first*a)/b);
			return 0;
		}
		
		first++;
	}
}
