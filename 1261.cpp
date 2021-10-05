#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
vector<vector<int> > map;

int dijstrak(){
	vector<vector<int> > dist;
	vector<vector<int> > visit;
	dist.assign(n, vector<int>(m, 100001));
	visit.assign(n, vector<int>(m, 0));
	
	priority_queue<pair<int, pair<int, int> > > que;
	que.push(make_pair(0, make_pair(0, 0)));
	dist[0][0] = 0;
	
	while(!que.empty()){
		int x = que.top().second.first;
		int y = que.top().second.second;
		int cost = -que.top().first;
		que.pop();
		if(cost > dist[x][y]) continue;
		
		visit[x][y] = 1;		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if(visit[nx][ny] == 0){
				if(dist[nx][ny] > cost + map[nx][ny]){
					dist[nx][ny] = cost + map[nx][ny];
					que.push(make_pair(-dist[nx][ny], make_pair(nx, ny)));
				}
			}
		}
	}
	
	return dist[n-1][m-1];
}

int main(){
	scanf("%d %d", &m, &n);
	map.assign(n, vector<int>(m, 0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%1d", &tmp);
		
			map[i][j] = tmp;
		}
	}
	
	printf("%d\n", dijstrak());
}
