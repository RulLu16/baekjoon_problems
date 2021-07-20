#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int left, right;
	int n,m;
	int sum = 0;
	int count = 0;
	vector<int> arr;
	
	scanf("%d %d", &n, &m);
	left = 0; right = 0;

	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d", &tmp);
		
		arr.push_back(tmp);
	}
	
	sum = arr[0];
	while(1){
		if(right >= n || left >= n) break;
		
		if(sum == m){
			count++;
			right++;
			sum += arr[right];
		}
			
		if(sum < m){
			right++;
			sum += arr[right];
		}
		else if(sum > m){
			sum -= arr[left];
			left++;
		}
	}
	
	printf("%d\n", count);
	
}
