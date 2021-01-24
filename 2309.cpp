#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> visit;
vector <int> height;
vector <int> result;
int finding = 0;

int getSum(){
	int sum = 0;
	
	for(int i=0;i<7;i++){
		sum += result[i];
	}
	
	return sum;
}

void dfs(int depth){
	if(depth == 7){
		if(getSum() == 100){
			sort(result.begin(), result.end());
			for(int i=0;i<7;i++){
				printf("%d\n", result[i]);
			}
			
			finding = 1;
			return;
		}
	}
	
	for(int i=0;i<9;i++){
		if(finding == 1) break;
		
		if(visit[i] == 0){
			result[depth] = height[i];
			visit[i] = 1;
			dfs(depth+1);
			visit[i] = 0;
		}
	}
	
}

int main(){
	height.assign(9, 0);
	visit.assign(9, 0);
	result.assign(7, 0);
	
	for(int i=0;i<9;i++){
		scanf("%d", &height[i]);
	}
	
	dfs(0);
}
