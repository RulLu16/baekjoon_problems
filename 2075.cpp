#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int n;
	priority_queue <int, vector<int>, greater<int> > que;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			scanf("%d",&temp);
			
			if(i==0){
				que.push(temp);
			}
			else{
				if(que.top()<temp){
					que.pop();
					que.push(temp);
				}
			}
		}
	}
	
	printf("%d\n",que.top());
}
