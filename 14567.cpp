#include <stdio.h>
#include <vector>
#include <queue>
//#include <algorithm>

using namespace std;

int n, m;
int degree[32001]={0,};
int semester[1001];
queue<int> que;
vector<int> node[32001];

void topology(){
	for(int i=1;i<=n;i++){
		if(degree[i]==0){
			que.push(i);
			semester[i]=1;
		}
	}
	
	while(!que.empty()){
		int temp=que.front();
		que.pop();
		
		//printf("%d ",temp);
		
		for(int i=0;i<node[temp].size();i++){
			degree[node[temp][i]]--;
			
			if(degree[node[temp][i]]==0){
				que.push(node[temp][i]);
				semester[node[temp][i]]=semester[temp]+1;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		printf("%d ",semester[i]);
	}
	printf("\n");
}

int main(){
	int first, second;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&first,&second);
		
		node[first].push_back(second);
		degree[second]++;
	}
	
	topology();	
}
