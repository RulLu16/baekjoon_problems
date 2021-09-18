#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int getMin(int a, int b){
	if(a < b) return a;
	return b;
}

vector<vector<int> > dist;
vector<pair<int, int> > usado[5001];
int visit[5001];

void bfs(int k, int s){
	queue<pair<int, int> > que;
	int partVisit[5001] = {0,};
	
	que.push(make_pair(s, 1000000001));
	partVisit[s] = 1;
	
	while(!que.empty()){
		pair<int, int> cur = que.front();
		que.pop();
		
		for(int i=0;i<usado[cur.first].size();i++){
			pair<int, int> next = usado[cur.first][i];
			
			if(partVisit[next.first]) continue;
			
			partVisit[next.first] = 1;
			dist[s][next.first] = getMin(dist[s][cur.first], next.second);
			que.push(next);
		}
	}
}


int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	
	dist.assign(n+1, vector<int>(n+1, 1000000000));
	
	for(int i=0;i<n-1;i++){
		int p, q, r;
		scanf("%d %d %d", &p, &q, &r);
		
		usado[p].push_back(make_pair(q, r));
		usado[q].push_back(make_pair(p, r));
	}
	
	for(int i=0;i<q;i++){
		int k, v;
		scanf("%d %d", &k, &v);
		
		if(visit[v] == 0){
			visit[v] = 1;
			bfs(k, v);
		}
		
		int sum = 0;
		for(int j=1;j<=n;j++){
			if(dist[v][j] >= k && j != v) sum++;
		}
		
		printf("%d\n", sum);
	}
}
