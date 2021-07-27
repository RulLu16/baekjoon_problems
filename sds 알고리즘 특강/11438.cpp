#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int n; int max_v = 0;
vector<int> graph[100001];
vector<int> depth, visit, anc;
vector<vector<int> > parent;

int getAncestor(int a, int b){
	int exp = 0;
	
	if(depth[a] < depth[b]){
		int tmp = a;
		a = b; b = tmp;
	} // 깊이가 더 아래인 것을 a로 맞춤 
	
	while(1){
		if(depth[a] == depth[b]){
			break;
		}
	
		if(depth[parent[exp][a]] >= depth[b]){
			a = parent[exp][a];
			exp++;
		}
		else exp = 0;
	} // 두 노드의 깊이 맞추기 
	
	if(a == b) return a;
	
	for(int i=parent.size()-1;i>=0;i--){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	} // 같은 depth에서 위로 2^k만큼 점프해보며 찾기. 
	
	if(a <= 1) return 1;
	return parent[0][a];
}

void dfs(int n_depth, int node, int p){
	depth[node] = n_depth;
	anc[node] = p;
	if(n_depth > max_v) max_v = n_depth;
	
	for(int i=0;i<graph[node].size();i++){
		if(visit[graph[node][i]] == 0){
			visit[graph[node][i]] = 1;
			dfs(n_depth+1, graph[node][i], node);
			visit[graph[node][i]] = 0;
		}
	}
	
	return;
}

int getExp(){
	int num = 1;
	int ex = 0;
	
	while(1){
		if(max_v < num){
			break;
		}
		else {
			num *= 2;
			ex++;
		}
	}
	
	return ex;
}

void getParent(){
	int exp = getExp();
	
	parent.assign(exp, vector<int>(n+1, 0));
	
	for(int i=1;i<=n;i++){
		parent[0][i] = anc[i];
	}
	
	for(int i=1;i<exp;i++){
		for(int j=1;j<=n;j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
	
}

int main(){
	scanf("%d", &n);
	
	depth.assign(n+1, 0);
	visit.assign(n+1, 0);
	anc.assign(n+1, 0);
	
	for(int i=1;i<n;i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visit[1] = 1;
	dfs(0, 1, 0); // 각 노드의 depth 계산 
	
	getParent(); // 2^k의 조상 parent 테이블 계산 
	
	int m;
	scanf("%d", &m);
	
	for(int i=0;i<m;i++){
		int a, b;
		
		scanf("%d %d", &a, &b);
		printf("%d\n", getAncestor(a, b));
	}
}
