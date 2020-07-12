#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001

int n,m;
int arr[MAX];
int minTree[4*MAX];
int maxTree[4*MAX];

int query(int,int,int,int,int, int);
void initTree(int,int, int);
int minVal(int,int);
int maxVal(int, int);

int minVal(int a, int b){
	if(a<b) return a;
	else return b;
}

int maxVal(int a, int b){
	if(a<b) return b;
	else return a;
}

int query(int node, int s, int e, int st, int ed, int cond){
	// 0 means min, 1 means max
	
	if(st<=s && ed>=e){
		if(cond==0) return minTree[node];
		else return maxTree[node];
	}
	
	else if(st>e || ed<s)
		if(cond==0) return 1000000000;
		else return 0;
		
	long long mid=(s+e)/2;
	
	if(cond==0)
		return minVal(query(node*2,s,mid,st,ed,0), query(node*2+1,mid+1,e,st,ed,0));
	else
		return maxVal(query(node*2,s,mid,st,ed,1), query(node*2+1,mid+1,e,st,ed,1));
}

void initTree(int node, int s, int e){
	if(s==e){
		minTree[node]=arr[s];
		maxTree[node]=arr[s];
		return;
	}
	
	int mid=(s+e)/2;
	initTree(node*2,s,mid);
	initTree(node*2+1,mid+1,e);
	
	minTree[node]=minVal(minTree[node*2],minTree[node*2+1]);
	maxTree[node]=maxVal(maxTree[node*2],maxTree[node*2+1]);
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
		
		printf("%d %d\n",query(1,1,n,b,c,0), query(1,1,n,b,c,1));
	}
	
}
