#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
vector <int> a(12);
vector <int> operand;
vector <int> list(12);
vector <int> visit(12);
long long min_val=1000000000;
long long max_val=-1000000000;

void dfs(int depth){
	int before=-1;
	int op;
	long long result;
	
	if(depth==n-1){
		result=a[0];
		
		for(int i=1;i<n;i++){
			switch(list[i-1]){
				case 0:
					result+=a[i];
					break;
				case 1:
					result-=a[i];
					break;
				case 2:
					result*=a[i];
					break;
				case 3:
					result/=a[i];
					break;						
			}
		}
		if(result>max_val){
			max_val=result;
		}
		if(result<min_val){
			min_val=result;
		}
		return;
	}
	
	for(int i=0;i<n-1;i++){
		if(visit[i]==0 && (i==0 || before!=operand[i])){
			visit[i]=1;
			before=operand[i];
			list[depth]=operand[i];
			dfs(depth+1);
			visit[i]=0;
		}
	}	
}

int main(){
	int temp;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<4;i++){
		scanf("%d",&temp);
		for(int j=0;j<temp;j++){
			operand.push_back(i);
		}
	}
		
	dfs(0);
	
	printf("%d\n%d",max_val, min_val);
}
