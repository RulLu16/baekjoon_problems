#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
vector <int> num;
vector <int> list(8);
vector <int> visit(8);

void dfs(int depth){
	int pre=-1;
	
	if(depth==m){
		for(int i=0;i<m;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<n;i++){
		if(visit[i]==0 && (i==0 || pre!=num[i])){
			visit[i]=1;
			pre=num[i];
			list[depth]=num[i];
			dfs(depth+1);
			visit[i]=0;						
		}
	}
}

int main(){
	int temp;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		num.push_back(temp);
	}
	
	sort(num.begin(),num.end());
	
	dfs(0);
}
