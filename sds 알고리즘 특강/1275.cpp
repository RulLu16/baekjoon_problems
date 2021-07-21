#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> index_tree; 

long long getLeaf(long long n){
	long long m = 2;
	
	while(1){
		if(n <= m) return m;
		
		m *= 2;
	}
}

long long makeIndex(long long left, long long right, long long node){
	if(left != right){
		long long left_v = makeIndex(left, (left+right)/2, node*2);
		long long right_v = makeIndex((left+right)/2 + 1, right, node*2+1);
		
		index_tree[node] = left_v + right_v;
		return index_tree[node];
	}
	else{
		return index_tree[node];
	}
	
}

long long query(long long left, long long right, long long node, long long qleft, long long qright){
	if(left >= qleft && right <= qright)
		return index_tree[node]; // 범위에 들어옴 
	if(left > qright || right < qleft)
		return 0; // 범위 밖
	
	long left_v = query(left, (left+right)/2, node*2, qleft, qright);
	long right_v =  query((left+right)/2 + 1, right, node*2+1, qleft, qright);
	
	return left_v + right_v;
}

long long update(long long left, long long right, long long node, long long target, long long diff){
	if(left > target || right < target) return index_tree[node]; // 범위 밖
	if(left == right) {
		index_tree[node] = diff;
		return index_tree[node];
	}
	
	long left_v = update(left, (left+right)/2, node*2, target, diff);
	long right_v =   update((left+right)/2 + 1, right, node*2+1, target, diff);
	
	index_tree[node] = left_v + right_v;
	return index_tree[node];
}

int main(){
	long long n, q;
	
	scanf("%lld %lld", &n, &q);
	
	long long s = getLeaf(n);
	index_tree.assign(2*s, 0);
	
	for(long long i=0;i<n;i++){
		long long tmp;
		scanf("%lld", &tmp);
		
		index_tree[s+i] = tmp;
	}
	
	makeIndex(1, s, 1);
	
	for(long long i=0;i<q;i++){
		long long x,y;
		long long a,b;
		
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		
		if(x > y)
			printf("%lld\n", query(1, s, 1, y, x));
		else 
			printf("%lld\n", query(1, s, 1, x, y));
			
		update(1, s, 1, a, b);
	}
}
