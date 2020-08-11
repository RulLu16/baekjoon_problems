#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

queue <int> que;

void popQue(){
	if(que.empty()) printf("-1\n");
	else {
		printf("%d\n",que.front());
		que.pop();
	}
}

void sizeQue(){
	printf("%d\n",que.size());
}

void emptyQue(){
	if(que.empty()) printf("1\n");
	else printf("0\n");
}

void frontQue(){
	if(que.empty()) printf("-1\n");
	else printf("%d\n",que.front());
}

void backQue(){
	if(que.empty()) printf("-1\n");
	else printf("%d\n",que.back());
}

int main(){
	int n, temp;
	char order[20];
	
	scanf("%d",&n);
	getchar();
	
	for(int i=0;i<n;i++){
		scanf("%s",order);
		getchar();
		
		if(strcmp(order, "push")==0){
			scanf("%d",&temp);
			que.push(temp);
		}
		else if(strcmp(order, "pop")==0) popQue();
		else if(strcmp(order, "size")==0) sizeQue();
		else if(strcmp(order, "empty")==0) emptyQue();
		else if(strcmp(order, "front")==0) frontQue();
		else if(strcmp(order, "back")==0) backQue();
	}
}


