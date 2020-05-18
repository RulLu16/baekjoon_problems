#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	int n;
	vector <long long> v;
	long long m,temp;
	long long right=0, left=0, mid=0;
	long long sum=0;
	long long result=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		v.push_back(temp);
		if(right<temp){
			right=temp;
		}
	}
	
	scanf("%lld",&m);
	left=1;
	mid=(right+left)/2;
	
	while(left<=right){
		sum=0;
		for(int i=0;i<n;i++){
			if(mid>v[i]){
				sum+=v[i];
			}
			else{
				sum+=mid;
			}
		}
		
		if(sum<=m){
			if(result<mid){
				result=mid;
			}
			left=mid+1;
		}
		else{
			right=mid-1;
		}
		mid=(right+left)/2;
	}
	printf("%lld\n",result);
	
}
