#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*vector <vector<pair<int, int> > > v;
queue <pair<int, int> > que;

void init(){
	v.assign(1000, vector<pair<int, int> >);
	que = queue<pair<int, int> >();
}

int bfs(int country){
	for(int i=0;i<1000;i++){
		if(v[i].size()>0){
			que.push(make_pair(i, 1));
		}
	}
	
	while(!que.empty()){
		int count = 
	}
}*/

int main(){
	int t;
	
	scanf("%d", &t);
	
	for(int i=0;i<t;i++){
		int country, plane;
		
		scanf("%d %d",&country, &plane);
		
		for(int j=0;j<plane;j++){
			int start, end;
			
			scanf("%d %d", &start, &end);
		}
		
		printf("%d\n", country-1);
	}
}
