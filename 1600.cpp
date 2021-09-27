#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int k, w, h;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1 ,-2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx_w[4] = {0, 1, 0, -1};
int dy_w[4] = {-1, 0, 1, 0};
vector<vector<int> > board;

int bfs(){
	int move = 40000;
	int visit[k+1][h][w] = {};
	queue<vector<int> > que; // x y k move
	
	vector<int> core;
	core.push_back(0); core.push_back(0);
	core.push_back(0); core.push_back(0);
	que.push(core);
	visit[0][0][0] = 1;
	
	while(!que.empty()){
		int x = que.front()[0];
		int y = que.front()[1];
		int cur_k = que.front()[2];
		int cur_move = que.front()[3];
		que.pop();
		
		if(x == h-1 && y == w-1 && cur_move < move){
			move = cur_move;
			continue;
		}
		
		for(int i=0;i<4;i++){
			int nextx = x + dx_w[i];
			int nexty = y + dy_w[i];
			
			if(nextx < 0 || nextx >= h || nexty < 0 || nexty >= w)
				continue;
			
			if(board[nextx][nexty] == 0 && visit[cur_k][nextx][nexty] == 0){			
				visit[cur_k][nextx][nexty] = 1;
				vector<int> new_one;
				new_one.push_back(nextx); new_one.push_back(nexty);
				new_one.push_back(cur_k); new_one.push_back(cur_move + 1);
			
				que.push(new_one);
			}
		}
		
		if(cur_k >= k) continue;
		
		for(int i=0;i<8;i++){
			int nextx = x + dx[i];
			int nexty = y + dy[i];
			
			if(nextx < 0 || nextx >= h || nexty < 0 || nexty >= w)
				continue;
			
			if(board[nextx][nexty] == 0 && visit[cur_k + 1][nextx][nexty] == 0){				
				visit[cur_k + 1][nextx][nexty] = 1;
				vector<int> new_jump;
				new_jump.push_back(nextx); new_jump.push_back(nexty);
				new_jump.push_back(cur_k + 1); new_jump.push_back(cur_move + 1);
				que.push(new_jump);
			}
		}
	}
	
	if(move == 40000) return -1;
	else return move;
}


int main(){
	scanf("%d", &k);
	scanf("%d %d", &w, &h);
	
	board.assign(h, vector<int>(w, 0));
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			int tmp;
			scanf("%d", &tmp);
			
			board[i][j] = tmp;
		}
	}
	
	printf("%d", bfs());
}
