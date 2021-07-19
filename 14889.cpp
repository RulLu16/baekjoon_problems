#include <stdio.h>
#include <math.h>

int n;
int s[20][20];
int visit[20]={0,};
int start_s=0;
int link_s=0;
int min_val=20000;
int sum=0;

void dfs(int depth, int index){
	int x, y;
	
	if(depth==n/2){
		start_s=0;
		link_s=0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visit[i]==1 && visit[j]==1){
					start_s+=s[i][j];
				}
				if(visit[i]==0 && visit[j]==0){
					link_s+=s[i][j];
				}
			}
		}
		
		if(min_val>abs(start_s-link_s)){
			min_val=abs(start_s-link_s);
		}
		return;
	}
	
	for(int i=index;i<n;i++){
		if(visit[i]==0){
			visit[i]=1;
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&s[i][j]);
			sum+=s[i][j];
		}
	}

	dfs(0, 0);
	
	printf("%d\n",min_val);
}
