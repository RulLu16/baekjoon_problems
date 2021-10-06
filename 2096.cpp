#include <stdio.h>
#include <vector>

using namespace std;

int getMax(int a, int b){
	if(a < b) return b;
	return a;
}

int getMin(int a, int b){
	if(a < b) return a;
	return b;
}

int main(){
	int n;
	vector<vector<pair<int, int> > > dp;
	
	scanf("%d", &n);
	dp.assign(2, vector<pair<int, int> >(3, make_pair(0, 0)));
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	dp[0][0].first = a; dp[0][0].second = a;
	dp[0][1].first = b; dp[0][1].second = b;
	dp[0][2].first = c; dp[0][2].second = c;	
	
	for(int i=1;i<n;i++){
		scanf("%d %d %d", &a, &b, &c);
		
		dp[1][0].first = getMax(dp[0][0].first, dp[0][1].first) + a;
		dp[1][0].second = getMin(dp[0][0].second, dp[0][1].second) + a;
		
		dp[1][1].first = getMax(getMax(dp[0][0].first, dp[0][1].first), dp[0][2].first) + b;
		dp[1][1].second = getMin(getMin(dp[0][0].second, dp[0][1].second), dp[0][2].second) + b;
		
		dp[1][2].first = getMax(dp[0][2].first, dp[0][1].first) + c;
		dp[1][2].second = getMin(dp[0][2].second, dp[0][1].second) + c;
		
		for(int j=0;j<3;j++){
			dp[0][j].first = dp[1][j].first;
			dp[0][j].second = dp[1][j].second;
		}
	}
	
	printf("%d %d\n", getMax(getMax(dp[0][0].first, dp[0][1].first), dp[0][2].first), getMin(getMin(dp[0][0].second, dp[0][1].second), dp[0][2].second));
}
