#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> arr;
vector<pair<int, int> > pos;
vector<pair<int, int> > edge; // first = ���, second = pos ��ġ 

int find(int target){
	if(target == arr[target])
		return target;
	
	arr[target] = find(arr[target]); 
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
	int ans = 0;
	
	scanf("%d", &n);
	scanf("%d", &m);
	
	init();
	
	for(int i=0;i<m;i++){
		int w, a, b;
		scanf("%d %d %d", &a, &b, &w);
		
		pos.push_back(make_pair(a, b));
		edge.push_back(make_pair(w, i));
	}
	
	sort(edge.begin(), edge.end());
	
	for(int i=0;i<m;i++){
		int w = edge[i].first;
		int a = pos[edge[i].second].first;
		int b = pos[edge[i].second].second;
		
		if(find(a) == find(b)) continue;
		else{
			union_s(a, b);
			ans += w;
		}
	}
	
	printf("%d\n", ans);
}
