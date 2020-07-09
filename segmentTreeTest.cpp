#include <stdio.h>

#define MAX 1000001
long long n,m,k;
long long arr[MAX];
long long tree[4*MAX];

long long query(long long,long long,long long,long long,long long);
void updateTree(long long,long long,long long,long long,long long);
void initTree(long long,long long,long long);

long long query(long long node, long long s, long long e, long long st, long long ed){
	if(st<=s && ed>=e){
		return tree[node];
	}
	
	else if(st>e || ed<s)
		return 0;
		
	long long mid=(s+e)/2;
	
	return query(node*2,s,mid,st,ed) + query(node*2+1,mid+1,e,st,ed);
}

void updateTree(long long node, long long s, long long e, long long idx, long long data){
	if(s==e){
		tree[node]=data;
		return;
	}
	
	long long mid=(s+e)/2;
	
	if(idx<=mid)
		updateTree(node*2,s,mid,idx,data);
	else	
		updateTree(node*2+1,mid+1,e,idx,data);
	
	tree[node]=tree[node*2]+tree[node*2+1];
}

void initTree(long long node, long long s, long long e){
	if(s==e){
		tree[node]=arr[s];
		return;
	}
	
	long long mid=(s+e)/2;
	initTree(node*2,s,mid);
	initTree(node*2+1,mid+1,e);
	
	tree[node]=tree[node*2]+tree[node*2+1];
}

int main(){
	
	long long a,b,c;
	
	scanf("%lld %lld %lld",&n,&m,&k);
	
	for(long long i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	initTree(1,1,n);
	
	for(long long i=0;i<m+k;i++){
		/*for(long long i=1;i<=n;i++){
			printf("%lld ",tree[i]);
		}*/
		scanf("%lld %lld %lld",&a,&b,&c);
		
		if(a==1){
			updateTree(1,1,n,b,c);
		}
		else{
			printf("%lld\n",query(1,1,n,b,c));
		}

	}
}
