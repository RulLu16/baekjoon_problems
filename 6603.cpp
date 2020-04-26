#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

vector <int> v;
int k;
int visit[51]={0,};
int num[51];

void dfs(int depth, int pick){
	int i;
	
	if(depth==6){
		for(i=0;i<6;i++){
			printf("%d ",v[i]);
		}
		printf("\n");
		return;
	}
	
	for(i=0;i<k;i++){
		if(num[i]<pick){
			continue;
		}
		if(visit[num[i]]==0){
			visit[num[i]]=1;
			v.push_back(num[i]);
			dfs(depth+1, num[i]);
			v.pop_back();
			visit[num[i]]=0;
		}
	}
}

int main(){
	int i;
	
	while(1){
		scanf("%d",&k);
		
		if(k==0){
			break;
		}
		
		for(i=0;i<k;i++){
			scanf("%d",&num[i]);
		}
		
		dfs(0, num[0]);	
		printf("\n");	
	}
	
}
