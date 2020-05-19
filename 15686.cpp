#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;

void dfs(int);
int calculate_dis();

int result=50*50;
int n,m;
vector <pair<int, int> > chicken;
vector <pair<int, int> > house;
vector <int> list(100);
vector <int> visit(100);

void dfs(int depth, int id){
	if(depth==m){
		int temp=calculate_dis();
		if(result>temp){
			result=temp;
		}
		
		return;
	}
	
	for(int i=0;i<chicken.size();i++){
		if(i<id){
			continue;
		}
		if(visit[i]==0){
			visit[i]=1;
			list[depth]=i;
			dfs(depth+1, i);
			visit[i]=0;
		}
	}
}

int calculate_dis(){
	int min_val=50*50;
	int sum=0;
	int temp;
	
	for(int i=0;i<house.size();i++){
		min_val=50*50;
		for(int j=0;j<m;j++){
			int index=list[j];
			temp=abs(house[i].first- chicken[index].first);
			temp+=abs(house[i].second- chicken[index].second);
			
			if(min_val>temp){
				min_val=temp;
			}
		}
		sum+=min_val;
	}
	
	return sum;	
}

int main(){
	int temp;
	
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&temp);
			
			if(temp==1){
				house.push_back(make_pair(i,j));
			}
			else if(temp==2){
				chicken.push_back(make_pair(i,j));
			}
		}
	}
	
	dfs(0, 0);
	
	printf("%d\n",result);
}
