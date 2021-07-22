#include <stdio.h>
#include <vector>

using namespace std;

long long S = 1048576;
vector<long long> index_tree; 

long long query(long long left, long long right, long long node, long long target){
	if(left == right) return left;
	
	if(index_tree[node*2] >= target){
		return query(left, (left+right)/2, node*2, target);
	}
	else{
		return query((left+right)/2 + 1, right, node*2+1, target - index_tree[node*2]);
	}
}

void update(long long left, long long right, long long node, long long target, long long diff){
	if(left > target || right < target) return; // ¹üÀ§ ¹Û
	
	index_tree[node] += diff;
	if(left != right){
		update(left, (left+right)/2, node*2, target, diff);
		update((left+right)/2 + 1, right, node*2+1, target, diff);
	}
	
	return;	
}

int main(){
	int n;
	
	index_tree.assign(2*S, 0);
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a;
		long long b, c;
		
		scanf("%d", &a);
		
		if(a == 1){
			scanf("%lld", &b);
			
			long long favor = query(1, S, 1, b);			
			printf("%lld\n", favor);
			update(1, S, 1, favor, -1);			
		}
		else if(a == 2){
			scanf("%lld %lld", &b, &c);
			update(1, S, 1, b, c);
		}
	}
}
