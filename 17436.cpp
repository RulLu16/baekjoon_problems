#include <stdio.h>
#include <vector>

using namespace std;

long long n,m;
long long ans=0;
long long maxN;
long long minor[10];
int visit[10]={0,};
int num[10];

void dfs(int depth, int pre){
	if(depth==maxN){
		long long temp=1;
		for(int i=0;i<maxN;i++){
			temp*=minor[num[i]];
		}
		
		if(maxN%2==0) ans-=m/temp;
		else ans+=m/temp;
		
		return;
	}
	
	for(int i=0;i<n;i++){
		if(pre>i) continue;
		
		if(visit[i]==0){
			visit[i]=1;
			num[depth]=i;
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int main(){
	
	scanf("%lld %lld",&n,&m);
	
	for(long long i=0;i<n;i++){
		scanf("%lld",&minor[i]);
	}

	for(long long i=1;i<=n;i++){
		maxN=i;
		dfs(0,-1);
	}
	
	printf("%lld\n",ans);
}
