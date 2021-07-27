#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int MAX = 300000*10 + 1;

int v, e;
int start;
vector<pair<int, int> > graph[20001]; // first = weight, second = v
vector<int> dis;
vector<int> visit;
priority_queue<pair<int, int> > que; // first = weight, second = v

void getDistance(){
	dis[start] = 0;
	que.push(make_pair(0, start));
	
	while(!que.empty()){
		pair<int, int> now = que.top();
		que.pop();
		
		if(-now.first > dis[now.second]) continue;
		
		visit[now.second] = 1;
		
		int size = graph[now.second].size();
		for(int i=0;i<size;i++){
			if(graph[now.second][i].first){
				int nextNode = graph[now.second][i].second;
				
				if(dis[nextNode] > -now.first + graph[now.second][i].first){
					dis[nextNode] = -now.first + graph[now.second][i].first;
					que.push(make_pair(-dis[nextNode], nextNode));
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &v, &e);
	scanf("%d", &start);
	
	dis.assign(v+1, MAX);
	visit.assign(v+1, 0);
	
	for(int i=0;i<e;i++){
		int u, v, w;
		
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back(make_pair(w, v));
	}
	
	getDistance();
	
	for(int i=1;i<=v;i++){
		if(dis[i] == MAX) {
			printf("INF\n");
		}
		else
			printf("%d\n", dis[i]);
	}	
}
