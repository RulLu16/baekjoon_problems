#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int n;
	queue <int> que;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		que.push(i+1);
	}
	
	while(1){
		if(que.size()==1) break;
		
		printf("%d ",que.front());
		que.pop();
		
		que.push(que.front());
		que.pop();
	}
	
	printf("%d\n",que.front());
}
