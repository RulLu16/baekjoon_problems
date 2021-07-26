#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int find(int target){
	if(target == arr[target])
		return target;
	
	arr[target] = find(arr[target]); 
	// 이렇게 저장하면 여러번 찾을 필요 없이 바로 최고 조상으로 jump.
	// dp처럼 작동하니까 성능이 매우 올라감 
	return arr[target];
}

void union_s(int a, int b){
	int pa = find(a);
	int pb = find(b);
	
	arr[pb] = pa;
}

void init(){
	arr.assign(n+1, 0);
	
	for(int i=0;i<=n;i++){
		arr[i] = i;
	}
}

int main(){
	int m;
	
	scanf("%d %d", &n, &m);
	
	init();
	
	for(int i=0;i<m;i++){
		int command, a, b;
		
		scanf("%d %d %d", &command, &a, &b);
		
		if(command){
			if(find(a) == find(b)){
				printf("YES\n");
			}
			else printf("NO\n");
		}
		else{
			union_s(a, b);
		}
	}	
}
