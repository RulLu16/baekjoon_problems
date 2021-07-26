#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<pair<int, long long> > arr; // first = parent, second = weight

int find(int target){
	if(target == arr[target].first)
		return target;
	
	int parent = find(arr[target].first); 
	arr[target].second += arr[arr[target].first].second; 
	// 거꾸로 타고 올라오면서 갱신해야 하므로 find를 먼저 돌아야함 
	arr[target].first = parent;
	
	return arr[target].first;
}

void union_s(int a, int b, int w){
	int pa = find(a);
	int pb = find(b);
	
	if(pa == pb) return;
	
	arr[pb].first = pa;
	arr[pb].second = arr[a].second - arr[b].second + w;
	// 어차피 다시 find할때 재귀로 갱신되므로, pb의 값만 변경해주면 
	// 위의 find 시 자식들을 전부 갱신해줌.  
}

void init(){
	arr.assign(n+1, make_pair(0, 0));
	
	for(int i=0;i<=n;i++){
		arr[i].first = i;
		arr[i].second = 0;
	}
}

int main(){
	int m;
	
	while(1){
		scanf("%d %d", &n, &m);
		getchar();
		
		if(n == 0 && m == 0) break;
		
		init();
		for(int i=0;i<m;i++){
			char command;
			int a, b, w;
			scanf("%1c", &command);
			
			if(command == '!'){
				scanf("%d %d %d", &a, &b, &w);
				union_s(a, b, w);
			}
			else{
				scanf("%d %d", &a, &b);
				if(find(a) == find(b)){
					printf("%d\n", arr[b].second - arr[a].second);
				}
				else{
					printf("UNKNOWN\n");
				}
			}
			getchar();
		
		}
	}
}
