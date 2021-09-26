#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int d, n;
	vector<long long> oven;
	
	scanf("%d %d", &d, &n);
	
	oven.push_back(1000000000);
	for(int i=0;i<d;i++){
		long long o;
		scanf("%lld", &o);
		
		oven.push_back(o);
	}
	
	long long wide = oven[1];
	for(int i=2;i<d;i++){
		if(wide > oven[i]){
			wide = oven[i];
			continue;
		}
		oven[i] = wide;
	}
	
	int depth = d + 1;
	for(int i=0;i<n;i++){
		long long dough;
		scanf("%lld", &dough);
		
		int right = depth - 1;
		int left = 0;
		
		while(left <= right){
			int mid = (right + left) / 2;
			
			if(oven[mid] < dough){
				right = mid - 1;
			}
			else{
				left = mid + 1;
				depth = mid;
			}
		}
	}
	
	printf("%d\n", depth);
}
