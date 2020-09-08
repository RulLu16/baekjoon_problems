#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long num[101];
long long ans[101];
int visit[101]={0,};
int found=0;

int checkEx(long long x){
	for(int i=0;i<n;i++){
		if(num[i]==x) return i;
	}
	return -1;
}

void dfs(int depth, int x){
	if(depth==n-1){
		for(int i=0;i<n-1;i++){
			printf("%lld ",ans[i]);
		}
		printf("%lld\n",num[x]);
		found=1;
		return;
	}
	
	if(found==1) return;
	
	if(visit[x]==0){
		int next;
		
		if(num[x]%3==0){
			next=checkEx(num[x]/3);
			
			if(next>=0){
				visit[x]=1;
				ans[depth]=num[x];
				dfs(depth+1,next);
				visit[x]=0;
			}
		}
		
		next=checkEx(num[x]*2);
		if(next>=0){
			visit[x]=1;
			ans[depth]=num[x];
			dfs(depth+1,next);
			visit[x]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	
	for(int i=0;i<n;i++){
		dfs(0,i);
		if(found==1) return 0;
	}
}
