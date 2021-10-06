#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int> > ocean;
vector<pair<int, int> > ice;

int bfs(){
	queue<pair<int, int> > que;
	que.push(ice[0]);
	
	vector<vector<int> > visit;
	visit.assign(n, vector<int>(m, 0));
	visit[ice[0].first][ice[0].second] = 1;
	
	while(!que.empty()){
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
				
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				
			if(ocean[nx][ny] != 0 && visit[nx][ny] == 0){
				visit[nx][ny] = 1;
				que.push(make_pair(nx, ny));
			}
		}
	}
	
	for(int i=0;i<ice.size();i++){
		if(visit[ice[i].first][ice[i].second] == 0)
			return 1;
	}
	
	return 0;
}

int main(){
	scanf("%d %d", &n, &m);
	
	ocean.assign(n, vector<int>(m, 0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			scanf("%d", &tmp);
			
			ocean[i][j] = tmp;
			
			if(tmp != 0){
				ice.push_back(make_pair(i, j));
			}
		}
	}
	
	int time = 1;
	while(ice.size() != 0){
		vector<vector<int> > copy;
		copy.assign(ocean.begin(), ocean.end());
		
		vector<pair<int, int> > ice_copy;
		// 얼음 녹이기 
		for(int i=0;i<ice.size();i++){
			int x = ice[i].first;
			int y = ice[i].second;
			int melt = 0;
			
			for(int j=0;j<4;j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				
				if(ocean[nx][ny] == 0) melt++;
			}
			
			copy[x][y] -= melt;
			if(copy[x][y] <= 0) copy[x][y] = 0;
			else ice_copy.push_back(ice[i]);
		}
		// 녹인 상태 반영 
		ocean.assign(copy.begin(), copy.end());
		ice.assign(ice_copy.begin(), ice_copy.end());
		
		// 한덩이 판단
		if(bfs()){
			printf("%d\n", time);
			return 0;
		} 
		time++;
	}
	
	printf("0\n");
}
