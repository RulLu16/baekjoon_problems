#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	int n;
	priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > que;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		
		
		if(x==0){
			if(que.empty()){
				printf("0\n");
			}
			else{
				printf("%d\n",que.top().second);
				que.pop();
			}
		}
		else{
			que.push(make_pair(abs(x), x));
		}
	}
}
