#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
	int visit;
	vector <char> back;
}node;

node v[10001]; // number and parent number
queue <int> que;
int a,b;

void init(){
	for(int i=0;i<10001;i++){
		v[i].visit = 0;
		v[i].back.clear();
	}
	que = queue<int>();
	
	return;
}

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

void copyVec(int origin, int modify){
	v[modify].visit = 1;
	for(int i=0;i<v[origin].back.size();i++){
		v[modify].back.push_back(v[origin].back[i]);
	}
}

void printAns(int idx){
	
	for(int i=0;i<v[idx].back.size();i++){
		printf("%c", v[idx].back[i]);
	}
	printf("\n");
	
	return;
}

int calculateQue(int origin){
	int modify;
	char order;
		
	for(int i=0;i<4;i++){
		if(i == 0){
			modify = orderD(origin);
			order = 'D';
		}
		else if(i==1){
			modify = orderS(origin);
			order = 'S';
		}
		else if(i==2){
			modify = orderL(origin);
			order = 'L';
		}
		else{
			modify = orderR(origin);
			order = 'R';
		}
		
		if(v[modify].visit == 0){
			copyVec(origin, modify);
			v[modify].back.push_back(order);
			que.push(modify);
		
			if(modify == b) {
				printAns(modify);
				return 1;	
			}
		}
	}
	
	return 0;
}

void bfs(){	
	v[a].visit = 1;
	que.push(a);
	
	while(!que.empty()){
		int origin = que.front();
		que.pop();
		
		if(calculateQue(origin)) return;		
	}
}

int main(){
	int t;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		init();
		scanf("%d %d", &a, &b);
		bfs();
	}
}
