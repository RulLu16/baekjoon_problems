#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n, s;
	vector<long long> arr;
	
	scanf("%d %d", &n, &s);
	
	for(int i=0;i<n;i++){
		long long tmp;
		
		scanf("%lld", &tmp);
		arr.push_back(tmp);
	}
	
	int right = 0; int left = 0;
	long long sum = arr[0];
	long long min_v = 100001;
	
	while(1){
		if(right >= n || left >= n) break;
			
		if(sum < s){
			right++;
			sum += arr[right];
		}
		else if(sum >= s){
			if(right - left < min_v) 
				min_v = right - left + 1;
			
			sum -= arr[left];
			left++;
		}
	}
	
	if(min_v == 100001) printf("0\n");
	else printf("%lld\n", min_v);
}
