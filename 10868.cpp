#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int n,m;
int arr[MAX];
int tree[4*MAX];

int query(int,int,int,int,int);
void initTree(int,int,int);
int minVal(int,int);

int minVal(int a, int b){
	if(a<b) return a;
	else return b;
}

int query(int node, int s, int e, int st, int ed){
	if(st<=s && ed>=e){
		return tree[node];
	}
	
	else if(st>e || ed<s)
		return 1000000000;
		
	long long mid=(s+e)/2;
	
	return minVal(query(node*2,s,mid,st,ed), query(node*2+1,mid+1,e,st,ed));
}

void initTree(int node, int s, int e){
	if(s==e){
		tree[node]=arr[s];
		return;
	}
	
	int mid=(s+e)/2;
	initTree(node*2,s,mid);
	initTree(node*2+1,mid+1,e);
	
	tree[node]=minVal(tree[node*2],tree[node*2+1]);
}

int main(){
	
	int b,c;
	
	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	initTree(1,1,n);
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&b,&c);
		
		printf("%d\n",query(1,1,n,b,c));
	}
	
}
