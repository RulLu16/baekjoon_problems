#include <stdio.h>
#include <stdlib.h>

long long max;
long long min;
long long sum;
long long n,l,r,x;
long long result=0;
int visit[16]={0,};
long long a[16]={0,};
long long list[16]={0,};

void dfs(int depth, int index){
	if(depth>=2){
		min=1000000; max=0; sum=0;
		for(int i=0;i<depth;i++){
			if(list[i]<min){
				min=list[i];
			}
			if(list[i]>max){
				max=list[i];
			}
			sum+=list[i];
		}
		
		if(max-min>=x && sum>=l && sum<=r){
			result++;
		}
	}
	
	for(int i=index;i<n;i++){
		if(visit[i]==0){
			visit[i]=1;
			list[depth]=a[i];
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%lld %lld %lld %lld",&n,&l,&r,&x);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	dfs(0, 0);
	
	printf("%lld\n",result);
}
