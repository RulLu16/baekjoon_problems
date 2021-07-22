#include <stdio.h>
#include <vector>

using namespace std;

long gcd(long a, long b){
	while(b != 0){
		int r = a%b;
		a = b;
		b = r;
	}
	
	return a;
}

int main(){
	long n;
	vector<long> num;
	long ans = -1;
	long idx = 0;
	scanf("%ld", &n);
	
	for(long i=0;i<n;i++){
		long tmp;
		scanf("%ld", &tmp);
		
		num.push_back(tmp);
	}
	
	vector<long> lr;
	lr.push_back(num[0]);
	for(long i=1;i<n;i++){
		long tmp = gcd(num[i], lr[i-1]);
		lr.push_back(tmp);
	}
	
	vector<long> rl;
	rl.assign(n, 0);
	rl[n-1] = num[n-1];
	for(long i=n-2;i>=0;i--){
		long tmp = gcd(num[i], rl[i+1]);
		rl[i] = tmp;
	}
	
	long origin = rl[0];
	for(long i=0;i<n;i++){
		long left = i-1;
		long right = i+1;
		
		long new_gcd;		
		if(left < 0){
			new_gcd = rl[right];
		}
		else if(right >= n){
			new_gcd = lr[left];
		}
		else{
			new_gcd = gcd(lr[left], rl[right]);
		}
		
		if(num[i]%new_gcd == 0) continue;
		
		if(new_gcd > ans) {
			ans = new_gcd;
			idx = i;
		}
	}
	
	if(ans == -1) printf("-1\n");
	else printf("%ld %ld\n", ans, num[idx]);
}
