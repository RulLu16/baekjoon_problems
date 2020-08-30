#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int visit[101]={0,};
int num[101];
vector <int> ans;
int n;
int result=0;
int found=0;

void dfs(int start, int end){
	if(start==num[end]){
		found=1;
		ans.push_back(end);
		return;
	}
	
	if(visit[num[end]]==0){
		visit[num[end]]=1;
		dfs(start,num[end]);
		visit[num[end]]=0;
	}
	
	if(found==1){
		ans.push_back(end);
		visit[num[end]]=1;
		return;
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	
	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			found=0;
			dfs(i,i);
		}
	}
	sort(ans.begin(), ans.end());
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d\n",ans[i]);
	}
}
