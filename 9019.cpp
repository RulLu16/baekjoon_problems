#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int> > v; // number and parent number
int a,b;

int orderD(int origin){
	return (2*origin)%10000;
}

int orderS(int origin){
	if(origin - 1 < 0) return 9999;
	else return origin-1;
}

int orderL(int origin){
	int d1 = origin/1000;
	int d2 = origin%1000/100;
	int d3 = origin%100/10;
	int d4 = origin%10;
	
	return ((d2*10 + d3)*10 + d4)*10 + d1;
}

int orderR(int origin){
	int d1 = origin/1000;
	int d2 = origin%1000/100;
	int d3 = origin%100/10;
	int d4 = origin%10;
	
	return ((d4*10 + d1)*10 + d2)*10 + d3;
}

void pushGraph(int origin, int parent){
	v.push_back(make_pair(orderD(origin), parent));
	v.push_back(make_pair(orderS(origin), parent));
	v.push_back(make_pair(orderL(origin), parent));
	v.push_back(make_pair(orderR(origin), parent));
	
	return;
}

void printAns(int idx){
	vector<int> order;
	
	while(1){
		int parent = v[idx].second;
		order.push_back(idx%4);
		
		if(parent == -1) break;
		
		idx = parent;
	}
	
	for(int i=order.size()-1;i>=0;i--){
		switch(order[i]){
			case 0:
				printf("D");
				break;
			case 1:
				printf("S");
				break;	
			case 2:
				printf("L");
				break;	
			case 3:
				printf("R");
				break;	
		}
	}
	printf("\n");
	
	return;
}

void bfs(){
	int idx = 0;
	pushGraph(a, -1);
	
	while(1){
		int origin = v[idx].first;
		
		if(origin == b){
			printAns(idx);
			return;
		}
		
		pushGraph(origin, idx);
		idx++;		
	}
}

int main(){
	int t;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		v.clear();
		scanf("%d %d", &a, &b);
		bfs();
	}
}
