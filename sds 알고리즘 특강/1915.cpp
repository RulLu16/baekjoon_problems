#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int min_v(int a, int b){
	if(a<b) return a;
	return b;
}

int main(){
	int n, m;
	vector<vector<int> > arr;
	vector<vector<int> > dp;
	int ans = 0;
	
	scanf("%d %d", &n, &m);
	
	arr.assign(n, vector<int>(m, 0));
	dp.assign(n, vector<int>(m, 0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%1d", &tmp);
			
			arr[i][j] = tmp;
			dp[i][j] = tmp;
			
			if(tmp == 1) ans = 1;
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(dp[i][j] == 0) continue;
			
			if(dp[i-1][j] == 0 || dp[i][j-1] == 0 || dp[i-1][j-1] == 0){
				dp[i][j] = 1;
			}
			else{
				dp[i][j] = 	min_v(dp[i-1][j], min_v(dp[i][j-1], dp[i-1][j-1])) + 1;	
			}
			
			if(dp[i][j] > ans) ans = dp[i][j];
		}
	}
	
	printf("%d\n", ans*ans);	
}
