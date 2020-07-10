#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100001
int n,k;
int arr[MAX];
int tree[4*MAX];

int query(int,int,int,int,int);
void updateTree(int,int,int,int,int);
void initTree(int,int,int);

int query(int node, int s, int e, int st, int ed){
	if(st<=s && ed>=e){
		return tree[node];
	}
	
	else if(st>e || ed<s)
		return 1;
		
	long long mid=(s+e)/2;
	
	return query(node*2,s,mid,st,ed) * query(node*2+1,mid+1,e,st,ed);
}

void updateTree(int node, int s, int e, int idx, int data){
	if(s==e){
		if(data>0){
			tree[node]=1;
		}
		else if(data<0){
			tree[node]=-1;
		}
		else{
			tree[node]=0;
		}
		return;
	}
	
	int mid=(s+e)/2;
	
	if(idx<=mid)
		updateTree(node*2,s,mid,idx,data);
	else	
		updateTree(node*2+1,mid+1,e,idx,data);
	
	tree[node]=tree[node*2]*tree[node*2+1];
}

void initTree(int node, int s, int e){
	if(s==e){
		if(arr[s]>0){
			tree[node]=1;
		}
		else if(arr[s]<0){
			tree[node]=-1;
			}
		else{
			tree[node]=0;
		}
		return;
	}
	
	int mid=(s+e)/2;
	initTree(node*2,s,mid);
	initTree(node*2+1,mid+1,e);
	
	tree[node]=tree[node*2]*tree[node*2+1];
}

int main(){
	
	int b,c;
	char a;
	char result[MAX];
	int idx=0;
	
	while(scanf("%d %d",&n,&k)!=EOF){
		getchar();
		idx=0;
	
		for(int i=1;i<=n;i++){
			scanf("%d ",&arr[i]);
		}
		
		//getchar();
		initTree(1,1,n);
		
		for(int i=0;i<k;i++){
			/*for(long long i=1;i<=n+3;i++){
				printf("%lld ",tree[i]);
			}*/
			//printf("\n\n");
			scanf("%1c %d %d",&a,&b,&c);
			getchar();
			//printf("%c %lld %lld\n",a,b,c);
		
			if(a=='C'){
				updateTree(1,1,n,b,c);
			}
			else{
				int getResult=query(1,1,n,b,c);
				//printf("%d\n",getResult);
				if(getResult==0){
					result[idx]='0';
					idx++;
				}
				else if(getResult>0){
					result[idx]='+';
					idx++;
				}
				else{
					result[idx]='-';
					idx++;
				}
			}
		}
		
		for(int i=0;i<idx;i++){
			printf("%c",result[i]);
		}
		printf("\n");
	}
}
