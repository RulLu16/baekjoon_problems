#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	long n, h, t;
	priority_queue<long> bigger;
	
	scanf("%ld %ld %ld", &n, &h, &t);
	
	for(int i=0;i<n;i++){
		long tmp;
		scanf("%ld", &tmp);
		
		bigger.push(tmp);
	}
	
	for(long i=0;i<t;i++){
		long key = bigger.top();
		bigger.pop();
		
		if(key < h){
			printf("YES\n%ld\n", i);
			return 0;
		}
		
		long shorter = key/2;
		
		if(shorter < 1) shorter = 1;
		bigger.push(shorter);
	}
	
	if(bigger.top() < h){
		printf("YES\n%ld\n", t);
	}
	else{
		printf("NO\n%ld\n", bigger.top());
	}
}
