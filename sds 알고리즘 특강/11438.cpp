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
	} // ���̰� �� �Ʒ��� ���� a�� ���� 
	
	while(1){
		if(depth[a] == depth[b]){
			break;
		}
	
		if(depth[parent[exp][a]] >= depth[b]){
			a = parent[exp][a];
			exp++;
		}
		else exp = 0;
	} // �� ����� ���� ���߱� 
	
	if(a == b) return a;
	
	for(int i=parent.size()-1;i>=0;i--){
		if(parent[i][a] != parent[i][b]){
			a = parent[i][a];
			b = parent[i][b];
		}
	} // ���� depth���� ���� 2^k��ŭ �����غ��� ã��. 
	
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
	dfs(0, 1, 0); // �� ����� depth ��� 
	
	getParent(); // 2^k�� ���� parent ���̺� ��� 
	
	int m;
	scanf("%d", &m);
	
	for(int i=0;i<m;i++){
		int a, b;
		
		scanf("%d %d", &a, &b);
		printf("%d\n", getAncestor(a, b));
	}
}
