#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	long long n,k;
	long long temp;
	long long min_val, max_val;
	long long mid;
	long long sum;
	long long result=0;
	vector <long long> lan;
	
	max_val=0;	
	scanf("%lld %lld",&k,&n);
	
	for(long long i=0;i<k;i++){
		scanf("%lld",&temp);
		lan.push_back(temp);
		if(max_val<temp){
			max_val=temp;
		}
	}
	min_val=1;
	mid=(min_val+max_val)/2;
	
	while(min_val<=max_val){
		sum=0;
		for(long long i=0;i<k;i++){
			sum+=lan[i]/mid;
		}
		
		if(sum>=n){
			if(result<mid){
				result=mid;
			}
			min_val=mid+1;
		}
		else{
			max_val=mid-1;
		}
		mid=(min_val+max_val)/2;
	}
	
	printf("%lld\n",result);
}
