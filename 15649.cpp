#include <stdio.h>
#include <stdlib.h>

int n, m;
int list[10];
int visit[10]={0,};

void dfs(int depth, int pre){
	if(depth==m){
		for(int i=0;i<m;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}	
	
	for(int i=1;i<=n;i++){
		if(i<pre){
			continue;
		}
		if(visit[i]==0){
			//visit[i]=1;
			list[depth]=i;
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d %d",&n, &m);
	
	dfs(0, 1);
}
