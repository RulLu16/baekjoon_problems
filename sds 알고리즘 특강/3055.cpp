#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct{
	vector<vector<char> > map;
	vector<pair<int, int> > water;
	int x;
	int y; // 고슴도치 위치
	int count; // 이동 횟수 
}block;

queue<block> que;
int r,c;
int xmove[4] = {0,1,0,-1};
int ymove[4] = {1,0,-1,0};
vector<vector<int> > visit;

block flood(block map){
	vector<vector<char> > after;
	after.assign(r, vector<char>(c, 0));
	
	vector<pair<int, int> > water;
	
	copy(map.map.begin(), map.map.end(), after.begin());
	
	for(int i=0;i<map.water.size();i++){
		int x = map.water[i].first;
		int y = map.water[i].second;
		
		water.push_back(make_pair(x, y));
		for(int j=0;j<4;j++){
			int nextx = x + xmove[j];
			int nexty = y + ymove[j];
			
			if(nextx<0 || nextx>=r || nexty<0 || nexty>=c)
				continue;
			
			if(after[nextx][nexty] == '.' || after[nextx][nexty] == 'S'){
				after[nextx][nexty] = '*';
				water.push_back(make_pair(nextx, nexty));
			}
		}
	}
	
	block b;
	b.map = after; b.count = map.count;
	b.x = map.x; b.y = map.y; b.water = water;
	
	return b;
}

void bfs(){
	while(!que.empty()){
		block after_map = flood(que.front());
		que.pop();
		
		// 물 이동 후 고슴도치 이동 여부 확인
		for(int i=0;i<4;i++){
			int nextx = after_map.x + xmove[i];
			int nexty = after_map.y + ymove[i];
			
			if(nextx < 0 || nextx>=r || nexty<0 || nexty>=c)
				continue;
			
			if(visit[nextx][nexty] == 1) continue; // 방문 확인. 없으면 메모리초과 
			
			if(after_map.map[nextx][nexty] == 'D'){
				printf("%d\n", after_map.count+1);
				return;
			}
			else if(after_map.map[nextx][nexty] == '.'){
				block b;
				
				b.map.assign(r, vector<char>(c, 0));
				copy(after_map.map.begin(), after_map.map.end(), b.map.begin());
				b.map[nextx][nexty] = 'S'; 
				if(b.map[after_map.x][after_map.y] == 'S')
					b.map[after_map.x][after_map.y] = '.';
					
				b.count = after_map.count+1;
				b.x = nextx; b.y = nexty; b.water = after_map.water;
				visit[nextx][nexty] = 1;
				
				que.push(b);
			}
		}
		 
	}
	
	printf("KAKTUS\n");
}

int main(){
	int x, y;
	block b;
	
	scanf("%d %d", &r, &c);
	getchar();
	
	vector<vector<char> > init_map;
	init_map.assign(r, vector<char>(c, 0));
	visit.assign(r, vector<int>(c, 0));
	
	vector<pair<int, int> > water;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			char tmp;
			scanf("%1c", &tmp);
		
			init_map[i][j] = tmp;
			visit[i][j] = 0;
			
			if(tmp == 'S'){
				x = i;
				y = j;
			}
			else if(tmp == '*'){
				water.push_back(make_pair(i, j));
			}
		}
		getchar();
	}
	
	b.map = init_map; b.count = 0;
	b.x = x; b.y = y; b.water = water;
	visit[x][y] = 1;
	
	que.push(b);
	
	bfs();	
	
}
