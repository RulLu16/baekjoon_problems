#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int n;
	vector<long> towers;
	vector<long> dp;
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		long tmp;
		scanf("%ld", &tmp);
		
		towers.push_back(tmp);
	}
	
	dp.assign(n, -1);
	for(int i=1;i<n;i++){
		if(towers[i] <= towers[i-1]){
			dp[i] = i-1;
		}
		else{
			for(int j=dp[i-1];j>=0;j--){
				if(towers[i] <= towers[j]){
					dp[i] = j;
					break;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%d ", dp[i]+1);
	}
}
