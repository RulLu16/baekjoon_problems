#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int m,n;
int result=0;
long long d;
vector <int> island;

void binary(){
	int left=1, right=d;
	int pre=0, num=0;
	int mid=(left+right)/2;
	
	while(left<=right){
		num=0;
		pre=0;
		for(int i=0;i<n;i++){
			if(island[i]-pre<mid){
				num++;
			}
			else{
				pre=island[i];
			}
		}
		
		if(d-pre<mid){
			num++;
		}
		
		if(num<=m){
			left=mid+1;
			if(result<mid){
				result=mid;
			}
		}
		else{
			right=mid-1;
		}
		mid=(right+left)/2;
	}
	
	return;
	
}

int main(){
	scanf("%lld %d %d",&d,&n,&m);
	
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		island.push_back(temp);
	}
	
	sort(island.begin(), island.end());
	
	binary();
	
	printf("%d\n",result);
} 
