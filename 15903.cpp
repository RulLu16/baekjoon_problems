#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
	priority_queue <long long, vector<long long>, greater<long long> > que;
	int n,m;
	long long result=0;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		long long temp;
		scanf("%lld",&temp);
		que.push(temp);
		result+=temp;
	}
	
	for(int i=0;i<m;i++){
		long long first=que.top();
		que.pop();
		long long second=que.top();
		que.pop();
		
		result=result-first-second;
		
		que.push(first+second);
		que.push(first+second);
		
		result=result+2*(first+second);
	}
	
	printf("%lld\n",result);
}
