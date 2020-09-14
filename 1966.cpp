#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

queue <pair<int, int> > que;
priority_queue<int, vector<int>, less<int> > pq;

void init(){
	while(!que.empty()){
		que.pop();
	}
	while(!pq.empty()){
		pq.pop();
	}
}

int printer(int loc){
	int turn=1;
	
	while(!que.empty()){
		if(que.front().second==pq.top()){
			if(que.front().first==loc) return turn;
			
			que.pop();
			pq.pop();
			turn++;
		}
		else{
			que.push(make_pair(que.front().first, que.front().second));
			que.pop();
		}
	}
	
	return -1;
}

int main(){
	int t,n,m;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&m);
		init();
		
		for(int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			
			que.push(make_pair(j,temp));
			pq.push(temp);
		}
		printf("%d\n",printer(m));
	}
}
