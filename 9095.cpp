#include <stdio.h>
#include <vector>

int result;

void dfs(int depth, int n){
	if(depth == n){
		result++;
		return;
	}
	
	if(depth > n){
		return;
	}
	
	for(int i=1;i<=3;i++){
		dfs(depth + i, n);
	}
}

int main(){
	int t, n;
	
	scanf("%d", &t);
	
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		
		result = 0;
		dfs(0, n);
		
		printf("%d\n", result);
	}
}
