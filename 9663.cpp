#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

void dfs(int);
int canAttack(int, int);

int n;
int result=0;
int visit[15]={0,};
vector <pair<int, int> > v(15);

void dfs(int depth){

	if(depth==n){
		result++;
		return;
	}
	
	for(int i=0;i<n;i++){		
		if(canAttack(depth,i)==1){ 
			visit[depth]=i;
			dfs(depth+1);
			visit[depth]=0;
		}
	}
}

int canAttack(int x, int y){
	for(int i=0;i<x;i++){
		if(visit[i]==y) return 0;
		if(abs(visit[i]-y)==abs(i-x)) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	
	dfs(0);	
	
	printf("%d\n",result);
}
