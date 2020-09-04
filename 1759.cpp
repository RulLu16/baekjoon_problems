#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int l,c;
vector <int> alpha;
int password[16];
int visit[16]={0,};

void dfs(int depth, int pre){
	if(depth==l){
		int first=0; int second=0;
		int found=0;
		
		for(int i=0;i<l;i++){
			if(alpha[password[i]]==97 || alpha[password[i]]==101 || alpha[password[i]]==105 || alpha[password[i]]==111 || alpha[password[i]]==117){
				first++;
			}
			else second++;
			
			if(first>0 && second>1) {
				found=1;
				break;
			}
		}
		
		if(found==0) return;
		
		for(int i=0;i<l;i++){
			printf("%c",(char)alpha[password[i]]);
		}
		printf("\n");
		return;
	}
	
	for(int i=0;i<c;i++){
		if(pre>i) continue;
		
		if(visit[i]==0){
			visit[i]=1;
			password[depth]=i;
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int main(){
	scanf("%d %d",&l,&c);
	getchar();
	
	for(int i=0;i<c;i++){
		char temp;
		scanf("%c",&temp);
		
		alpha.push_back((int)temp);
		getchar();
	}
	sort(alpha.begin(), alpha.end());
	
	dfs(0,0);
}
