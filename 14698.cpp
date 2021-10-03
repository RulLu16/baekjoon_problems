#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main(){
	int t;
	
	scanf("%d", &t);
	
	for(int i=0;i<t;i++){
		int n;
		priority_queue<long long> que;
		scanf("%d", &n);
		
		for(int j=0;j<n;j++){
			long long c;
			scanf("%lld", &c);
			
			que.push(-c);
		}
		
		long long multiple = 1;
		while(que.size() > 1){
			long long first = que.top(); que.pop();
			long long second = que.top(); que.pop();
			
			long long tmp = first * second;
			que.push(-tmp);
			
			multiple = tmp % 1000000007 * multiple % 1000000007;
		}
		
		printf("%lld\n", multiple);
	}
}
