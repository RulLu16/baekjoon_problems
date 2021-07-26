#include <stdio.h>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int find(int target){
	if(target == arr[target])
		return target;
	
	arr[target] = find(arr[target]); 
	// �̷��� �����ϸ� ������ ã�� �ʿ� ���� �ٷ� �ְ� �������� jump.
	// dpó�� �۵��ϴϱ� ������ �ſ� �ö� 
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
