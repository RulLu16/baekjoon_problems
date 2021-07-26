#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> node[501];
int dp[501], t[501];

int max_v(int a, int b){
	if(a<b) return b;
	return a;
}

int dfs(int target){
	if(dp[target]) return dp[target];
	
	for(int i=0;i<node[target].size();i++){
		dp[target] = max_v(dp[target], dfs(node[target][i]));
	}
	
	dp[target] += t[target];
	return dp[target];
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i=1;i<=n;i++){
		int time;
		
		scanf("%d", &time);
		t[i] = time;
		
		while(1){
			int before;
			scanf("%d", &before);
			
			if(before == -1) break;
			
			node[i].push_back(before);
		}
	}
	
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	
	for(int i=1;i<=n;i++){
		printf("%lld\n", dp[i]);
	}
}

/*
int n;
long long total = 0;
vector<pair<int, int> > topol; // first = degree, second = time
vector<int> node[501];
queue<int> que;
vector<int> build;
vector<long long> result;

void time_out(){
	
	if(build.empty()) return;
	
	while(1){
		int flag = 0;
		vector<int> erase;
		total++;
		
		for(int i=0;i<build.size();i++){
			topol[build[i]].second--;
			
			if(topol[build[i]].second == 0) {
				flag = build[i];
				result[build[i]] = total;
				erase.push_back(i);
				que.push(flag);
			}
		}
		
		for(int i=0;i<erase.size();i++){
			build.erase(build.begin() + erase[i] - i);
		}
		
		if(flag > 0) return;
	}
}

void topol_sort(){
	
	for(int i=1;i<=n;i++){
		if(topol[i].first == 0){
			build.push_back(i);
		}
	}
	time_out();

	while(!que.empty()){
		int temp = que.front(); que.pop();
		//printf("%d\n ", temp);
		
		for(int i=0;i<node[temp].size();i++){
			topol[node[temp][i]].first--;
			
			if(topol[node[temp][i]].first == 0){
				build.push_back(node[temp][i]);
			}
		}
		
		time_out();
	}
}

int main(){
	scanf("%d", &n);
	
	topol.assign(n+1, make_pair(0, 0));
	result.assign(n+1, 0);
	
	for(int i=1;i<=n;i++){
		int a, b, c;
		
		scanf("%d %d", &a, &b);
		
		if(b != -1){
			topol[i].first++;			
			node[b].push_back(i);
				
			while(1){
				scanf("%d", &c);
				
				if(c == -1) break;
				
				topol[i].first++;			
				node[c].push_back(i);
			}
		}
		topol[i].second = a;
	}
	
	topol_sort();
	
	for(int i=1;i<=n;i++){
		printf("%lld\n", result[i]);
	}
}*/
