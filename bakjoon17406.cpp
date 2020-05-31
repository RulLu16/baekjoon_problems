#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _Cor{
	int r;
	int c;
	int s;
}cor;

cor info[6];
vector <int> list(6);
vector <int> visit(6);
int init[50][50];
int a[50][50]={0,};
int n, m, k;
int min_val=5000;

void rotate(int, int, int);
int calculate();
void initArr();
void dfs(int);


void rotate(int r, int c, int s){ //rotate and calculate min value
	int result=5000;
	int l_x=r-s-1;
	int l_y=c-s-1;
	int r_x=r+s-1;
	int r_y=c+s-1;
	int temp;
	int copy[50][50];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			copy[i][j]=a[i][j];
	}
	
	int k=0;
	for(int i=r_x-l_x;i>0;i-=2){	
		for(int j=0;j<i;j++){
			a[l_x+k][l_y+k+j+1]=copy[l_x+k][l_y+k+j];
		}
		for(int j=0;j<i;j++){
			a[l_x+k+j+1][r_y-k]=copy[l_x+k+j][r_y-k];
		}
		for(int j=0;j<i;j++){
			a[r_x-k][r_y-k-j-1]=copy[r_x-k][r_y-k-j];
		}
		for(int j=0;j<i;j++){
			a[r_x-k-j-1][l_y+k]=copy[r_x-k-j][l_y+k];
		}
		k++;
	}
	
}

int calculate(){
	int temp;
	int result=5000;
	for(int i=0;i<n;i++){
		temp=0;
		for(int j=0;j<m;j++){
			temp+=a[i][j];
		}
		if(temp<result)
			result=temp;
	}
	
	return result;
}

void initArr(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			a[i][j]=init[i][j];
	}
}

void dfs(int depth){
	
	if(depth==k){
		initArr();
		for(int i=0;i<k;i++){
			int idx=list[i];
			rotate(info[idx].r, info[idx].c, info[idx].s);
		}
		
		int temp=calculate();
		if(temp<min_val){
			min_val=temp;
		}
		return;
	}
	
	for(int i=0;i<k;i++){
		if(visit[i]==0){
			visit[i]=1;
			list[depth]=i;
			dfs(depth+1);
			visit[i]=0;
		}
	}
}

int main(){
	int r,s,c;
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			init[i][j]=a[i][j];
		}
	}
	
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&r,&c,&s);
		info[i].r=r;
		info[i].c=c;
		info[i].s=s;
	}
	
	dfs(0);
	
	printf("%d\n",min_val);
}
