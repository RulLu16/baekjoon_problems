#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int n;
	priority_queue<int, vector<int>, greater<int> > que;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		
		if(x==0){
			if(que.empty()){
				printf("0\n");
			}
			else{
				printf("%d\n",que.top());
				que.pop();
			}
		}
		else{
			que.push(x);
		}
	}
}
