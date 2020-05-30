#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n, c;
vector <long long> house;

void binary(){
	long long right=house.back()-house.front();
	long long left=1;
	long long mid=(right+left)/2;
	long long result=0;
	int pre, sum;
	
	while(left<=right){
		pre=house[0];
		sum=1;
		for(int i=1;i<n;i++){
			if(house[i]-pre>=mid){
				sum++;
				pre=house[i];
			}
		}
		
		if(sum<c){
			right=mid-1;
		}
		else{
			left=mid+1;	
			if(result<mid){
				result=mid;
			}	
		}
		mid=(right+left)/2;
		//printf("%d ",mid);
	}
	
	printf("%lld\n",result);
}

int main(){
	long long temp, result;
	scanf("%d %d",&n,&c);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		house.push_back(temp);
	}
	
	sort(house.begin(),house.end());
	
	binary();
}
