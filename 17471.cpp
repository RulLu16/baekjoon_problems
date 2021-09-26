#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int n;
vector<vector<int> > graph;
vector<int> visit;
vector<int> reg_first;
vector<int> reg_second;
vector<int> population;
int min_v = 5001;

int bfs(int target, int mode, int start){
	// 연결 여부 파악 + 인구 수 세기 
	
	int sum = 1;
	int popu = population[start];
	queue<int> que;
	que.push(start);
	
	vector<int> copy;
	if(mode == 1) copy.assign(reg_first.begin(), reg_first.end());
	else copy.assign(reg_second.begin(), reg_second.end());
	
	visit.assign(n+1, 0);
	visit[start] = 1;
	
	while(!que.empty()){
		int v = que.front();
		que.pop();
		
		for(int i=0;i<graph[v].size();i++){
			if(visit[graph[v][i]] == 0 && copy[graph[v][i]] == 1){
				visit[graph[v][i]] = 1;
				que.push(graph[v][i]);
				sum++;
				popu += population[graph[v][i]];
			}
		}
	}
	
	if(sum == target) return popu;
	else return -1;
}

int getPopulation(int target){
	// 한 정점 뽑아서 bfs로 인구수, 연결여부 확인 
	
	int first_popu;
	for(int i=1;i<reg_first.size();i++){
		if(reg_first[i] == 1){
			first_popu = bfs(target, 1, i);
			break;
		}
	}
	
	if(first_popu < 0) return 5001;
	
	int second_popu;
	for(int i=1;i<reg_second.size();i++){
		if(reg_second[i] == 1){
			second_popu = bfs(n - target, 2, i);
			break;
		}
	}
	
	if(second_popu < 0) return 5001;
	
	return abs(first_popu - second_popu);
}

void brute(int target, int depth, int before){
	if(depth == target){
		int popu = getPopulation(target);
		
		if(popu < min_v){
			min_v = popu;
		}
		return;
	}
	
	for(int i=before+1;i<=n;i++){
		if(reg_first[i] == 0){
			reg_first[i] = 1;
			reg_second[i] = 0;
			brute(target, depth + 1, i);
			reg_first[i] = 0;
			reg_second[i] = 1;
		}
	}
}

int main(){
	scanf("%d", &n);
	
	population.assign(n+1, 0);
	graph.assign(n+1, vector<int>());
	
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d", &tmp);
		population[i] = tmp;
	}	
	
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d", &num);
		
		for(int j=0;j<num;j++){
			int tmp;
			scanf("%d", &tmp);
			
			graph[i].push_back(tmp);
		}
	}
	
	// 선거구 뽑기
	for(int i=1;i<n;i++){
		reg_first.assign(n+1, 0);
		reg_second.assign(n+1, 1);
		brute(i, 0, 0);
	}
	
	if(min_v == 5001) printf("-1\n");
	else printf("%d\n", min_v);
}
