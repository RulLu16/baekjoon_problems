#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > map;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(){
	queue<vector<int> > que;
	vector<vector<vector<int> > > visit;
	
	visit.assign(2, vector<vector<int> >(n, vector<int>(m, 0)));
	que.push(vector<int>(4, 0)); // x y isCrack move
	visit[0][0][0] = 1;
	
	while(!que.empty()){
		int x = que.front()[0];
		int y = que.front()[1];
		int isCrack = que.front()[2];
		int move = que.front()[3];
		que.pop();
		
		if(x == n - 1 && y == m - 1){
			return move + 1;
		}
		
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			
			if(map[nx][ny] == 0){
				if(visit[isCrack][nx][ny] == 0){
					visit[isCrack][nx][ny] = 1;
					
					vector<int> tmp;
					tmp.push_back(nx); tmp.push_back(ny);
					tmp.push_back(isCrack); tmp.push_back(move+1);
					que.push(tmp);
				}
			}
			else{
				if(isCrack == 0 && visit[1][nx][ny] == 0){
					visit[1][nx][ny] = 1;
					
					vector<int> tmp;
					tmp.push_back(nx); tmp.push_back(ny);
					tmp.push_back(1); tmp.push_back(move+1);
					que.push(tmp);
				}
			}
		}
	}
	
	return -1;
}

int main(){	
	scanf("%d %d", &n, &m);
	map.assign(n, vector<int>(m, 0));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			
			scanf("%1d", &tmp);
			map[i][j] = tmp;
		}
	}
	
	printf("%d\n", bfs());
}
