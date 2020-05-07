#include <stdio.h>
#include <stdlib.h>

int n;
int list[9];
int visit[9];

void dfs(int depth){
	if(depth==n){
		for(int i=0;i<n;i++){
			printf("%d ",list[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			list[depth]=i;
			dfs(depth+1);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	
	dfs(0);
}
