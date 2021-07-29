#include <stdio.h>
#include <vector>

using namespace std;

int max_v(int a, int b){
	if(a<b) return b;
	return a;
}

int main(){
	int n, c, m;
	
	vector<int> memory;
	vector<int> cost;
	vector<vector<int> > dp; 
	// 세로 = 앱의 수, 가로 = cost 합 j로 가능한 최대 메모리 => 공간복잡도 때문 
	
	scanf("%d %d", &n, &m);
	
	memory.assign(n+1, 0);
	cost.assign(n+1, 0);
	
	for(int i=1;i<=n;i++){
		int tmp;
		
		scanf("%d", &tmp);
		memory[i] = tmp;
	}
	
	int costSum = 0;
	for(int i=1;i<=n;i++){
		int tmp;
		
		scanf("%d", &tmp);
		cost[i] = tmp;
		costSum += tmp;
	}
	
	dp.assign(n+1, vector<int>(costSum+1, 0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=costSum;j++){
			if(j - cost[i] >= 0){
				dp[i][j] = max_v(dp[i][j], dp[i-1][j-cost[i]] + memory[i]);
			}
			dp[i][j] = max_v(dp[i][j], dp[i-1][j]);
		}
	}
	
	for(int i=0;i<=costSum;i++){
		if(dp[n][i] >= m){
			printf("%d\n", i);
			return 0;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			// 메모리로 하면 메모리초과남.. 
			dp[i][j] = min_v(dp[i-1][j], dp[i-1][j-memory[i-1]] + cost[i-1]);
		}
	}
	
	printf("%d\n", dp[n][m]);*/
	
}
