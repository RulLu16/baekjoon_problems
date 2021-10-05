#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit;
vector<vector<int> > graph;

int bfs(int start, int v){
	queue<pair<int, int> > que; // v, color
	vector<int> color;
	color.assign(v+1, 0);
	
	que.push(make_pair(start, 1));
	visit[start] = 1;
	color[start] = 1;
	
	while(!que.empty()){
		int cur = que.front().first;
		int level = que.front().second;
		que.pop();
		
		for(int i=0;i<graph[cur].size();i++){
			int next = graph[cur][i];
			if(color[next] != 0 && color[next] == level){
				return 1;
			} 
			
			if(visit[next] == 0){
				visit[next] = 1;
				que.push(make_pair(next, -level));
				color[next] = -level;
			}
		}
	}
	
	return 0;
}

int main(){
	int k;
	scanf("%d", &k);
	
	for(int i=0;i<k;i++){
		int v, e;
		scanf("%d %d", &v, &e);
		
		graph.assign(v+1, vector<int>());
		visit.assign(v+1, 0);
		
		for(int j=0;j<e;j++){
			int u, s;
			scanf("%d %d", &u, &s);
			
			graph[u].push_back(s);
			graph[s].push_back(u);
		}
		
		int flag = 0;
		for(int j=1;j<=v;j++){
			if(visit[j] == 0){
				flag = bfs(j, v);
			}
			
			if(flag == 1){
				printf("NO\n");
				break;
			}
		}
		
		if(flag == 0)
			printf("YES\n");
	}
}
