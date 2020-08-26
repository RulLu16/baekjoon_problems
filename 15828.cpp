#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	int n;
	queue <int> que;
	
	scanf("%d",&n);
	
	while(1){
		int temp;
		
		scanf("%d",&temp);
		
		if(temp==0){
			que.pop();
		}
		else if(temp==-1){
			if(que.empty()) {
				printf("empty\n");
				break;
			}
			
			while(!que.empty()){
				int num=que.front();
				que.pop();
				printf("%d ",num);
			}
			break;
		}
		else{
			if(que.size()<n)
				que.push(temp);
		}
	}
}
